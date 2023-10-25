#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* Date: 2018-05-21
* Authors: Guberovic E., Matosevic L.
*
* Scale-Array algorithm for scaling large arrays to smaller ones while keeping the normal distribution of elements in resulting array.
* 
* Parameters:
* N - Number of elements in the initial array
* K - Number of elements in the scaled array
* V - The size of each normal group
* G - Number of normal groups (size of V)
* J - Number of singular groups (size is one)
* S - Steps after which to include singular group element into the normal group
*/
int main() {
    int N, K, V, G, J, S, i, j, k, g, middle;
    double *elements, *scaled, *group;

    printf("Input size of initial array (N): ");
    scanf_s("%d", &N);

    elements = (double *) malloc(N * sizeof(double));

    for (i = 0; i < N; i++) {
        printf("\nInput element %d/%d: ", i + 1, N);
        scanf_s("%lf", elements + i);
    }

    printf("\nInput size of scaled array (K): ");
    scanf_s("%d", &K);

    if (K >= N) {
        printf("\nThe size of a scaled array must be smaller than the size of a initial array!\n\n");
        system("pause");
        return 1;
    }

    scaled = (double *) malloc(K * sizeof(double));

    V = ceil((double) N / K);
    G = floor((double) N / V);
    J = K - G;
    if (J != 0) {
        S = floor((double) G / J);
    } else {
        S = 0;
    }

    printf("\nParameters:\nN=%d\nK=%d\nV=%d\nG=%d\nJ=%d\nS=%d\n", N, K, V, G, J, S);

    group = (double *) malloc(V * sizeof(double));
    for (i = j = k = g = 0; i < N; i++) {
        *(group + j) = *(elements + i);
        j++;
        if (j == V || (i + 1) == N) {
            g++;
            middle = (int) ceil((double) j / 2) - 1;
            if (S != 0 && g != 0 && g % S == 0 && middle > 0) {
                *(scaled + k) = *(group + (middle - 1));
                k++;
            }
            *(scaled + k) = *(group + middle);
            k++;
            j = 0;
        }
    }

    free(group);

    printf("\nScaled array elements:\n");
    for (i = 0; i < K; i++) {
        printf("%f ", *(scaled + i));
    }

    free(scaled);

    printf("\n\n");
    system("pause");
    return 0;
}