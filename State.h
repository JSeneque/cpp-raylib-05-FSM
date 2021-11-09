#pragma once

#include <vector>
#include "Transition.h"

class Agent;
class Transition;

class State
{
public :
    virtual ~State() {};
    virtual void onUpdate(Agent* agent, float deltaTime) = 0;
    virtual void onEnter(Agent* agent) {};
    virtual void onExit(Agent* agent) {};

    void AddTransition(Transition* transition)
    {
        _transitions.push_back(transition);
    }

    Transition* GetTriggeredTransition(Agent* agent) {
        for(auto transition : _transitions)
        {
            if (transition->HasTriggered(agent))
                return transition;
        }

        return nullptr;
    }

protected:
    std::vector<Transition*> _transitions;

};