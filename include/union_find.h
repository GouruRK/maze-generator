#ifndef __INIT_UNION_FIND__
#define __INIT_UNION_FIND__

typedef struct {
    int* table;
    int* rank;
    int size;
} UnionFind;

UnionFind init_uf(int size);

int find(UnionFind* uf, int elem);

void union_set(UnionFind* uf, int a, int b);

void free_uf(UnionFind* uf);

#endif
