/*  AED 2018-2019, sem.2
 *  Outline main function for LabAval Problem 3
 *  Last change abl 2019.03.19
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <limits.h>

#include"LinkedList.h"


/* define ratio of data items, N, to buckets, M, according to taste */
#define NMR 4

/*
 *  Function:
 *    bucketSort()
 *
 */
void    bucketSort(int *vtab, LinkedList **btab,
                    int bcnt, int vcnt, int vmin, int vmax)
{
    int i;
    LinkedList *lp;

    for (i=0; i < bcnt; i++)
    {
        lp = initLinkedList();
        btab[i] = lp;
    }
    /* placeholder for algorithm to be implemented */
    for (i=0; i < vcnt; i++)
    {
        vtab[i] = 0;
    }
}


 /*
 *  Function:
 *    main()
 *
 */
int main(int argc, char *argv[])
{
    int ibuf, i;
    int *vtab;              /* data values table   */
    int vcnt = 0;
    int vmin = INT_MAX;
    int vmax = INT_MIN;     /* not a bug */
    LinkedList **btab;
    int  bcnt;              /* size of bucket table */
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    fp = fopen ( argv[1], "r" );
    if ( fp == NULL ) {
        fprintf ( stderr, "ERROR: cannot open file '%s'\n", argv[1]);
        exit ( 1 );
    }

    /* first scan: count int values, find min and max */
    while(fscanf(fp, "%d", &ibuf) == 1) {
        vcnt++;
        if (ibuf > vmax)    vmax = ibuf;
        if (ibuf < vmin)    vmin = ibuf;
    }
/*  printf("Read %d ints, min = %d, max = %d\n", vcnt, vmin, vmax);     */

    /* allocate memory for int value table   */
    vtab = (int *) malloc( vcnt * sizeof(int) );
    
    /* second scan: store int values */
    rewind(fp);
    for (i=0; i < vcnt; i++) {
        fscanf(fp, "%d", &(vtab[i]) );
    }
    fclose(fp);

    /* allocate bucket table (with at least one bucket) */

    bcnt = 1 + vcnt / NMR;
    btab = (LinkedList **) malloc (bcnt * sizeof(LinkedList *));
    
    /* call bucket sort, print result  */

    bucketSort(vtab, btab, bcnt, vcnt, vmin, vmax);

    for (i=0; i < vcnt; i++) {
        printf("%d\n", vtab[i]);
    }

    /* free memory */
    /* ... */

    exit(0);
}
