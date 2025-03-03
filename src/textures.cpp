#include "textures.hpp"

TextureResource::TextureResource() {}

void TextureResource::Load(const char *fileName) {
    texture = LoadTextureFromImage(LoadImage(fileName));
}

void TextureResource::Unload() {
    UnloadTexture(texture);
}

Texture2D TextureResource::GetTexture() {
    return texture;
}

TextureResource playerTexture;