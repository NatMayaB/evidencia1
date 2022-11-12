#include<stdio.h>
#include<stdlib.h>

struct nodo {
int info;
int prioridad;
struct nodo *siguiente; 
}; 

struct nodo *inicio = NULL; 

void insertar(int x, int y) {

struct nodo *p;
struct nodo *nuevonodo;
nuevonodo = malloc(sizeof(struct nodo)); 
struct nodo *anterior;
anterior=malloc(sizeof(struct nodo));

nuevonodo -> info = x;// almacena la información en nuevo nodo
nuevonodo -> prioridad = y;// almacena la prioridad del nodo
nuevonodo -> siguiente = NULL; // almacena dirección del siguiente nodo

// Comprueba si la cola esta vacía, si esta vacía asigna "nuevonodo" como primer nodo
if(inicio == NULL)
inicio = nuevonodo;
//Comprueba si la prioridad del nodo es menor que la del primer nodo
  else if(nuevonodo -> prioridad > inicio -> prioridad) {
    anterior = inicio;// almacena nodo de incio en un nodo temporal
    p = inicio;
// itera hasta que encuentra el nodo con menor prioridad
    while(p != NULL && p -> prioridad <= nuevonodo -> prioridad) {
      anterior = p;
      p = p -> siguiente;
    }
    nuevonodo -> siguiente = p;
    anterior -> siguiente = nuevonodo;
  }
// si el nodo entrante tiene la prioridad más alta, pasa como nodo de inicio 
  else {
    nuevonodo -> siguiente = inicio;
    inicio = nuevonodo;
  }
} 

void mostrarCola() {
struct nodo *p;
// Checa si la cola esta vacía
  if(inicio == NULL)
    printf("La cola esta vacia\n");
// itera sobre todos los nodos e imprime la información
  else {
    p= inicio;
    printf("Los elementos de la cola son:\n\n");
    printf("Prioridad | Valor\n");
    while(p!=NULL) {
      printf("   %d         %d\n", p -> prioridad, p -> info);
      p = p -> siguiente;
    }
  }
} 


int main() {
  struct nodo *p;
  int x;
  int opcion;
  int y;
  //menú
  while(1) {
    printf("\n\n1.Insertar valor y prioridad\n2.Mostrar cola\n");
    scanf("%d",&opcion);
    switch(opcion) {
      case 1:
      printf("\n\nInsertar valor: ");
      scanf("%d", &x);
      printf("Insertar prioridad: ");
      scanf("%d", &y);
      insertar(x, y);
        break;
      case 2:
        mostrarCola();
        break;
    }
  }
}
