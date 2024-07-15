#include "entity.h"
#include <stdbool.h>

int NUM_MOVE_DIRECTIONS = 4;

void entity_move(
    struct EntityPosition* position,
    enum MoveDirection direction
)
{
    switch(direction)
    {
        case MOVE_DIRECTION_UP: {
            position->y -= position->height;
        } break;
        case MOVE_DIRECTION_DOWN: {
            position->y += position->height;
        } break;
        case MOVE_DIRECTION_LEFT: {
            position->x -= position->width;
        } break;
        case MOVE_DIRECTION_RIGHT: {
            position->x += position->width;
        } break;
        default:
            break;
    }
}

void entity_clamp(
    struct EntityPosition* position,
    int screen_width,
    int screen_height
)
{
    if (position->x >= screen_width) position->x = screen_width;
    if (position->y >= screen_height) position->y = screen_height;
    if (position->x <= 0) position->x = 0;
    if (position->y <= 0) position->y = 0;
}
