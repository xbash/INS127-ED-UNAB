struct SNodoLista{
	struct SNodoLista *m_pNext; // Referencia al siguiente
															// elemento de la lista
	int m_iID;
	char m_achNombre[40]; short m_shNacimiento;
	} ;

struct SNodoLista *NuevoElemento(){
	struct SNodoLista *pNodo;
	pNodo = (struct SNodoLista *) malloc(sizeof(struct SNodoLista));
	if(pNodo == NULL)
		return NULL;
	printf("Introduzca id, nombre, y año de nacimiento.\n");

	if(scanf("%d %s %h",&pNodo->m_iID, &pNodo->m_achNombre,&pNodo->m_shNacimiento) != 3){
		free(pNodo);
		return NULL;
	}
	pNodo->m_pNext = NULL;
	return pNodo;
}

void Encola(struct SNodoLista *pOrigen, struct SNodoLista *pNodo){
	struct SNodoLista *it;
	for(it = pOrigen; it->m_pNext; ++it)
 	it->m_pNext = pNodo; // Recorrerla hasta el último elemento
}

int main(){
	struct SNodoLista *pCabeza = NULL;
	pCabeza = NuevoElemento();
	while(1){
		// . . .
		Encola(pCabeza, NuevoElemento());
	}
	return 0;
}


