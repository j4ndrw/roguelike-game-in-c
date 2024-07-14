#include "entity.h"
#include <stdbool.h>

int NUM_MOVE_DIRECTIONS = 4;

void entity_move(
    struct EntityPosition* position,
    enum MoveDirection direction,
    float velocity
)
{
    switch(direction)
    {
        case MOVE_DIRECTION_UP: {
            position->y -= velocity;
        } break;
        case MOVE_DIRECTION_DOWN: {
            position->y += velocity;
        } break;
        case MOVE_DIRECTION_LEFT: {
            position->x -= velocity;
        } break;
        case MOVE_DIRECTION_RIGHT: {
            position->x += velocity;
        } break;
    }
}

void entity_clamp_to_screen(
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
