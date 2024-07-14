#include "game.h"
#include "enemy.h"
#include "raylib.h"
#include "engine.h"
#include "player.h"
#include <stdbool.h>
#include <stdlib.h>

void render_scenery(struct Context* ctx)
{
    ClearBackground(BLACK);

    const char* text = "Level 1";
    const int font_size = 64;
    const int text_size = MeasureText(text, font_size);
    const int text_height = ctx->screen.height * 5 / 100;

    DrawText(text, ctx->screen.width / 2 - (text_size / 2), text_height, font_size, RAYWHITE);
}

struct Player player = {0};
void render_player(struct Context* ctx)
{

    if (!player.meta.rendered)
    {
        player.position.width = .5 * ctx->meta.factor;
        player.position.height = .5 * ctx->meta.factor;
        player.position.x = ((float)ctx->screen.width / 2) - (player.position.width / 2);
        player.position.y = ((float)ctx->screen.height / 2) - (player.position.height / 2);
        player.meta.rendered = true;
    }

    entity_clamp_to_screen(&player.position, ctx->screen.width, ctx->screen.height);

    const Rectangle player_sprite = {
        .x = player.position.x,
        .y = player.position.y,
        .width = player.position.width,
        .height = player.position.height,
    };
    const float thickness = .1f * ctx->meta.factor;
    DrawRectangleLinesEx(player_sprite, thickness, RAYWHITE);

    const float velocity = 5.0f;

    if (GetKeyPressed() == KEY_NULL) {
        ctx->game.should_move_enemies = false;
    }

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        ctx->game.should_move_enemies = true;
        entity_move(
            &player.position,
            MOVE_DIRECTION_UP,
            velocity
        );
    }
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        ctx->game.should_move_enemies = true;
        entity_move(
            &player.position,
            MOVE_DIRECTION_LEFT,
            velocity
        );
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        ctx->game.should_move_enemies = true;
        entity_move(
            &player.position,
            MOVE_DIRECTION_DOWN,
            velocity
        );
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))  {
        ctx->game.should_move_enemies = true;
        entity_move(
            &player.position,
            MOVE_DIRECTION_RIGHT,
            velocity
        );
    }
}

struct Enemy enemy = {0};
void render_enemy(struct Context* ctx)
{
    if (!enemy.meta.rendered)
    {
        enemy.position.width = .5 * ctx->meta.factor;
        enemy.position.height = .5 * ctx->meta.factor;
        do
        {
            enemy.position.x = rand() % ctx->screen.width;
            enemy.position.y = rand() % ctx->screen.height;
        } while(
            enemy.position.x == player.position.x &&
            enemy.position.y == player.position.y
        );
        enemy.meta.rendered = true;
    }

    entity_clamp_to_screen(&enemy.position, ctx->screen.width, ctx->screen.height);

    const Rectangle enemy_sprite = {
        .x = enemy.position.x,
        .y = enemy.position.y,
        .width = enemy.position.width,
        .height = enemy.position.height,
    };
    const float thickness = .1f * ctx->meta.factor;
    DrawRectangleLinesEx(enemy_sprite, thickness, RED);

    const float velocity = 5.0f;
    const int direction = rand() % NUM_MOVE_DIRECTIONS;

    if (ctx->game.should_move_enemies)
    {
        entity_move(
            &enemy.position,
            direction,
            velocity
        );
    }
}
