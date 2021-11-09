#include "Game.h"
#include "raylib.h"

Game::Game()
{

}

void Game::Initialise()
{
    SetTargetFPS(60);
    InitWindow(800, 600, "Finite State Machine Demo");

    player = new Agent({150, 150}, 20.0f, BLUE);

    followMouseBehaviour = new FollowMouseBehaviour();
	player->AddBehaviour(followMouseBehaviour);
	player->_maxSpeed= 100.0f;

    redEnemy = new Agent({760, 20}, 20.0f, RED);
	//seekBehaviour = new SeekBehaviour(player);
	//redEnemy->AddBehaviour(seekBehaviour);

	shyEnemy = new Agent({400,300}, 20.0f, YELLOW);
	fleeBehaviour = new FleeBehaviour(player);
	shyEnemy->AddBehaviour(fleeBehaviour);

    chaseState = new ChaseState(player, 50.0f);
    withinRangeCondition = new WithinRangeCondition(player, 175.0f);
    outOfRangeCondition = new OutOfRangeCondition(player, 175.0f);

    toChaseTransition = new Transition(chaseState, withinRangeCondition);
    toIdleTransition = new Transition(idleState, outOfRangeCondition);

    idleState->AddTransition(toChaseTransition);
    chaseState->AddTransition(toIdleTransition);
    
    enemyBehaviour.AddState(idleState);
    enemyBehaviour.AddState(chaseState);
    enemyBehaviour.SetCurrentState(idleState);
}

void Game::RunLoop()
{
    while (!WindowShouldClose())
    {
        ProcessInput();
        UpdateGame(GetFrameTime());
        GenerateOutput();
    }
}

void Game::Shutdown()
{
    CloseWindow();
}

void Game::ProcessInput()
{
    //_mousePosition = GetMousePosition();
}

void Game::UpdateGame(float deltaTime)
{
    player->Update(deltaTime);
    enemyBehaviour.Update(redEnemy, deltaTime);
    redEnemy->Update(deltaTime);
    shyEnemy->Update(deltaTime);
}

void Game::GenerateOutput()
{
    BeginDrawing();

    // clears the screen
    ClearBackground(BLACK);

    player->Draw();
    redEnemy->Draw();
    shyEnemy->Draw();

    EndDrawing();
}