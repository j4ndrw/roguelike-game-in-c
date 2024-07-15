#include "raylib.h"
#include "engine.h"
#include "game.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int ASPECT_RATIO_WIDTH = 16;
int ASPECT_RATIO_HEIGHT = 9;
int FACTOR = 120 * 1.5;

struct Context ctx = {0};

void event_loop(
    setup_handler setup,
    draw_handler draw,
    prerender_handler prerender,
    postrender_handler postrender
)
{
    setup(&ctx);
    while(!WindowShouldClose()) {
        if (prerender != NULL) prerender(&ctx);
        BeginDrawing();

        ctx.screen.width = GetScreenWidth();
        ctx.screen.height = GetScreenHeight();
        ctx.meta.fps = GetFPS();

        draw(&ctx);
        EndDrawing();
        if (postrender != NULL) postrender(&ctx);
    }
}

void setup(struct Context* ctx)
{
    InitWindow(ASPECT_RATIO_WIDTH * FACTOR, ASPECT_RATIO_HEIGHT * FACTOR, "Roguelike Game");

    ctx->screen.aspect_ratio.x = ASPECT_RATIO_WIDTH;
    ctx->screen.aspect_ratio.y = ASPECT_RATIO_HEIGHT;
    ctx->meta.factor = FACTOR;
#ifdef FLAG_DEBUG
    ctx->meta.should_render_fps_counter = true;
#else
    ctx->meta.should_render_fps_counter = false;
#endif

    ctx->screen.width = GetScreenWidth();
    ctx->screen.height = GetScreenHeight();
    alloc_grid(ctx);
}

void draw(struct Context* ctx)
{
    toggle_fullscreen(ctx);

    render_scenery(ctx);

    render_fps_counter(ctx);

    render_grid(ctx);
    render_player(ctx);
    render_enemy(ctx);
}

void prerender(struct Context* ctx)
{
    /*! TODO: I forgor...
     *
     * @todo Cure my dementia.
     */
}

void postrender(struct Context* ctx)
{
    /*! TODO: I forgor...
     *
     * @todo Cure my dementia.
     */
}
