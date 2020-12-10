#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fill_array(int *v, int dim);


void get_array(int *v, int dim);


int main (void) {

    srand(time(NULL));          /// random seed for rand() function

    int i = 0, j = 0, k = 0, delete = 0;
    int n = 20;    /// you can decide the size n
    int *array;

    /// START CREATING THE ARRAY WITH DYNAMIC MEMORY ALLOCATION
    if ((array = (int *)calloc(n, sizeof(int *))) == NULL) {
        puts("Memory allocation error...");
        return(EXIT_FAILURE);
    }

    /// Fill the array with random numbers between 0 and 9
    fill_array(array, n);

    /// Print the array 
    puts("FIRST");
    get_array(array, n);

    /// START ALGORITHM

    for (i = 0; i < n - delete; i++) {
        for (j = (n - 1) - delete; j > i; j--) {
            if (array[i] == array[j]) {
                if (j == (n - 1) - delete) {
                    delete++;
                }
                else {
                    for (k = j; k < (n - 1) - delete; k++) {
                        array[k] = array[k + 1];
                    }
                    delete++;
                }
            }
        }
    }
    n -= delete;

    /// END ALGORITHM
    
    /// THE ARRAY RESIZES ITS MEMORY
    array = realloc(array, n * sizeof(int *));

    printf("Iteration of i: %d\n\n", i);
    
    /// Print a new array without duplicates
    puts("THEN");
    get_array(array, n);

    return EXIT_SUCCESS;
}

/** Fill the array with random numbers between 0 and 9,
 *  so the chances of a duplicate coming out are greater
 * 
 *  *v  : array
 *  dim : size of the array
 */
void fill_array(int *v, int dim) {
    for (int i = 0; i < dim; i++) {
        v[i] = rand() % 10;
    }
}

/** Print the array
 * 
 *  *v  : array
 *  dim : size of the array
 */
void get_array(int *v, int dim) {
    printf("array: [ ");
    for (int i = 0; i < dim; i++) {
        printf("%d ", v[i]);
    }
    puts("]\n");
}