#ifndef ASSETS_H
#define ASSETS_H

#include "raylib.h"

#include "sprite.h"

inline Font menu_font;

inline Texture2D wall_texture;
inline Texture2D void_texture;
inline Texture2D paddle_texture;
inline Texture2D block_texture;
inline Texture2D block1_texture;
inline Texture2D background1_texture;
inline Texture2D defeat_texture;
inline Texture2D victory_texture;
inline Texture2D pause_texture;
inline Texture2D menu_texture;
inline Texture2D portal_texture;
inline Texture2D coin_texture;
inline sprite ball_sprite;

inline Sound sound_rock;
inline Sound coin_sound;
inline Sound win_sound;
inline Sound portal_sound;
inline Sound lose_sound;
inline Sound back_sound;

void load_fonts();
void unload_fonts();

void load_textures();
void unload_textures();

void load_sounds();
void unload_sounds();

#endif // ASSETS_H
