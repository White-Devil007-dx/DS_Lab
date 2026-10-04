/*
 * All-Pairs Shortest Paths using Warshall's (Floyd-Warshall) Algorithm
 *
 * The graph is a weighted directed graph given as an adjacency matrix:
 *   w[i][j] = weight of edge i -> j, or INF (1e7) if no edge exists.
 *
 * Recurrence:
 *   D(k)[i][j] = min( D(k-1)[i][j], D(k-1)[i][k] + D(k-1)[k][j] )
 *
 * Time complexity : O(n^3)
 * Space complexity: O(n^2)
 */
#include <stdio.h>

#define INF 999   /* 1e7 */
#define MAX 100

/* Returns the smaller of two integers */
int min(int a, int b)
{
    return (a < b) ? a : b;
}

/* Computes shortest distances between all pairs of vertices, in place */
void floyd(int n, int d[MAX][MAX])
{
    int i, j, k;

    for (k = 0; k < n; k++)              /* intermediate vertex */
        for (i = 0; i < n; i++)          /* source */
            for (j = 0; j < n; j++)      /* destination */
                if (d[i][k] != INF && d[k][j] != INF)   /* avoid INF + INF overflow/false paths */
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(void)
{
    int n, i, j;
    int d[MAX][MAX];

    printf("Enter the number of vertices (max %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Enter the weight matrix (use %d for INF / no edge):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &d[i][j]);

    floyd(n, d);

    printf("\nAll-pairs shortest distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (d[i][j] >= INF)
                printf("%6s", "INF");
            else
                printf("%6d", d[i][j]);
        }
        printf("\n");
    }

    /* Optional: report negative cycle (a vertex with negative distance to itself) */
    for (i = 0; i < n; i++)
        if (d[i][i] < 0) {
            printf("\nWarning: graph contains a negative-weight cycle.\n");
            break;
        }

    return 0;
}