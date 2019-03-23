/*  AED 2018-2019, sem.2
 *  Outline main function for LabAval Problem 2
 *  Last change abl 2019.03.18
 */
#include <stdio.h>
#include <stdlib.h>
/* #include <malloc.h> */
#include <math.h>

#define MAX(a, b) ((a)>(b)? (a) : (b))



typedef struct _matriz {
	int linhas;
	int colunas;
	int **matriz;
} Matriz;



int sum_submatrix(int **matriz, int x_origin, int y_origin ){

	return (int) ((matriz[y_origin][x_origin]) +  (matriz[y_origin][x_origin+1]) +  (matriz[y_origin-1][x_origin+1]) +  (matriz[y_origin-1][x_origin]));  

}


int sum_elements(Matriz *M, int orig_linhas, int orig_colunas){
	int ** matriz_ = M->matriz;
	int i, j, sum =0;	
	for(i = orig_linhas; i< M->linhas; ++i){
		for(j = orig_colunas; j< M->colunas;++j){
			sum += matriz_[i][j];

		}
	}
	return sum;
}

void funcao(Matriz *M, int *a1, int *a2){

	/* Number of Sub-Matrix's inside of original matrix */
	int n_submatrixx =0,n_submatrixy=0;
	/*  Size of  MxM Matrix */  
	int size_submatrix = 2; 

	int i,j;

	n_submatrixx = (int)((M->colunas)/size_submatrix);
	n_submatrixy = (int)((M->linhas)/size_submatrix);


	if((M->colunas < 2) || (M->linhas <2)){
		/* origin point */
		*a1 = sum_elements(M, 0, 0);
	}
	else{
		/*  Matrix with a surprising  Width */
		if(M->colunas > M->linhas){

			for(i = 0; i< size_submatrix * n_submatrixx; i+=2){
				for(j =0; j<size_submatrix * n_submatrixy; j+=2){

					(*a1) += sum_submatrix(M->matriz,i,j); 

				}
			}
			if( (( size_submatrix * n_submatrixx ) - (M->colunas))!= 0){
				(*a1) += sum_elements(M,0,(M->colunas)-1);}
			if( ((size_submatrix * n_submatrixy) - (M->linhas)) != 0){
				(*a1) += sum_elements(M,(M->linhas)-1,0);}

		}
		
		/* Matrix w/ a surprising Length */
		
		else{

			for(i = 0; i< size_submatrix * n_submatrixy; i+=2){
				for(j =0; j<size_submatrix * n_submatrixx; j+=2){

					(*a1) += sum_submatrix(M->matriz,i,j); 

				}
			}
			if( (( size_submatrix * n_submatrixx ) - (M->colunas))!= 0){
				(*a1) += sum_elements(M,0,(M->colunas)-1);}
			if( ((size_submatrix * n_submatrixy) - (M->linhas)) != 0){
				(*a1) += sum_elements(M,(M->linhas)-1,0);}


		}


	}



(*a2) = 0;

}


int main(int argc, char *argv[])
{
	int i, j;
	int out1, out2; 
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

	funcao(&MAT, &out1, &out2);
	printf("%d %d \n", out1, out2);

	for(i =0; i < MAT.linhas; ++i){
		free(MAT.matriz[i]);
	}

	/* free memory */
	free(MAT.matriz);
	fclose(fpin);

	/* ... */

	exit(0);
}
