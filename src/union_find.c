#include <stdlib.h>

#include "../include/union_find.h"

// Thanks to https://coderscat.com/using-disjoint-set-union-find-to-create-maze/
// and its implementation of union find optimizations

UnionFind init_uf(int size) {
    UnionFind uf;
    uf.rank = (int*)calloc(size, sizeof(int));
    if (!(uf.rank)) {
        uf.table = NULL;
        uf.size = 0;
        return uf;
    }
    uf.table = (int*)malloc(sizeof(int) * size);
    if (uf.table) {
        uf.size = size;
        for (int i = 0; i < size; i++) {
            uf.table[i] = i;
        } 
    } else {
        uf.size = 0;
    }
    return uf;
}

int find(UnionFind* uf, int elem) {
    if (elem != uf->table[elem]) {
        uf->table[elem] = find(uf, uf->table[elem]);
    }
    return uf->table[elem];
}

void union_set(UnionFind* uf, int a, int b) {
    if (a == b) return;
    int x = find(uf, a);
    int y = find(uf, b);

    if (uf->rank[x] > uf->rank[y]) {
        uf->table[y] = x;
    } else {
        uf->table[x] = y;
        if (uf->rank[x] == uf->rank[y]) {
            uf->rank[y]++;
        }
    }
}

void free_uf(UnionFind* uf) {
    free(uf->rank);
    free(uf->table);
}
