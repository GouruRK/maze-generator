#ifndef __INIT_GRAPHIC__
#define __INIT_GRAPHIC__

#include "struct.h"

void exit_function(void* data);

void display_default_grid(int cell_width, int cell_height, int cell_size);

void remove_wall(int x, int y, int cell_size, Wall wall);

#endif
