#include <MLV/MLV_all.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#include "include/graphic.h"
#include "include/generation.h"
#include "include/union_find.h"

#define CELL_WIDTH 20
#define CELL_HEIGHT 20
#define CELL_SIZE 30

int main(void) {
    srand(time(NULL));
    
    int stop = 0;
    MLV_execute_at_exit(exit_function, &stop);
    
    MLV_create_window("Maze", "", CELL_WIDTH * CELL_SIZE, CELL_HEIGHT * CELL_SIZE);
    display_default_grid(CELL_WIDTH, CELL_HEIGHT, CELL_SIZE);
    MLV_update_window();
    
    Maze maze = create_maze(CELL_WIDTH, CELL_HEIGHT);
    Cell cell;
    Wall wall;

    bool is_done = false;
    while (!stop) {
        if (is_done) {
            continue;
        }
        
        cell = random_cell(&maze);
        wall = random_wall();
        break_wall(&maze, cell, wall);
        remove_wall(cell.x, cell.y, CELL_SIZE, wall);

        MLV_update_window();
        MLV_wait_milliseconds(10);
        
        is_done = find(&(maze.uf), 0) == find(&(maze.uf), maze.cell_heigth * maze.cell_width - 1);
        if (is_done) {
            printf("Done\n");
        }
    }
    MLV_free_window();
    free_uf(&(maze.uf));
}