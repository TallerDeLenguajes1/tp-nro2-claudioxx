#include <stdio.h>
#include <conio.h>
#define N 4
#define M 5

int main(){
	int f,c;
	int mt[N][M];

	for(f = 0;f<N; f++){
 		for(c = 0;c<M; c++){
			mt[f][c]=c;
		}
	}
//Claudio armando.
	for(f = 0;f<N; f++){
 		for(c = 0;c<M; c++){
			cprintf("%d", mt[f][c]);
		}
		cprintf("\n");
	}
	return 0;
}
