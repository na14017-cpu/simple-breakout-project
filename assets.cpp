#include "assets.h"

#include "raylib.h"

void load_fonts()
{
    menu_font = LoadFontEx("data/fonts/ARCADECLASSIC.TTF", 256, nullptr, 0);
}

void unload_fonts()
{
    UnloadFont(menu_font);
}

void load_textures()
{
    coin_texture = LoadTexture("data/images/coin.png");
    portal_texture = LoadTexture("data/images/portal.png");
    wall_texture = LoadTexture("data/images/wall.png");
    void_texture = LoadTexture("data/images/void.png");
    block_texture = LoadTexture("data/images/blocks/block0.png");
    block1_texture = LoadTexture("data/images/blocks/block1.png");
    paddle_texture = LoadTexture("data/images/paddle1.png");
    background1_texture = LoadTexture("data/images/backgrounds/background1.png");
    victory_texture = LoadTexture("data/images/victory.png");
    defeat_texture = LoadTexture("data/images/defeat.png");
    pause_texture = LoadTexture("data/images/pause.png");
    menu_texture = LoadTexture("data/images/menu.png");
    ball_sprite = load_sprite("data/images/ball/stoneball", + ".png", 8, true, 0);
}

void unload_textures()
{
    UnloadTexture(background1_texture);
    UnloadTexture(menu_texture);
    UnloadTexture(portal_texture);
    UnloadTexture(victory_texture);
    UnloadTexture(defeat_texture);
    UnloadTexture(pause_texture);
    UnloadTexture(wall_texture);
    UnloadTexture(block1_texture);
    UnloadTexture(void_texture);
    UnloadTexture(block_texture);
    UnloadTexture(paddle_texture);
    UnloadTexture(coin_texture);
    unload_sprite(ball_sprite);
}

void load_sounds()
{
    InitAudioDevice();
    back_sound = LoadSound("data/sounds/backmusic.wav");
    win_sound = LoadSound("data/sounds/point.wav");
    coin_sound = LoadSound("data/sounds/coin.wav");
    portal_sound = LoadSound("data/sounds/portalsound.wav");
    lose_sound = LoadSound("data/sounds/die.wav");
    sound_rock = LoadSound("data/sounds/soundrock.wav");
}

void unload_sounds()
{
    UnloadSound(coin_sound);
    UnloadSound(win_sound);
    UnloadSound(portal_sound);
    UnloadSound(lose_sound);
    UnloadSound(sound_rock);
    UnloadSound(back_sound);

    CloseAudioDevice();
}
