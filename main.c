#include <MLV/MLV_all.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "include/graphic.h"
#include "include/generation.h"
#include "include/union_find.h"

#define CELL_WIDTH 20
#define CELL_HEIGHT 20
#define CELL_SIZE 30

int main(void) {
    srand(time(NULL));
    MLV_create_window("Maze", "", CELL_WIDTH * CELL_SIZE, CELL_HEIGHT * CELL_SIZE);
    display_default_grid(CELL_WIDTH, CELL_HEIGHT, CELL_SIZE);
    MLV_update_window();
    Maze maze = create_maze(CELL_WIDTH, CELL_HEIGHT);
    build_maze(&maze, CELL_SIZE);
    printf("Done\n");
    MLV_wait_event(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    MLV_free_window();
    free_uf(&(maze.uf));
}