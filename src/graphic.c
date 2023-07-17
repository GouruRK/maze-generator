#include <MLV/MLV_all.h>

#include "../include/graphic.h"
#include "../include/struct.h"

// void display_default_grid(int cell_width, int cell_height, int cell_size) {
//     for (int i = 1; i < cell_width; i++) {
//         MLV_draw_line(i * cell_size, 0, i * cell_size, cell_height * cell_size, MLV_COLOR_RED);
//     }
//     for (int i = 1; i < cell_height; i++) {
//         MLV_draw_line(0, i * cell_size, cell_width * cell_size, i * cell_width, MLV_COLOR_RED);
//     } 
// }

void display_default_grid(int cell_width, int cell_height, int cell_size) {
    for (int i = 1; i < cell_width; i++) {
        MLV_draw_line(i * cell_size, 0, i * cell_size, cell_height * cell_size, MLV_COLOR_RED);
    }
    for (int i = 1; i < cell_height; i++) {
        MLV_draw_line(0, i * cell_size, cell_width * cell_size, i * cell_size, MLV_COLOR_RED);
    } 
}

void remove_wall(int x, int y, int cell_size, Wall wall) {
    x *= cell_size;
    y *= cell_size;
    if (wall == UP) {
        MLV_draw_line(x, y, x + cell_size, y, MLV_COLOR_BLACK);
    } else if (wall == DOWN) {
        MLV_draw_line(x, y + cell_size, x + cell_size, y + cell_size, MLV_COLOR_BLACK);
    } else if (wall == LEFT) {
        MLV_draw_line(x, y, x, y + cell_size, MLV_COLOR_BLACK);
    } else {
        MLV_draw_line(x + cell_size, y, x + cell_size, y + cell_size, MLV_COLOR_BLACK);
    }
}
