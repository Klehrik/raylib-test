#include "health.h"

#include <algorithm>

void Health::reset(float value) {
    if (value) hpMax = value;
    hp = hpMax;
}

void Health::takeDamage(float amount) {
    hp = std::max(hp - amount, 0.0f);
}