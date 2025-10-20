#include "dummy.h"

#include "raylib.h"

Dummy::Dummy() {
    setSize(12, 12);
    color = BEIGE;
}

void Dummy::update() {}

void Dummy::draw() {
    Actor::draw();
}