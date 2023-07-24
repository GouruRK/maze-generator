#ifndef __INIT_GENERATION__
#define __INIT_GENERATION__

#include "union_find.h"
#include "struct.h"

typedef struct _cell {
    int x;
    int y;
} Cell;

typedef struct _maze {
    UnionFind uf;
    int cell_width;
    int cell_heigth;
    int dimensions;
} Maze;

Maze create_maze(int cell_width, int cell_height);

int random_n(int min, int max);

Cell random_cell(Maze* maze);

Cell copy_cell(Cell cell);

int is_in_maze(Maze* maze, Cell cell);

Wall random_wall(void);

int convert_2d_coords_to_1d(Maze* maze, Cell cell);

Cell select_neighbour_cell(Cell cell, Wall wall);

void break_wall(Maze* maze, Cell cell, Wall wall);

#endif
