#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 4
#define M 5

int main(){
	int f,c=0,cont=0;
	int mt[N][M];
	int * punt;
	srand (time(NULL));// ****¿¿¿ES NECESARIO???****.. si, sino el primer numero aleatorio siempre es el mismo.

	punt=&mt[0][0];
	
	for(f = 0;f<N*M; f++){
			c++;
			*(punt+f)=1+(rand()%(10-1));
	}


	for(f = 0;f<N; f++){
 		for(c = 0;c<M; c++){
			cprintf("%d", *(punt+cont));
			cont++;
		}
		cprintf("\n");
	}

	return 0;
}
