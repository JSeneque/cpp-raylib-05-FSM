#pragma once
#include <vector>
#include "State.h"
#include "Transition.h"
#include "Condition.h"

class Agent;

class FiniteStateMachine {
public:
    FiniteStateMachine() : _currentState (nullptr) {}
    ~FiniteStateMachine() {
        for (auto s : _states)
            delete s;
    }

    State* AddState(State* state) {
        _states.push_back(state);
        return state;
    }

    void SetCurrentState(State* state) {  _currentState = state;}
    virtual void Update(Agent* agent, float deltaTime);

protected:
    std::vector<State*> _states;
    State* _currentState;
};