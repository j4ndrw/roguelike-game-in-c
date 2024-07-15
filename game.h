#ifndef GAME_H
#define GAME_H

#include "engine.h"
#include <stdbool.h>

void render_scenery(struct Context* ctx);
void render_player(struct Context* ctx);
void render_enemy(struct Context* ctx);
void render_grid(struct Context* ctx);

#endif // GAME_H
