#ifndef GAME_H
#define GAME_H

#include "engine.h"
#include <stdbool.h>

struct PlayerPosition { float x; float y; };
struct Player
{
    struct PlayerPosition position;
    bool rendered;
};

void hello_world(void);
void render_scenery(struct Context* ctx);
void render_player(struct Context* ctx);

#endif // GAME_H
