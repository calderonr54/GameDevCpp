#include "raylib.h"

int main(){

    //Window dimensions
    //const means the variable is constant which never changes
    const int windowWidth{512};
    const int windowHeight{300};

    //Initialize window
    InitWindow(windowWidth, windowHeight, "Dapper Dashher by Ricardo");

    //Rectangle dimensions
    const int width{50};
    const int height{80};

    int posY{windowHeight - height}; //subtract to place rectangle on the ground
    int velocity{0};

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        
        //Start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        if(IsKeyPressed(KEY_SPACE)){

            velocity -=10;

        }

        //Update Y position
        posY += velocity;

        DrawRectangle(windowHeight/2, posY, width, height, BLUE);

        //Stop drawing
        EndDrawing();

    }

    //Properly closing window
    CloseWindow();
    
}