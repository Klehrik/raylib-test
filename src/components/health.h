#pragma once

class Health {
    public:
        float hp;
        float hpMax;

        /**
         * Set `hp` to equal `hpMax`.
         * 
         * @param value Optionally set a new `hpMax`.
         */
        void reset(float value = 0.0f);

        /**
         * Subtract `hp` by the specified `amount`.
         * 
         * Ensures that `hp` cannot fall below `0`.
         * 
         * @param amount The amount of HP to subtract.
         */
        void takeDamage(float amount);
};