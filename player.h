#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

struct Player
{
    struct EntityPosition position;
    struct EntityMeta meta;
};

#endif // !PLAYER_H
