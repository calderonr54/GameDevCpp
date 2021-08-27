#include "raylib.h"

int main(){

    //Window dimensions
    //const means the variable is constant which never changes
    const int windowWidth{512};
    const int windowHeight{300};

    //Initialize window
    InitWindow(windowWidth, windowHeight, "Dapper Dashher by Ricardo");

    //Acceleration due to grativity (pixels/frame)/frame
    const int gravity{1'000};

    //Adding 2D textures
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;

    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2; //Place Scarfy in the center
    scarfyPos.y = windowHeight - scarfyRec.height;
    

    //Prevent air jumping
    bool isInAir{};

    //Jump velocity
    const int jumpVel{-600};

    int velocity{0};

    SetTargetFPS(60);

    while(!WindowShouldClose()){

        //Delta time (time since last frame)
        const float dT{GetFrameTime()};

        //Start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        //Perform ground check
        if(scarfyPos.y >= windowHeight - scarfyRec.height){

            //Rectangle is on the ground
            //Set velocity back to 0
            velocity = 0;
            isInAir = false;

        }
        else{
            //Rectangle is in the air
            //Apply gravity
            velocity += gravity * dT;
            isInAir = true;
            
        }

        //Jump check
        if(IsKeyPressed(KEY_SPACE) && !isInAir){

            velocity += jumpVel;

        }

        //Update Y position
        scarfyPos.y += velocity * dT;    

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        //Stop drawing
        EndDrawing();

    }

    //Unload texture properly
    UnloadTexture(scarfy);
    //Properly closing window
    CloseWindow();
    
}