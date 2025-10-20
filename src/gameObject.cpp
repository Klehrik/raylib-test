#include "gameObject.h"

std::vector<std::shared_ptr<GameObject>> GameObject::objects = std::vector<std::shared_ptr<GameObject>>();

void GameObject::moveAndSlide() {
    // Horizontal wall collision
    // TODO

    // Vertical wall collision
    // TODO

    // Update position
    position = Vector2Add(position, Vector2Scale(velocity, GetFrameTime()));
}

std::vector<std::shared_ptr<GameObject>> GameObject::getCollisions() {
    std::vector<std::shared_ptr<GameObject>> collisions = std::vector<std::shared_ptr<GameObject>>();

    Vector2 thisP1 = Vector2 {position.x + hitbox.p1.x, position.y + hitbox.p1.y};
    Vector2 thisP2 = Vector2 {position.x + hitbox.p2.x, position.y + hitbox.p2.y};

    for (auto object : objects) {
        if (object == getSharedPtr())
            continue;

        Vector2 boxP1 = Vector2 {object->position.x + object->hitbox.p1.x, object->position.y + object->hitbox.p1.y};
        Vector2 boxP2 = Vector2 {object->position.x + object->hitbox.p2.x, object->position.y + object->hitbox.p2.y};

        // Check if boxes are *not* colliding
        if (thisP1.x > boxP2.x
         || thisP2.x < boxP1.x
         || thisP1.y > boxP2.y
         || thisP2.y < boxP1.y)
            continue;

        // Add to list
        collisions.push_back(object);
    }

    return collisions;
}

void GameObject::updateObjects() {
    for (std::shared_ptr<GameObject> object : objects) {
        object->update();
    }
}

void GameObject::drawObjects() {
    for (std::shared_ptr<GameObject> object : objects) {
        object->draw();
    }
}

std::size_t GameObject::getObjectCount() {
    return objects.size();
}