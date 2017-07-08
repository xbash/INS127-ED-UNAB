

#define _XOPEN_SOURCE 500 /* Enable certain library functions (strdup) on linux.  See feature_test_macros(7) */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

struct entry_s {
	char *key;
	char *value;
	struct entry_s *next;
};

typedef struct entry_s entry_t;				//se crea las estructuras entry y las estructura que lo alamacena que es la estructura hashtable 

struct hashtable_s {
	int size;
	struct entry_s **table;			//crea un arreglo de entrys llamado table
};

typedef struct hashtable_s hashtable_t;



hashtable_t *ht_create( int size ) {			//funcion que crea un nuevo hashtable 

	hashtable_t *hashtable = NULL;
	int i;

	if( size < 1 ) return NULL;

	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {		
		return NULL;
	}
																					//en caso de que no exista asiganacion de memoria ni para el hashtable o entry

	if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) {	
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;		//llena el arreglo con null´s 
	}

	hashtable->size = size;

	return hashtable;	
}


int ht_hash( hashtable_t *hashtable, char *key ) {


	unsigned long int hashval;
	int i = 0;


	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		hashval = hashval << 8;
		hashval += key[ i ];
		i++;
	}

	return hashval % hashtable->size;
}


entry_t *ht_newpair( char *key, char *value ) //funcionque crea las llaves del hashtable 
{
	entry_t *newpair;

	if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->key = strdup( key ) ) == NULL ) {			//condiciones de control del metodo para evitar usar memoria de mas ( en caso que no sea necesaria o no se pueda ) 
		return NULL;
	}

	if( ( newpair->value = strdup( value ) ) == NULL ) {
		return NULL;
	}

	newpair->next = NULL;

	return newpair;
}


void ht_set( hashtable_t *hashtable, char *key, char *value ) {
	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;

	bin = ht_hash( hashtable, key );

	next = hashtable->table[ bin ];

	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}

	
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {

		free( next->value );
		next->value = strdup( value );

	
	} else {
		newpair = ht_newpair( key, value );

		
		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;
	
	
		} else if ( next == NULL ) {
			last->next = newpair;
	
		
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	}
}


char *ht_get( hashtable_t *hashtable, char *key ) {
	int bin = 0;
	entry_t *pair;

	bin = ht_hash( hashtable, key );

	
	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		pair = pair->next;
	}

	
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return NULL;

	} else {
		return pair->value;
	}
	
}


int main( int argc, char **argv ) {

	hashtable_t *hashtable = ht_create( 65536 );

	ht_set( hashtable, "key1", "hola" );
	ht_set( hashtable, "key2", "sr_tomas" );
	ht_set( hashtable, "key3", "como" );
	ht_set( hashtable, "key4", "esta" );

	printf( "%s\n", ht_get( hashtable, "key1" ) );
	printf( "%s\n", ht_get( hashtable, "key2" ) );
	printf( "%s\n", ht_get( hashtable, "key3" ) );
	printf( "%s\n", ht_get( hashtable, "key4" ) );

	return 0;
}
