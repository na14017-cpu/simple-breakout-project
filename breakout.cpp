#include "assets.h"
#include "ball.h"
#include "game.h"
#include "graphics.h"
#include "level.h"
#include "paddle.h"

#include "raylib.h"

void update()
{
    switch (game_state) {
    case menu_state:
        if (IsKeyPressed(KEY_ENTER)) {
            game_state = in_game_state;
        }
        break;
    case in_game_state:
        if (IsKeyPressed(KEY_X)) {
            load_level(1);
        }
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
            move_paddle(-paddle_speed);
        }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            move_paddle(paddle_speed);
        }
        move_ball();
        if (!is_ball_inside_level()) {
            game_state = losing_state;
            PlaySound(lose_sound);
        } else if (current_level_blocks == 0) {
            load_level(1);
            PlaySound(win_sound);
        }
        if (IsKeyPressed(KEY_SPACE)) {
            game_state = paused_state;
        }

        break;
    case paused_state:
        if (IsKeyPressed(KEY_SPACE)) {
            game_state = in_game_state;
        }
        break;
    case victory_state:
        if (IsKeyPressed(KEY_ENTER))  {
            game_state = menu_state;
            current_level_index = -1;
        }
    case losing_state:
        if (IsKeyPressed(KEY_ENTER)) {
            game_state = menu_state;
        }
    default:;
    }
}


void draw()
{
    switch(game_state) {
    case menu_state:
        draw_menu();
        break;
    case in_game_state:
        draw_level();
        draw_paddle();
        draw_ui();
        draw_ball();
        break;
    case victory_state:
        draw_victory_menu();
        break;
    case paused_state:
        draw_pause_menu();
        break;
    case losing_state:
        draw_lose_menu();
        break;
    }

}

int main()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(1280, 720, "Breakout");
    SetTargetFPS(60);

    load_fonts();
    load_textures();
    load_level();
    load_sounds();

    while (!WindowShouldClose()) {

        BeginDrawing();
        update();
        draw();

        EndDrawing();
    }
    CloseWindow();

    unload_sounds();
    unload_level();
    unload_textures();
    unload_fonts();

    return 0;
}
