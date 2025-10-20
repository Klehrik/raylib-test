#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include "raylib.h"

#include "collisionBox.h"

/**
 * Abstract class for anything that should have
 * stuff be called on every frame.
 * 
 * The following must be overridden:
 * `update`
 * `draw`
 */
class GameObject : public std::enable_shared_from_this<GameObject> {
    public:
        Vector2 position;
        Vector2 velocity;
        CollisionBox hitbox;

        std::shared_ptr<GameObject> getSharedPtr() {
            return shared_from_this();
        }

        /**
         * Apply velocity to the object's
         * position and handle collision with walls.
         */
        void moveAndSlide();

        /**
         * Get all intersecting `GameObject`s.
         * 
         * @returns A vector of `std::shared_ptr<GameObject>`s.
         */
        std::vector<std::shared_ptr<GameObject>> getCollisions();

        /**
         * Create an object of a derived class of `GameObject`.
         */
        template <class T>
        static T& create() {
            // This must be in the header file to
            // avoid explicit template instantiation
            std::shared_ptr<T> obj = std::make_shared<T>();
            objects.push_back(obj);
            return *obj;
        }

        /**
         * Destroy an object of a derived class of `GameObject`.
         */
        static void destroy(GameObject& obj) {
            // This must be in the header file to
            // avoid explicit template instantiation
            objects.erase(std::find(objects.begin(), objects.end(), obj.getSharedPtr()));
        }

        /**
         * Call `update` for all objects.
         * 
         * Should be called once in the main update loop every frame.
         */
        static void updateObjects();

        /**
         * Call `draw` for all objects.
         * 
         * Should be called once in the main draw loop every frame.
         */
        static void drawObjects();

        /**
         * @returns The number of objects currently existing.
         */
        static std::size_t getObjectCount();

    protected:
        // The following must be overridden

        /**
         * Called every frame during the main update loop.
         */
        virtual void update() = 0;

        /**
         * Called every frame during the main draw loop.
         */
        virtual void draw() = 0;

    private:
        static std::vector<std::shared_ptr<GameObject>> objects;
};