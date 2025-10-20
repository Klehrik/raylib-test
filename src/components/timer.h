#pragma once

#include <vector>

class Timer {
    public:
        float timeLeft;
        float timeMax;

        /**
         * @param time The starting maximum time of the timer.
         *      Defaults to `1` second.
         */
        Timer(float time = 1.0f);
        ~Timer();

        /**
         * Set `timeLeft` to equal `timeMax`.
         */
        void reset();

        /**
         * @returns `true` if `timeLeft` is `0f`.
         */
        bool isDone();

        /**
         * Reduce all currently active timers by `GetFrameTime()`.
         * 
         * Should be called once in the main update loop every frame.
         */
        static void processTimers();

    private:
        static std::vector<Timer*> timers;
};