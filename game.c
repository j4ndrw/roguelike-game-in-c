#include "game.h"
#include "raylib.h"
#include "engine.h"
#include <stdbool.h>

void render_scenery(struct Context* ctx)
{
    ClearBackground(BLACK);

    const char* text = "Level 1";
    const int fontSize = 64;
    const int textSize = MeasureText(text, fontSize);
    const int textHeight = ctx->screen.height * 5 / 100;

    DrawText(text, ctx->screen.width / 2 - (textSize / 2), textHeight, fontSize, RAYWHITE);
}

void clamp_player_to_screen(struct Player* player, int screen_width, int screen_height)
{
    if (player->position.x >= screen_width) player->position.x = screen_width;
    if (player->position.y >= screen_height) player->position.y = screen_height;
    if (player->position.x <= 0) player->position.x = 0;
    if (player->position.y <= 0) player->position.y = 0;
}

struct Player player = {0};
void render_player(struct Context* ctx)
{
    const float player_sprite_width = .5 * ctx->meta.factor;
    const float player_sprite_height = .5 * ctx->meta.factor;

    clamp_player_to_screen(&player, ctx->screen.width, ctx->screen.height);

    if (!player.rendered)
    {
        player.position.x = ((float)ctx->screen.width / 2) - (player_sprite_width / 2);
        player.position.y = ((float)ctx->screen.height / 2) - (player_sprite_height / 2);
        player.rendered = true;
    }
    const Rectangle player_sprite = {
        .x = player.position.x,
        .y = player.position.y,
        .width = player_sprite_width,
        .height = player_sprite_height,
    };
    const float thickness = .1f * ctx->meta.factor;
    DrawRectangleLinesEx(player_sprite, thickness, RAYWHITE);

    const float velocity = 5.0f;

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) player.position.y -= velocity;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) player.position.x -= velocity;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) player.position.y += velocity;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) player.position.x += velocity;
}
