#include "utils.h"
#include "engine.h"
#include "raylib.h"

void render_fps_counter(struct Context* ctx)
{
    if (!ctx->meta.should_render_fps_counter) return;

    Rectangle box = {
        .x = 16,
        .y = 16,
        .width = 160,
        .height = 160,
    };
    DrawRectangleRec(box, DARKGRAY);

    const int font_size = 64;
    const int padding = 12;
    const char* fps = TextFormat("%d", ctx->meta.fps);
    const float fps_text_size = MeasureText(fps, font_size);
    DrawText(
        fps,
        (box.width / 2 - fps_text_size / 2) + padding,
        (box.height / 2) - padding,
        font_size,
        RAYWHITE
    );
}
