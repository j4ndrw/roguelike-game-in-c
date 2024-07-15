#ifndef ENTITY_H
#define ENTITY_H

#include "engine.h"
#include <stdbool.h>

extern int NUM_MOVE_DIRECTIONS;
enum MoveDirection
{
    MOVE_DIRECTION_NULL = 0,
    MOVE_DIRECTION_UP = 1,
    MOVE_DIRECTION_DOWN = 2,
    MOVE_DIRECTION_LEFT = 3,
    MOVE_DIRECTION_RIGHT = 4
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

typedef void (*post_move_action)(struct Context*);

void entity_move(
    struct EntityPosition* position,
    enum MoveDirection direction
);

void entity_clamp(
    struct EntityPosition* position,
    int screen_width,
    int screen_height
);

#endif // !ENTITY_H
