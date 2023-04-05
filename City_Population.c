#include<stdio.h>
#include <stdlib.h>

int* city_population (int N, int* population, int** road, int Q, int** cities) ;

int main2() {
    int N;
    scanf("%d", &N);
    int i_population;
    int *population = (int *)malloc(sizeof(int)*(N));
    for(i_population = 0; i_population < N; i_population++)
    	scanf("%d", &population[i_population]);
    int i_road, j_road;
    int **road = (int **)malloc((N-1)*sizeof(int *));
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	road[i_road] = (int *)malloc((2)*sizeof(int));
    }
    for(i_road = 0; i_road < N-1; i_road++)
    {
    	for(j_road = 0; j_road < 2; j_road++)
    	{
    		scanf("%d", &road[i_road][j_road]);
    	}
    }
    int Q;
    scanf("%d", &Q);
    int i_cities, j_cities;
    int **cities = (int **)malloc((Q)*sizeof(int *));
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	cities[i_cities] = (int *)malloc((3)*sizeof(int));
    }
    for(i_cities = 0; i_cities < Q; i_cities++)
    {
    	for(j_cities = 0; j_cities < 3; j_cities++)
    	{
    		scanf("%d", &cities[i_cities][j_cities]);
    	}
    }

    int* out_ = city_population(N, population, road, Q, cities);
    printf("%d", out_[0]);
    int i_out_;
    for(i_out_ = 1; i_out_ < Q; i_out_++)
    	printf("\n%d", out_[i_out_]);
}
typedef struct Edge {
    int v;
    struct Edge* next;
} Edge;

void add(Edge** graph, int u, int v) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->v = v;
    e->next = graph[u];
    graph[u] = e;
}

void dfs(int u, int p, int* population, int* depth, int* pNode, int* size, Edge** graph) {
    pNode[u] = p;
    size[u] = 1;
    Edge* e;

    for (e = graph[u]; e != NULL; e = e->next) {
        int v = e->v;
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u, population, depth, pNode, size, graph);
            size[u] += size[v];
        }
    }
}

int lca(int u, int v, int* depth, int* pNode) {
    if (depth[u] < depth[v]) {
        int temp = u;
        u = v;
        v = temp;
    }

    while (depth[u] > depth[v]) {
        u = pNode[u];
    }

    while (u != v) {
        u = pNode[u];
        v = pNode[v];
    }

    return u;
}

int* city_population(int N, int* population, int** road, int Q, int** cities) {
    Edge** graph = (Edge**)malloc(N * sizeof(Edge*));
    int i, q;

    for (i = 0; i < N; i++) {
        graph[i] = NULL;
    }

    for (i = 0; i < N - 1; i++) {
        int u = road[i][0] - 1;
        int v = road[i][1] - 1;
        add(graph, u, v);
        add(graph, v, u);
    }

    int* answers = (int*)malloc(Q * sizeof(int));
    int* depth = (int*)calloc(N, sizeof(int));
    int* pNode = (int*)calloc(N, sizeof(int));
    int* size = (int*)calloc(N, sizeof(int));
    dfs(0, -1, population, depth, pNode, size, graph);

    for (q = 0; q < Q; q++) {
        int U = cities[q][0] - 1;
        int V = cities[q][1] - 1;
        int W = cities[q][2];
        int count = 0;
        int p = lca(U, V, depth, pNode);
        int u = U;

        while (depth[u] > depth[p]) {
            if (population[u] <= W) count++;
            u = pNode[u];
        }

        if (population[p] <= W) count++;
        u = V;

        while (depth[u] > depth[p]) {
            if (population[u] <= W) count++;
            u = pNode[u];
        }

        answers[q] = count;
    }

    for (i = 0; i < N; i++) {
        Edge* e = graph[i];

        while (e != NULL) {
            Edge* next = e->next;
            free(e);
            e = next;
        }
    }
    return answers;
}
