#pragma once

#include "raylib.h"

#include "gameObject.h"
#include "health.h"

class Actor : public GameObject {
    public:
        Color color;
        Health health;

        Actor();
    
        /**
         * Modifies the drawn rectangle and hitbox size.
         * 
         * @param width The width of the hitbox.
         * @param height The height of the hitbox.
         */
        void setSize(int width, int height);

    protected:
        virtual void update() override;
        virtual void draw() override;
};