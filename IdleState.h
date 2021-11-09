#pragma once
#include "State.h"
#include <iostream>

class IdleState : public State {
public:
    IdleState() {}
    ~IdleState() {}

    void onUpdate(Agent* agent, float deltaTime) override {
        // slow down the agent
        agent->_acceleration.x -= agent->_velocity.x * deltaTime;
        agent->_acceleration.y -= agent->_velocity.y * deltaTime;
    }

    void onEnter(Agent* agent) {
        std::cout << "Idle state enter\n";
    }

    void onExit(Agent* agent) {
        std::cout << "Idle state exit\n";
    }
};