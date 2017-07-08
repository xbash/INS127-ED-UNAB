#define _XOPEN_SOURCE 300

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

struct entrada_a {
	char *key;
	char *valor;
	struct entrada_a *siguiente;
};

typedef struct entrada_a entrada_b;

struct hashtable_a {
	int size;
	struct entrada_a **table;	
};

typedef struct hashtable_a hashtable_b;


/* Crea un nuevo hashtable. */
hashtable_b *ht_create( int size ) {

	hashtable_b *hashtable = NULL;
	int i;

	if( size < 1 ) return NULL;

	if( ( hashtable = malloc( sizeof( hashtable_b ) ) ) == NULL ) {
		return NULL;
	}

	if( ( hashtable->table = malloc( sizeof( entrada_b * ) * size ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;	
}

int ht_hash( hashtable_b *hashtable, char *key ) {

	unsigned long int hashval;
	int i = 0;


	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		hashval = hashval << 8;
		hashval += key[ i ];
		i++;
	}

	return hashval % hashtable->size;
}

entrada_b *ht_nuevoP( char *key, char *valor ) {
	entrada_b *nuevoP;

	if( ( nuevoP = malloc( sizeof( entrada_b ) ) ) == NULL ) {
		return NULL;
	}

	if( ( nuevoP->key = strdup( key ) ) == NULL ) {
		return NULL;
	}

	if( ( nuevoP->valor = strdup( valor ) ) == NULL ) {
		return NULL;
	}

	nuevoP->siguiente = NULL;

	return nuevoP;
}


void ht_set( hashtable_b *hashtable, char *key, char *valor ) {
	int bin = 0;
	entrada_b *nuevoP = NULL;
	entrada_b *siguiente = NULL;
	entrada_b *ultimo = NULL;

	bin = ht_hash( hashtable, key );

	siguiente = hashtable->table[ bin ];

	while( siguiente != NULL && siguiente->key != NULL && strcmp( key, siguiente->key ) > 0 ) {
		ultimo = siguiente;
		siguiente = siguiente->siguiente;
	}

	if( siguiente != NULL && siguiente->key != NULL && strcmp( key, siguiente->key ) == 0 ) {
		free( siguiente->valor );
		siguiente->valor = strdup( valor );

	} else {
		nuevoP = ht_nuevoP( key, valor );

		if( siguiente == hashtable->table[ bin ] ) {
			nuevoP->siguiente = siguiente;
			hashtable->tabla[ bin ] = nuevoP;

		} else if ( siguiente == NULL ) {
			ultimo->siguiente = nuevoP;	

		} else  {
			nuevoP->siguiente = siguiente;
			ultimo->siguiente = nuevoP;
		}
	}
}

char *ht_get( hashtable_b *hashtable, char *key ) {
	int bin = 0;
	entrada_b *pair;

	bin = ht_hash( hashtable, key );

	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		pair = pair->siguiente;
	}

	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return NULL;

	} else {
		return pair->valor;
	}
	
}


int main( int argc, char **argv ) {

	hashtable_b *hashtable = ht_create( 65536 );

	ht_set( hashtable, "key1", "perro" );
	ht_set( hashtable, "key2", "gato" );
	ht_set( hashtable, "key3", "conejo" );
	ht_set( hashtable, "key4", "raton" );

	printf( "%s\n", ht_get( hashtable, "key1" ) );
	printf( "%s\n", ht_get( hashtable, "key2" ) );
	printf( "%s\n", ht_get( hashtable, "key3" ) );
	printf( "%s\n", ht_get( hashtable, "key4" ) );

	return 0;
}