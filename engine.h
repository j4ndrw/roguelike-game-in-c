#ifndef ENGINE_H
#define ENGINE_H

#include "raylib.h"
#include <stddef.h>

extern int ASPECT_RATIO_WIDTH;
extern int ASPECT_RATIO_HEIGHT;
extern int FACTOR;

struct AspectRatio
{
    int x;
    int y;
};

struct Screen
{
    int width;
    int height;
    struct AspectRatio aspect_ratio;
};

struct Meta
{
    int factor;
    bool should_render_fps_counter;
    int fps;
};

struct Tile
{
    int x;
    int y;
    int width;
    int height;
};

struct Grid
{
    struct Tile* tiles;
    int rows;
    int cols;
    bool rendered;
};

struct Game
{
    bool should_move_enemies;
    struct Grid grid;
};

struct Context
{
    struct Screen screen;
    struct Meta meta;
    struct Game game;
};

typedef void (*setup_handler)(struct Context*);
typedef void (*prerender_handler)(struct Context*);
typedef void (*postrender_handler)(struct Context*);
typedef void (*draw_handler)(struct Context*);


void event_loop(
    setup_handler setup,
    draw_handler draw,
    prerender_handler prerender,
    postrender_handler postrender
);

void setup(struct Context* ctx);
void draw(struct Context* ctx);
void prerender(struct Context* ctx);
void postrender(struct Context* ctx);

#endif // ENGINE_H
