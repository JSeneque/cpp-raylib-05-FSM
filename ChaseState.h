#pragma once
#include "State.h"
#include <iostream>

class Agent;

class ChaseState : public State {
public:
    ChaseState(Agent* target, float speed): _target(target), _moveSpeed(speed) {}
    ~ChaseState() {}

    void onUpdate(Agent* agent, float deltaTime) override;

    void onEnter(Agent* agent) {
        std::cout << "Chase state enter\n";
    }

    void onExit(Agent* agent) {
        std::cout << "Chase state exit\n";
    }

private:
    Agent* _target;
    float _moveSpeed{0.0f};
};