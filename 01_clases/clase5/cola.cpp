#include <cstdlib>
#include <iostream>
#define MAX 10
using namespace std;
typedef int Base;
typedef Base Vector[MAX];

// Interfaz
class Stack
{   private:
       Vector v;
       int top;
    public:
       Stack();
       bool Empty();
       void Push(Base);
       Base Pop();
};
// Implementacion
Stack::Stack()
{	cout << "Creando stack" << endl << endl;
 	top = -1;
}
bool Stack::Empty()
{	return top == -1; }
void Stack::Push(Base e)
{      v[++top] = e; }
Base Stack::Pop()
{    return v[top--]; }
// Despliegue de contenido


// Interfaz
class Cola
{  private:
       Vector v;
       int front;
       int rear;
    public:
       Cola();
       bool Vacia();
       void Agregar(Base);
       Base Extraer();
};
// Implementacion
Cola::Cola()
{  cout << "Creando cola" << endl << endl;
    front = 0;
    rear = 0;
}
bool Cola::Vacia()
{  return front == rear; };
void Cola::Agregar(Base e)
{  rear = (rear+1)%MAX;
    v[rear] = e;
}
Base Cola::Extraer()
{  front = (front+1)%MAX;
    return v[front];
}
// Despliegue de contenido
void Imprime(Cola &C)
{  int e;
    Cola Q;
    while(!C.Vacia())
    {  e = C.Extraer();
        cout << "Elemento " << e << endl;
        Q.Agregar(e);
    }
    while(!Q.Vacia())
        C.Agregar(Q.Extraer());
}
// Suma iterativa
int SumaIter(Cola &C)
{  int e, t = 0;
    Cola Q;
    while(!C.Vacia())
    {  e = C.Extraer();
        t = t + e;
        Q.Agregar(e);
    }
    while(!Q.Vacia())
        C.Agregar(Q.Extraer());
    return t;
}
// Funcion main

void invertir(Cola &C)
{
     Stack S;
     while(! C.Vacia())
        S.Push(C.Extraer());
        
     while(! S.Empty())
        C.Agregar(S.Pop());       
}

int main(int argc, char *argv[])
{  Cola Q;
    int i, k=1;
    for (i=1;i<=5;i++)
    {  Q.Agregar(k*(i+2));
        k = - k;
    }
    Imprime(Q);
    cout << "Suma elementos " << SumaIter(Q) << endl;

    invertir(Q);
    cout << "Cola Invertida " << endl;
    Imprime(Q);

    system("PAUSE");
    return EXIT_SUCCESS;
}
