#include "raylib.h"
#include "engine.h"
#include "game.h"

int ASPECT_RATIO_WIDTH = 16;
int ASPECT_RATIO_HEIGHT = 9;
int FACTOR = 120 * 1.5;


void event_loop(
    setup_handler setup,
    draw_handler draw,
    prerender_handler prerender,
    postrender_handler postrender
)
{
    struct Context ctx = {0};

    setup();
    while(!WindowShouldClose()) {
        if (prerender != NULL) prerender();
        BeginDrawing();

        ctx.screen.width = GetScreenWidth();
        ctx.screen.height = GetScreenHeight();

        draw(&ctx);
        EndDrawing();
        if (postrender != NULL) postrender();
    }
}

void setup(void)
{
    InitWindow(ASPECT_RATIO_WIDTH * FACTOR, ASPECT_RATIO_HEIGHT * FACTOR, "Roguelike Game");
}

void draw(struct Context* ctx)
{
    render_scenery(ctx);
    render_player(ctx);
}

void prerender(void)
{
    /*! TODO: I forgor...
     *
     * @todo Cure my dementia.
     */
}

void postrender(void)
{
    /*! TODO: I forgor...
     *
     * @todo Cure my dementia.
     */
}
