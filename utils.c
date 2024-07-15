#include "utils.h"
#include "engine.h"
#include "raylib.h"
#include <assert.h>
#include <stdlib.h>

void render_fps_counter(struct Context* ctx)
{
    if (!ctx->meta.should_render_fps_counter) return;

    const int font_size = 32;
    const int padding = 6;
    const char* fps = TextFormat("%d", ctx->meta.fps);
    const float fps_text_size = MeasureText(fps, font_size);
    DrawText(
        fps,
        16,
        16,
        font_size,
        RAYWHITE
    );
}

void toggle_fullscreen(struct Context* ctx)
{
    if (!IsKeyPressed(KEY_F12)) return;
    ToggleFullscreen();
}

void alloc_grid(struct Context* ctx)
{
    const int cols = ctx->screen.aspect_ratio.x;
    const int rows = ctx->screen.aspect_ratio.y;

    const int width = ctx->screen.width / cols;
    const int height = ctx->screen.height / rows;
    ctx->game.grid.rows = height;
    ctx->game.grid.cols = width;

    ctx->game.grid.tiles = malloc(width * height * sizeof(struct Tile));
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            int tile_idx = row * width + col;
            struct Tile tile = {
                .x = col * width,
                .y = row * height,
                .width = width,
                .height = height
            };
            ctx->game.grid.tiles[tile_idx] = tile;
        }
    }
    ctx->game.grid.rendered = false;
}
