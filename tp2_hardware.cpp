#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int velocidad; //1+rand()%(4-3);
	int anio; //2000+rand()%(2018-2000);
	int cantidad; //1+rand()%(5-1);
	char *tipo_cpu;
	}compu;

void cargar_computadoras (compu *pcs,int cantpc,char tipos[6][10]);
char* rand_cpu(char tipos [6][10]);
//void mostrar_pc2 (compu *pcs,int canpc); otra forma de hacerlo.
void mostrar_pc (compu pc,int i);
void pc_masvieja (compu *pcs,int cantpc);
void pc_masrapida (compu *pcs,int cantpc);

int main(){
	srand(time(NULL));
	int cantpc,i;
	compu *pcs;
	//char **tipos=(char **)malloc(sizeof(char*)*10); ESTARIA BIEN??
	char tipos[6][10]={"Intel","AMD","Celeron","Athlon","Core","Pentium"};

	printf("CANTIDAD DE COMPUTADORAS A INGRESAR: ");
	scanf("%d",&cantpc);

	//Asigno memoria al arreglo de estructuras.
	pcs = (compu *)malloc(sizeof(compu)*cantpc);

	cargar_computadoras(pcs,cantpc,tipos);

	printf("\nCOMPUTADORAS:");
	for(i=0;i<cantpc;i++){
		mostrar_pc(*(pcs+i),i);
	}

	pc_masvieja(pcs,cantpc);

	pc_masrapida(pcs,cantpc);

	return 0;
}

void cargar_computadoras (compu *pcs,int cantpc,char tipos[6][10]){
	int i;
	//Recorro vector de estructuras y voy cargando.
	for(i=0;i<cantpc;i++){
		(*(pcs+i)).velocidad = 1+rand()%(4-1);
		(*(pcs+i)).anio = 2000+rand()%(2018-2000);
		(*(pcs+i)).cantidad = 1+rand()%(5-1);
		(*(pcs+i)).tipo_cpu = rand_cpu(tipos);
	}

	return;
}

char* rand_cpu(char tipos [6][10]){
	char *cpu = (char*)malloc(sizeof(char)*10); 
	int i = rand()%6;
	cpu = tipos[i];
	return cpu;
}

/*void mostrar_pc2 (compu *pcs,int cantpc){
	int i;
	compu pc;
	printf("\nLAS COMPUTADORAS INGRESADAS SON:\n\n");
	for(i=0;i<cantpc;i++){
		pc = *(pcs+i);
		printf(" %d:\n  Procesador: %s\n  Cantidad de nucleos: %d\n  Frecuencia del procesador: %dGHz\n  Fecha de lanzamiento: %d\n",i+1,pc.tipo_cpu,pc.cantidad,pc.velocidad,pc.anio);
	}

	return;
}*/

void mostrar_pc (compu pc,int i){
	printf("\n %d:\n  Procesador: %s\n  Cantidad de nucleos: %d\n  Frecuencia del procesador: %dGHz\n  Fecha de lanzamiento: %d\n",i+1,pc.tipo_cpu,pc.cantidad,pc.velocidad,pc.anio);
	return;
}

void pc_masvieja (compu *pcs,int cantpc){
	int i,subi=0,anio;
	compu pc;
	anio = pcs[0].anio;
	for(i=1;i<cantpc;i++){
			if(anio>pcs[i].anio){
				subi=i;
				anio = pcs[i].anio;
			}
	}
	pc = *(pcs+subi);
	printf("\n\nCOMPUTADORA MAS VIEJA:\n Procesador: %s\n Cantidad de nucleos: %d\n Frecuencia del procesador: %dGHz\n Fecha de lanzamiento: %d\n",pc.tipo_cpu,pc.cantidad,pc.velocidad,pc.anio);
	return;
}

void pc_masrapida (compu *pcs,int cantpc){
	int i,subi=0,rapidez;
	compu pc;
	rapidez = pcs[0].velocidad;
	for(i=1;i<cantpc;i++){
			if(rapidez<pcs[i].velocidad){
				subi=i;
				rapidez = pcs[i].velocidad;
			}
	}
	pc = *(pcs+subi);
	printf("\n\nCOMPUTADORA MAS RAPIDA:\n Procesador: %s\n Cantidad de nucleos: %d\n Frecuencia del procesador: %dGHz\n Fecha de lanzamiento: %d\n",pc.tipo_cpu,pc.cantidad,pc.velocidad,pc.anio);
	return;
}