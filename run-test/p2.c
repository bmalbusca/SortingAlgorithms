/*  AED 2018-2019, sem.2
 *  Outline main function for LabAval Problem 2
 *  Last change abl 2019.03.18
 */
#include <stdio.h>
#include <stdlib.h>
/* #include <malloc.h> */
#include <math.h>

typedef struct _matriz {
	int linhas;
	int colunas;
	int **matriz;
} Matriz;

/*
void funcao(Matriz *M, int *a1, int *a2)
{
} */


int main(int argc, char *argv[])
{
	int i, j;
	/*    int out1, out2; */
	Matriz MAT;
	FILE *fpin;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(1);
	}

	/* open file and read dimensions */
	fpin = fopen(argv[1], "r");
	fscanf(fpin, "%d %d", &MAT.linhas, &MAT.colunas);

	/* allocate memory, set structure, read in array       */
	MAT.matriz = (int **) calloc( (MAT.linhas),sizeof(int*) );
	/* MAT.matriz = (int *) malloc((MAT.colunas)*sizeof(int));
	   ...        ...       ...       ...        ...        */


	for (i = 0; i < MAT.linhas; i++) {
		MAT.matriz[i] = (int *)calloc((MAT.colunas),sizeof(int));
		for (j = 0; j < MAT.colunas; j++) {
			fscanf(fpin, "%d", &MAT.matriz[i][j]);
		}
	}
	/* apply function and print results                    */
	/*funcao(&MAT, &out1, &out2);

	  printf("%d %d \n", out1, out2);
	  */
	for(i =0; i < MAT.linhas; ++i){
		free(MAT.matriz[i]);
	}

	/* free memory */
	free(MAT.matriz);
	fclose(fpin);
	
	/* ... */

	exit(0);
}
