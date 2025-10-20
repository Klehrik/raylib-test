#include "player.h"

#include "raylib.h"
#include "raymath.h"

Player::Player() {
    moveSpeed = 60.0f;

    setSize(16, 16);
    color = BLUE;
}

void Player::handleInput() {
    // Get normalized movement vector
    Vector2 movement {0, 0};
    if (IsKeyDown(KEY_A)) movement.x = -1;
    if (IsKeyDown(KEY_D)) movement.x = 1;
    if (IsKeyDown(KEY_W)) movement.y = -1;
    if (IsKeyDown(KEY_S)) movement.y = 1;
    if (Vector2Length(movement) != 0)
        movement = Vector2Normalize(movement);

    // Set velocity
    velocity = Vector2Scale(movement, moveSpeed);
}

void Player::update() {
    handleInput();
    moveAndSlide();
}

void Player::draw() {
    Actor::draw();
}