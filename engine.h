#pragma once

#ifndef ENGINE_H
#define ENGINE_H

#include "raylib.h"
#include <stddef.h>

extern int ASPECT_RATIO_WIDTH;
extern int ASPECT_RATIO_HEIGHT;
extern int FACTOR;

struct Screen
{
    int width;
    int height;
};
struct Context
{
    struct Screen screen;
};

typedef void (*setup_handler)(void);

typedef void (*prerender_handler)(void);
typedef void (*postrender_handler)(void);
typedef void (*draw_handler)(struct Context*);


void event_loop(
    setup_handler setup,
    draw_handler draw,
    prerender_handler prerender,
    postrender_handler postrender
);

void setup(void);
void draw(struct Context* ctx);
void prerender(void);
void postrender(void);

#endif // ENGINE_H
