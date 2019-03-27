#include <stdio.h>
#include <stdlib.h>
#define F 15
void cargar_matriz(int **matriz,int C);
void mostrar_matriz(int **matriz,int C);
void pares(int **matriz,int C);
void vector_pares (int cont);
void mostrar_arreglo(int *par);

int main(){
	srand(time(NULL));
	int i;
	int **matriz;//Declaro Matriz.
	int C = 5+(rand()%(16-5));//declaro C como un numero aleatorio entre 5 y 15.

	//Le asigno memoria a la matriz.
	matriz = (int**)malloc(sizeof(int*)*F);

	//Le otorgo un lugar en la memoria a cada puntero del arreglo.
	for(i=0;i<F;i++){
		//A cada puntero le asigno memoria segun el numero de columnas.
		matriz[i]=(int*)malloc(sizeof(int)*C);
	}

	//Cargar matriz.
	cargar_matriz(matriz,C);

	//Mostrar matriz
	printf("Matriz(%dX%d) de numeros aleatorios:\n\n",F,C);
	mostrar_matriz(matriz,C);

	//Contar cantidad de pares por fila.
	pares(matriz,C);

	return 0;
}

void cargar_matriz(int **matriz,int C){
	int i,j;
	for(i=0;i<F;i++){
		for(j=0;j<C;j++){
			*(*(matriz+i)+j)=100+(rand()%(1000-100));
		}
	}
}

void mostrar_matriz(int **matriz,int C){
	int i,j;
	for(i=0;i<F;i++){
		for(j=0;j<C;j++){
			printf("%d ",*(*(matriz+i)+j));
		}
		printf("\n");
	}

}

void pares(int **matriz,int C){
	int i,j,cont;
	//Creacion del vector de pares de manera dinamica.
	int *par=(int *)malloc(sizeof(int)*F);
	printf("\n\nCantidad de numeros pares que tiene la matriz en cada fila:\n");
	for(i=0;i<F;i++){
		cont = 0;
		for(j=0;j<C;j++){
			if(!(*(*(matriz+i)+j)%2))
				cont++;
		}
		printf(" %d: %d\n",i+1,cont);
		*(par+i)=cont;
	}
	mostrar_arreglo(par);

	return;
}

void mostrar_arreglo(int *par){
	int i;
	printf("\nCantidad de pares de la matriz en forma de arreglo:\n  (");
	for(i=0;i<F;i++){
		printf("%d ",*(par+i));
	}
	printf(")\n\n");
	return;
}
