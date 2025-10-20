#include <iostream>
#include <vector>

#include "raylib.h"
#include "raymath.h"

#include "actor.h"
#include "dummy.h"
#include "player.h"

int main()
{
    const int screenWidth = 400;
    const int screenHeight = 300;
    float windowScale = 3.0f;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth * windowScale, screenHeight * windowScale, "Raylib Demo");
    SetTargetFPS(60);

    // Create camera
    // This and `Window resize testing` section below should be
    // in their own file (should be a wrapper for raylib's Camera2D)
    Camera2D camera;
    camera.target   = Vector2 {0, 0};
    camera.offset   = Vector2 {screenWidth/2 * windowScale, screenHeight/2 * windowScale};
    camera.rotation = 0.0f;
    camera.zoom     = windowScale;
    
    // Create 30 dummies and delete every other one
    for (int i = 0; i < 30; i++) {
        Dummy& dummy = GameObject::create<Dummy>();
        float x = static_cast<float>(GetRandomValue(-150, 150));
        float y = static_cast<float>(GetRandomValue(-100, 100));
        dummy.position = Vector2 {x, y};
        std::cout << TextFormat("Created dummy %i at position (%f, %f)\n", i, x, y);

        if (i % 2 == 0) {
            GameObject::destroy(dummy);
            std::cout << TextFormat("Destroyed dummy %i\n", i);
        }
    }

    // Create player
    Player& player = GameObject::create<Player>();
    player.position = Vector2 {0, 0};
    std::cout << "Created player\n";

    // Main loop
    // Exiting will close
    SetExitKey(KEY_NULL);           // Removes ESC as the default exit key
    while (!WindowShouldClose())    // Detects window close button or exit key
    {
        // Window resize testing
        if (IsWindowResized()) {
            windowScale = static_cast<float>(GetScreenHeight()) / screenHeight;

            // Maintain aspect ratio
            SetWindowSize(screenWidth * windowScale, screenHeight * windowScale);

            // Set camera properties
            camera.offset   = Vector2 {screenWidth/2 * windowScale, screenHeight/2 * windowScale};
            camera.zoom     = windowScale;
        }

        // Update game objects
        GameObject::updateObjects();

        BeginDrawing();
        ClearBackground(GRAY);

        BeginMode2D(camera);

        // Draw game objects
        GameObject::drawObjects();

        EndMode2D();

        // Draw debug text
        int textSize = 10;
        DrawText(TextFormat("Object count: %i", GameObject::getObjectCount()), 4 * windowScale, 4 * windowScale, textSize * windowScale, BLACK);
        DrawText(TextFormat("Player collision count: %i", player.getCollisions().size()), 4 * windowScale, 14 * windowScale, textSize * windowScale, BLACK);
        DrawText(TextFormat("Player position: %.2f, %.2f", player.position.x, player.position.y), 4 * windowScale, 24 * windowScale, textSize * windowScale, BLACK);
        
        EndDrawing();
    }

    CloseWindow();

    return 0;
}