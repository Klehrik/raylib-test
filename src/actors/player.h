#pragma once

#include "actor.h"
#include "timer.h"

class Player : public Actor {
    public:
        float moveSpeed;

        Player();

        /**
         * Handle player input and perform relevant actions.
         */
        void handleInput();

    protected:
        virtual void update() override;
        virtual void draw() override;
};