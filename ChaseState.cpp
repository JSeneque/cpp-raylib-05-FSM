#include "ChaseState.h"
#include "raylib.h"
#include "Agent.h"
#include "raymath.h"


void ChaseState::onUpdate(Agent* agent, float deltaTime) {
    Vector2 direction = Vector2Subtract(_target->GetPosition(),agent->GetPosition());
    agent->_acceleration = Vector2Scale(Vector2Normalize(direction), 
                                (agent->_maxSpeed * deltaTime));
}   