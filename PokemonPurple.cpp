/**************************************************************************************************************
*
*   COOL LITTLE GAME IN C++, USING: RAYLIB 5.0
*
**************************************************************************************************************/



     //---------------------------------------------------------------------------//
    //  NOTE:                                                                    //            
   //     when subtracting from an objects position on the y axis; it will      //
  //      appear to be moving up and vise versa meaning that, up is a          // 
 //       lower value or negative, while down is a positive or higher number  // 
//---------------------------------------------------------------------------//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "raylib.h"
#include "Move.h"
#include "Pokemon.h"
#include "Pokedex.h"
#include "Movepool.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------



int main(void)
{
   
    
    // Initialization
    //--------------------------------------------------------------------------------------
    //creating variables to set the screen dimentions to
    const int screenWidth = 1600;
    const int screenHeight = 900;
    
    
    
    
    InitWindow(screenWidth, screenHeight, " |Pokemon Purple Version| "); //initilisation of the window 

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
     Pokemon Bulbasaur(50, "Bulbasaur", "Grass", 5, 0, 0, LoadTexture("Assets/Pokemon/Bulbasaur/Bulbasaur_front.png"), LoadTexture("Assets/Pokemon/Bulbasaur/Bulbasaur_back.png"), {&tackle, NULL, NULL, NULL});
     Bulbasaur.spriteFront.width = 100;
     Bulbasaur.spriteFront.height = 100;
    
    //initializes camera values
    Camera2D camera = { 0 };
    camera.offset = {screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera.target = {0,0};

    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    
    while (!WindowShouldClose()){    // Detect window close button or ESC key
    
    
    
    
      // Draw, where the scene actually gets rendered and drawn out

      
        BeginDrawing();
        
        
            
            //anything drawn inside of the BeginMode2D() and EndMode2D() are going to be drawn onto the world and wont move with the camera but anything drawn after EndMode2D() is drawn onto the screen and moves with the camera useful for UI
                BeginMode2D(camera);
                ClearBackground(RAYWHITE);
                
                DrawTextureEx(Bulbasaur.spriteBack, {-700,0}, 0, 1, WHITE);
                
                
                
                EndMode2D();
            
            
            
                
            
          
           
        //ends the drawing phase of the program     
        EndDrawing();
        //----------------------------------------------------------------------------------
    } 
     
     

    // De-Initialization
    //--------------------------------------------------------------------------------------
      // Texture unloading
      

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
