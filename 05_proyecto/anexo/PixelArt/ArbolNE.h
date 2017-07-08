typedef struct QNodo{
    int color;
    struct Qnodo* hijos;
    int x;
    int y;
    int l;
} QNodo;

QNodo* crearCuadrante(int color, int x, int y, int l){
    QNodo* aux = (QNodo*) malloc(sizeof(QNodo));
    aux->color = color;
    aux->x = x;
    aux->y = y;
    aux->l = l;
    aux->hijos = NULL;
    
    return aux;
}

void initHijos(QNodo* n){
    n->hijos = (QNodo*) malloc(sizeof(QNodo) * 4);
}