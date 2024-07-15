#include "game.h"
#include "enemy.h"
#include "entity.h"
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

void render_grid(struct Context* ctx)
{
    for (int row = 0; row < ctx->game.grid.rows; ++row) {
        for (int col = 0; col < ctx->game.grid.cols; ++col) {
            int tile_idx = row * ctx->game.grid.rows + col;

            int width = ctx->game.grid.tiles[tile_idx].width;
            int height = ctx->game.grid.tiles[tile_idx].height;
            int x = col * width;
            int y = row * height;

            const Rectangle tile = {
                .x = x,
                .y = y,
                .width = width,
                .height = height,
            };
            const float thickness = 1.0f;
            DrawRectangleLinesEx(
                tile,
                thickness,
                LIGHTGRAY
            );

            if (!ctx->game.grid.rendered) {
                ctx->game.grid.tiles[tile_idx].x = x;
                ctx->game.grid.tiles[tile_idx].y = y;
            };
        }
    }
    ctx->game.grid.rendered = true;
}

struct Player player = {0};
void render_player(struct Context* ctx)
{
    if (!player.meta.rendered)
    {
        player.position.width = ctx->game.grid.tiles[0].width;
        player.position.height = ctx->game.grid.tiles[0].height;
        player.position.x = ((float)ctx->game.grid.cols / 2) - (player.position.width / 2);
        player.position.y = ((float)ctx->game.grid.rows / 2) - (player.position.height / 2);
        player.meta.rendered = true;
    }

    entity_clamp(&player.position, ctx->screen.width, ctx->screen.height);

    const Rectangle player_sprite = {
        .x = player.position.x,
        .y = player.position.y,
        .width = player.position.width,
        .height = player.position.height,
    };
    const float thickness = .1f * ctx->meta.factor;
    DrawRectangleLinesEx(player_sprite, thickness, RAYWHITE);

    enum MoveDirection move_direction = MOVE_DIRECTION_NULL;

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) move_direction = MOVE_DIRECTION_UP;
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) move_direction = MOVE_DIRECTION_LEFT;
    if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) move_direction = MOVE_DIRECTION_DOWN;
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) move_direction = MOVE_DIRECTION_RIGHT;

    ctx->game.should_move_enemies = move_direction != MOVE_DIRECTION_NULL;
    if (move_direction != MOVE_DIRECTION_NULL) {
        entity_move(
            &player.position,
            move_direction
        );
    }
}

struct Enemy enemy = {0};
void render_enemy(struct Context* ctx)
{
    if (!enemy.meta.rendered)
    {
        enemy.position.width = ctx->game.grid.tiles[0].width;
        enemy.position.height = ctx->game.grid.tiles[0].height;
        do
        {
            enemy.position.x = rand() % ctx->game.grid.cols;
            enemy.position.y = rand() % ctx->game.grid.rows;
        } while(
            enemy.position.x == player.position.x &&
            enemy.position.y == player.position.y
        );
        enemy.meta.rendered = true;
    }

    entity_clamp(&enemy.position, ctx->screen.width, ctx->screen.height);

    const Rectangle enemy_sprite = {
        .x = enemy.position.x,
        .y = enemy.position.y,
        .width = enemy.position.width,
        .height = enemy.position.height,
    };
    const float thickness = .1f * ctx->meta.factor;
    DrawRectangleLinesEx(enemy_sprite, thickness, RED);

    const int direction = rand() % NUM_MOVE_DIRECTIONS;

    if (ctx->game.should_move_enemies)
    {
        entity_move(
            &enemy.position,
            direction
        );
    }
}
