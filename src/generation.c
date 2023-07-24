#include "../include/struct.h"
#include "../include/union_find.h"
#include "../include/generation.h"
#include "../include/graphic.h"

#include <stdlib.h>
#include <MLV/MLV_all.h>

Maze create_maze(int cell_width, int cell_height) {
    Maze maze;
    int dim = cell_width * cell_height;
    maze.uf = init_uf(dim);
    if (!(maze.uf.size)) {
        return maze;
    }
    maze.cell_heigth = cell_height;
    maze.cell_width = cell_width;
    maze.dimensions = dim;
    return maze;
}

int random_n(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

Cell random_cell(Maze* maze) {
    Cell cell;
    cell.x = random_n(0, maze->cell_width - 1);
    cell.y = random_n(0, maze->cell_heigth - 1);
    return cell;
}

Cell copy_cell(Cell cell) {
    Cell new_cell;
    new_cell.x = cell.x;
    new_cell.y = cell.y;
    return new_cell;
}

int is_in_maze(Maze* maze, Cell cell) {
    return (0 <= cell.x && cell.x < maze->cell_width)
           && (0 <= cell.y && cell.y < maze->cell_heigth);

}

Wall random_wall(void) {
    return random_n(0, 3);
}

int convert_2d_coords_to_1d(Maze* maze, Cell cell) {
    return maze->cell_width * cell.x + cell.y;
}

Cell select_neighbour_cell(Cell cell, Wall wall) {
    Cell new_cell = copy_cell(cell);
    switch (wall) {
        case UP:
            new_cell.y--;
            break;
        case DOWN:
            new_cell.y++;
            break;
        case LEFT:
            new_cell.x--;
            break;
        case RIGHT:
            new_cell.x++;
            break;
    }
    return new_cell;
}

void break_wall(Maze* maze, Cell cell, Wall wall) {
    Cell neighbour = select_neighbour_cell(cell, wall);
    if (is_in_maze(maze, neighbour)) {
        int a = convert_2d_coords_to_1d(maze, cell);
        int b = convert_2d_coords_to_1d(maze, neighbour);
        union_set(&(maze->uf), a, b);
    }
}
