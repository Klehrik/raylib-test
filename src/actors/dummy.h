#pragma once

#include "actor.h"

class Dummy : public Actor {
    public:
        Dummy();

    protected:
        virtual void update() override;
        virtual void draw() override;
};