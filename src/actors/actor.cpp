#include "actor.h"

Actor::Actor() {
    color = WHITE;
}

void Actor::setSize(int width, int height) {
    hitbox.p1 = Vector2 {-width/2.0f, -height/2.0f};
    hitbox.p2 = Vector2 {width/2.0f, height/2.0f};
}

void Actor::update() {}

void Actor::draw() {
    // Use hitbox size for drawing
    float width  = hitbox.p2.x - hitbox.p1.x;
    float height = hitbox.p2.y - hitbox.p1.y;
    DrawRectangle(position.x - width/2.0f, position.y - height/2.0f, width, height, color);
}