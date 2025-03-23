#include "enemy.hpp"

#define ENEMY_SIZE 200.0f
#define ENEMY_COL_SIZE 200.0f

Enemy::Enemy(Vector2 pos, TextureResource *texture, Rectangle source): 
    aabb(AABB(pos.x, pos.y, ENEMY_COL_SIZE, ENEMY_COL_SIZE)), 
    vel(Vector2 { 0, 0 }), 
    speed(400.0),
    texture(texture),
    source(Rectangle { source.x, source.y, source.width, source.height }),
    dest(Rectangle { 0, 0, ENEMY_SIZE, ENEMY_SIZE }),
    isActive(true) {}

void Enemy::Update() {
    if (!isActive) { return; }
}

void Enemy::Render() {
    if (!isActive) { return; }
    DrawTexturePro(texture->GetTexture(), source, dest, Vector2 { -aabb.GetPos().x, -aabb.GetPos().y }, 0, WHITE);
}

void Enemy::SetActive(bool active) {
    this->isActive = active;
}

AABB Enemy::GetAABB() {
    return aabb;
}

Vector2 Enemy::GetPos() {
    return aabb.GetPos();
}

Vector2 Enemy::GetVel() {
    return vel;
}
