#pragma once
#include <vector>
#include "raylib.h"

class TextureResource {
public:
    TextureResource();

    void Load(const char *fileName);
    void Unload();
    Texture2D GetTexture();

private:
    Texture2D texture;
};

extern TextureResource playerTexture;
extern TextureResource kroshTexture;
extern TextureResource yozhykTexture;
extern TextureResource kopatychTexture;
extern TextureResource losyashTexture;