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
 *  *  Function:
 */  
void freeEntryItem(Item item)
{
    return;       /* no mem actually allocated */
}




/*
 *   Function: compareItems
 *    
 *   Description:
 *       Item comparison function to be passed in for List sorting
 */

int  compareItems(Item it1, Item it2)
{
    int i1, i2;

    i1 = *((int *) it1);
    i2 = *((int *) it2);

    if (i1 < i2)
        return -1;
    if (i1 > i2)
        return 1;
    return 0;
}




/*
 *  Function:
 *    bucketSort()
 *
 */
void    bucketSort(int *vtab, LinkedList **btab,
        int bcnt, int vcnt, int vmin, int vmax)
{
    int i, j=0;
    int err, index, counter =0;

    LinkedList *lp; 
    LinkedList *aux;

    for (i=0; i < bcnt; i++)
    {
        lp = initLinkedList();
        btab[i] = lp;
    }
    /* placeholder for algorithm to be implemented */
    printf("\n size of btab : %i\n",bcnt);
    for (i=0; i < vcnt; ++i)
    {
        index = bcnt * (vtab[i])/(vmax + 1);
        btab[index] = insertSortedLinkedList(btab[index],(Item)(&vtab[i]),compareItems, &err);
        if(err==2){
            perror("Allocation Failed");
        }
    
    }



    printf_bucket(btab,bcnt); 
/* fazer disto funcao  para cada lista*/
       while(j<bcnt){
            for(aux = btab[j]; aux != NULL; (aux = getNextNodeLinkedList(aux))){            
            vtab[counter] = *((int *)getItemLinkedList(aux));
            counter++;
            }
        ++j;
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

    printf("Read %d ints, min = %d, max = %d\n", vcnt, vmin, vmax);

    /* allocate memory for int value table   */
    vtab = (int *) malloc( vcnt * sizeof(int) );

    /* second scan: store int values */
    rewind(fp);
    printf("|");
    for (i=0; i < vcnt; i++) {
        fscanf(fp, "%d", &(vtab[i]) );
        printf("%i|",vtab[i]);
    }
    fclose(fp);

    /* allocate bucket table (with at least one bucket) */

    bcnt = 1 + vcnt / NMR; /* Number of buckets */
    btab = (LinkedList **) malloc (bcnt * sizeof(LinkedList *));

    /* call bucket sort, print result  */

    /*
     * vtab - table of int's
     * btab - table of (buckets) pointer to lists  
     * vcnt - Number of readed values (int)
     * bcnt - Number of buckets
     * vmin, vmax - maximum and minimum (int) value readed
     */

    bucketSort(vtab, btab, bcnt, vcnt, vmin, vmax);
    printf(" \n");

    for (i=0; i < vcnt; i++) {
        printf("%d\n", vtab[i]);
    }


    for(i =0; i <bcnt; i++){        
        freeLinkedList(btab[i],freeEntryItem);     
    }

    free(btab);
    free(vtab);
    /* free memory */
    /* ... */

    exit(0);
}
