#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int comparator(const void *a, const void *b)
{
    int *p1 = (int *)a;
    int *p2 = (int *)b;
    return p1[2] - p2[2]; // compare weights
}

// Initialize parent and rank
void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find with path compression
int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;

    return parent[component] = findParent(parent, parent[component]);
}

// Union by rank
void unionSet(int u, int v, int parent[], int rank[])
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal Algorithm
int kruskalAlgo(int n, int edge[n][3])
{
    // Sort edges based on weight
    qsort(edge, n, sizeof(edge[0]), comparator);

    int parent[n];
    int rank[n];

    makeSet(parent, rank, n);

    int minCost = 0;

    for (int i = 0; i < n; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        int v1 = findParent(parent, u);
        int v2 = findParent(parent, v);

        if (v1 != v2) {
            unionSet(v1, v2, parent, rank);
            minCost += wt;
        }
    }

    return minCost;
}

// Driver code
int main()
{
    int edge[5][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    printf("Minimum Cost: %d\n", kruskalAlgo(5, edge));

    return 0;
}
