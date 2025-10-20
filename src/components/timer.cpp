#include "timer.h"

#include <algorithm>
#include "raylib.h"

std::vector<Timer*> Timer::timers = std::vector<Timer*>();

Timer::Timer(float time) {
    timeLeft = time;
    timeMax  = time;

    // Add timer to list
    timers.push_back(this);
}

Timer::~Timer() {
    // Remove timer from list
    timers.erase(std::find(timers.begin(), timers.end(), this));
}

void Timer::reset() {
    timeLeft = timeMax;
}

bool Timer::isDone() {
    return timeLeft <= 0.0f;
}

void Timer::processTimers() {
    for (Timer* timer : timers) {
        timer->timeLeft = std::max(timer->timeLeft - GetFrameTime(), 0.0f);
    }
}