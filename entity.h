#ifndef ENTITY_H
#define ENTITY_H

#include <stdbool.h>

extern int NUM_MOVE_DIRECTIONS;
enum MoveDirection
{
    MOVE_DIRECTION_UP,
    MOVE_DIRECTION_DOWN,
    MOVE_DIRECTION_LEFT,
    MOVE_DIRECTION_RIGHT
};


struct EntityPosition
{
    float x;
    float y;
    float width;
    float height;
};

struct EntityMeta
{
    bool rendered;
};

void entity_move(
    struct EntityPosition* position,
    enum MoveDirection direction,
    float velocity
);

void entity_clamp_to_screen(
    struct EntityPosition* position,
    int screen_width,
    int screen_height
);

#endif // !ENTITY_H
