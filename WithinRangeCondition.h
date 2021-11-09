#include "Condition.h"
#include "raymath.h"
#include "raylib.h"
#include "Agent.h"

class WithinRangeCondition : public Condition { 
    public: 
        WithinRangeCondition(Agent* target, float range) : 
            _target(target), _range(range) {} 
        virtual ~WithinRangeCondition() {} 
        bool Test(Agent* agent) const override {
            // get the distance to the player
            float distance = Vector2Distance(_target->GetPosition(), agent->GetPosition());
            // check if within range and return true or false
            return distance <= _range;
        }
    private:
        Agent* _target; 
        float _range; 
};