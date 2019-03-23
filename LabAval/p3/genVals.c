/******************************************************************************
 * NAME
 *      genVals.c
 *  Last change abl 2019.03.18
 *
 * DESCRIPTION
 * - generate a list of int values (one per line)
 *  hacked from LMS
 *     genPairs - generate pairs for Sedgewick's Connectivity Problem
 *
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h> // For random(), RAND_MAX


/*
 *
 * Assumes 0 <= max <= RAND_MAX
 * Returns in the closed interval [0, max]
 */
long random_at_most(long max) {
    unsigned long
    /* max <= RAND_MAX < ULONG_MAX, so this is okay.  */
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

    long x, y;
    do {
        x = random();
    }
    // This is carefully written not to overflow
    while (num_rand - defect <= (unsigned long)x);

    // Truncated division is intentional
    y = x/bin_size;
    return x/bin_size;
}



/*
 *  main
 */

int main(int argc, char *argv[]) {
    int i, NP;
    long N, p, q;

    if (argc < 3) {
        fprintf(stderr, "usage: %s max_val num_vals\n", argv[0]);
        exit(0);
    } else {
        N = (long) atoi(argv[1]);
        NP = atoi(argv[2]);
    }
    /* check N for boundaries */

/* NO HEADER
  fprintf(stdout, "%d\n", N);
*/

    /* set seed for repeatable results */
    srandom(0);
    q = 0;
    for (i=0; i < NP; i++) {
        p = random_at_most(N-1);
        fprintf(stdout, "%lu\n", p);
/*
    q = random_at_most(N-1);
    fprintf(stdout, "%lu %lu\n", p, q);
*/
    }
    fflush(stdout);
}
