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
    
    Texture2D baseE = LoadTexture("Assets/Battle Assets/Battle Base Grass Opp.png");
    Texture2D baseP = LoadTexture("Assets/Battle Assets/Battle Base Grass Ally.png");
    Texture2D HPboxP = LoadTexture("Assets/Battle Assets/PlayerHPBox.png");
    Texture2D HPboxE = LoadTexture("Assets/Battle Assets/EnemyHPBox.png");
    /*
    Pokemon constructer paramaters:
    (health, name,  type,  level,  exp,  stage, spriteFront,  spriteBack, *moveset[4], stats{})
    */
     Pokemon Bulbasaur(50, 50, "Bulbasaur", "Grass", 5, 0, 0, LoadTexture("Assets/Pokemon/Bulbasaur/Bulbasaur_front.png"), LoadTexture("Assets/Pokemon/Bulbasaur/Bulbasaur_back.png"), {&tackle, NULL, NULL, NULL}, {45,49,49,65,65,45});
     Bulbasaur.spriteBack.width = 600;
     Bulbasaur.spriteBack.height = 600;
     Bulbasaur.spriteFront.width = 500;
     Bulbasaur.spriteFront.height = 500;
     Pokemon Squirtle(50, 50, "Squirtle", "Water", 5, 0, 0, LoadTexture("Assets/Pokemon/Squirtle/Squirtle_front.png"), LoadTexture("Assets/Pokemon/Squirtle/Squirtle_back.png"), {&tackle, NULL, NULL, NULL},{44,48,65,50,64,43});
     Squirtle.spriteFront.width = 500;
     Squirtle.spriteFront.height = 500;
     Squirtle.spriteBack.width = 600;
     Squirtle.spriteBack.height = 600;
     Pokemon Rayquaza(500, 500, "Rayquaza", "Dragon", 70, 0, 0, LoadTexture("Assets/Pokemon/Rayquaza/Rayquaza_front.png"), LoadTexture("Assets/Pokemon/Rayquaza/Rayquaza_back.png"), {&tackle, NULL, NULL, NULL},{105,150,90,150,90,95});
     Rayquaza.spriteBack.width = 600;
     Rayquaza.spriteBack.height = 600;
     Rayquaza.spriteFront.width = 500;
     Rayquaza.spriteFront.height = 500;
     Pokemon Treecko(50, 50, "Treecko", "Grass", 5, 0, 0, LoadTexture("Assets/Pokemon/Treecko/Treecko_front.png"), LoadTexture("Assets/Pokemon/Treecko/Treecko_back.png"), {&tackle, NULL, NULL, NULL}, {40,45,35,60,65,70});
     Treecko.spriteBack.width = 600;
     Treecko.spriteBack.height = 600;
     Treecko.spriteFront.width = 500;
     Treecko.spriteFront.height = 500;
     Pokemon Mudkip(50, 50, "Mudkip", "Water", 5, 0, 0, LoadTexture("Assets/Pokemon/Mudkip/Mudkip_front.png"), LoadTexture("Assets/Pokemon/Mudkip/Mudkip_back.png"), {&tackle, NULL, NULL, NULL},{50,70,50,50,50,40});
     Mudkip.spriteBack.width = 600;
     Mudkip.spriteBack.height = 600;
     Mudkip.spriteFront.width = 500;
     Mudkip.spriteFront.height = 500;
     Pokemon Torchic(50, 50, "Torchic", "Fire", 5, 0, 0, LoadTexture("Assets/Pokemon/Torchic/Torchic_front.png"), LoadTexture("Assets/Pokemon/Torchic/Torchic_back.png"), {&tackle, NULL, NULL, NULL},{45,60,40,70,50,45});
     Torchic.spriteBack.width = 600;
     Torchic.spriteBack.height = 600;
     Torchic.spriteFront.width = 500;
     Torchic.spriteFront.height = 500;
     Pokemon Absol(50, 50, "Absol", "Dark", 5, 0, 0, LoadTexture("Assets/Pokemon/Absol/Absol_front.png"), LoadTexture("Assets/Pokemon/Absol/Absol_back.png"), {&tackle, NULL, NULL, NULL},{65,130,60,75,60,75});
     Absol.spriteBack.width = 600;
     Absol.spriteBack.height = 600;
     Absol.spriteFront.width = 500;
     Absol.spriteFront.height = 500;
     Pokemon Shroomish(50, 50, "Shroomish", "Poison", 5, 0, 0, LoadTexture("Assets/Pokemon/Shroomish/Shroomish_front.png"), LoadTexture("Assets/Pokemon/Shroomish/Shroomish_back.png"), {&tackle, NULL, NULL, NULL}, {60,40,60,40,60,35});
     Shroomish.spriteBack.width = 600;
     Shroomish.spriteBack.height = 600;
     Shroomish.spriteFront.width = 500;
     Shroomish.spriteFront.height = 500;
     Pokemon Raltz(50, 50, "Raltz", "Poison", 5, 0, 0, LoadTexture("Assets/Pokemon/Raltz/Raltz_front.png"), LoadTexture("Assets/Pokemon/Raltz/Raltz_back.png"), {&tackle, NULL, NULL, NULL}, {28, 25,25, 45,35,40});
     Raltz.spriteBack.width = 600;
     Raltz.spriteBack.height = 600;
     Raltz.spriteFront.width = 500;
     Raltz.spriteFront.height = 500;
    
    //initializes camera values
    Camera2D camera = { 0 };
    camera.offset = {screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera.target = {800,450};
    
    bool PartyMenu = false;
    bool moveMenu = false;
    
    bool loseE = false;
    Pokemon *enemyTeam[6] = {&Rayquaza, NULL, NULL, NULL, NULL, NULL};
    Pokemon *party[6] = {&Shroomish, &Raltz, &Torchic, &Mudkip, &Rayquaza, &Absol};
    
    int activePKM = 0;
    int activePKME = 0;
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    
    while (!WindowShouldClose()){    // Detect window close button or ESC key
    
    int checkTeam = 0;
    for(int i = 0; i < 6; i++){
        if(party[i] == NULL || party[i]->fainted){
            checkTeam++;
        }
    }
    if(checkTeam == 6) return 0;
    
      // Draw, where the scene actually gets rendered and drawn out

      
        BeginDrawing();
            
            
            if(IsKeyPressed(KEY_BACKSPACE)) party[activePKM]->health -= 10;
        
            
            //anything drawn inside of the BeginMode2D() and EndMode2D() are going to be drawn onto the world and wont move with the camera but anything drawn after EndMode2D() is drawn onto the screen and moves with the camera useful for UI
                BeginMode2D(camera);
                
                if(PartyMenu)ClearBackground(GRAY);
                else ClearBackground(DARKGREEN);
                
                
               
                
                
                
                
                
                EndMode2D();
                
                
                if(!PartyMenu){
                    DrawTextureEx(baseE, {1000,325}, 0, 4.5, WHITE);
                    DrawTextureEx(baseP, {37,540}, 0, 4.5, WHITE);
                    
                    
                    
                    DrawTextureEx(party[activePKM]->spriteBack, {100,225}, 0, 1, WHITE);
                    
                    DrawTextureEx(enemyTeam[activePKME]->spriteFront, {1000,0}, 0, 1, WHITE);
                    
                    DrawRectangle(25, 675, 1125, 450,  DEFCOLOR(0,0,0,240));
                    
                    if(!moveMenu){
                        if(CheckCollisionPointRec({GetMouseX(), GetMouseY()}, {50, 700, 250, 150})){
                            DrawRectangle(50, 725, 250, 150, RED);
                            DrawText("Fight", 75, 775, 50, WHITE);
                            if(IsMouseButtonPressed(0)){
                                 moveMenu = true;
                            }
                            
                        }else{
                            DrawRectangleLines(50, 700, 250, 150, RED);
                            DrawText("Fight", 75, 750, 50, RED);
                        }
                        
                        if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{325, 700, 250, 150})){
                            DrawRectangle(325, 725, 250, 150, ORANGE);
                            DrawText("Bag", 350, 775, 50, WHITE);
                            
                        }else{
                            DrawRectangleLines(325, 700, 250, 150, ORANGE);
                            DrawText("Bag", 350, 750, 50, ORANGE);
                        }
                        
                        if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{600, 700, 250, 150})){
                            DrawRectangle(600, 725, 250, 150, GREEN);
                            DrawText("Pokemon", 625, 775, 50, WHITE);
                            if(IsMouseButtonPressed(0))PartyMenu = true;
                            
                        }else{
                            DrawRectangleLines(600, 700, 250, 150, GREEN);
                            DrawText("Pokemon", 625, 750, 50, GREEN);
                        }
                        
                        if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{875, 700, 250, 150})){
                            DrawRectangle(875, 725, 250, 150, BLUE);
                            DrawText("Run", 900, 775, 50, WHITE);
                            
                        }else{
                            DrawRectangleLines(875, 700, 250, 150, BLUE);
                            DrawText("Run", 900, 750, 50, BLUE);
                        }
                    }else{
                        //moves
                        if(CheckCollisionPointRec({GetMouseX(), GetMouseY()}, {50, 700, 250, 150})){
                            DrawRectangle(50, 725, 250, 150, WHITE);
                            DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 775, 50, BLACK);
                            if(IsMouseButtonPressed(0)){
                                 moveMenu = true;
                            }
                            
                        }else{
                            DrawRectangleLines(50, 700, 250, 150, WHITE);
                            DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 50, WHITE);
                        }
                        
                        
                        
                        if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{1200, 700, 250, 100})){
                     
                        DrawRectangle(1200, 725, 250, 100, RED);
                        DrawText("Cancel", 1240, 750, 50, WHITE);
                        if(IsMouseButtonPressed(0))moveMenu = false;
                        
                        }else{
                        DrawRectangleLines(1200, 700, 250, 100, RED);
                        DrawText("Cancel", 1240, 725, 50, RED);
                        
                        }  
                        
                        if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{1200, 700, 250, 100})){
                        
                        DrawRectangle(1200, 725, 250, 100, RED);
                        DrawText("Cancel", 1240, 750, 50, WHITE);
                        if(IsMouseButtonPressed(0))moveMenu = false;
                        
                        }else{
                        DrawRectangleLines(1200, 700, 250, 100, RED);
                        DrawText("Cancel", 1240, 725, 50, RED);
                        
                        }  
                    }
                    
                    
                    DrawTextureEx(HPboxP, {1025,475}, 0, 4.5, WHITE);
                    DrawTextureEx(HPboxE, {0,100}, 0, 5, WHITE);
                    
                    DrawRectangle(1349, 588,  lerp(0, 216, (float)party[activePKM]->health/(float)party[activePKM]->maxHealth), 13, GREEN);
                    
                    DrawText(party[activePKM]->name.c_str(), 1100,524, 50, BLACK);
                    std::string temp = std::to_string(party[activePKM]->health);
                    DrawText(temp.c_str(), 1325, 615, 40, BLACK);
                    std::string tempM = std::to_string(party[activePKM]->maxHealth);
                    DrawText(tempM.c_str(), 1465, 615, 40, BLACK);
                    
                    std::string tempL = std::to_string(party[activePKM]->level);
                    DrawText(tempL.c_str(), 1500, 524, 40, BLACK);
                    
                    DrawText(enemyTeam[activePKME]->name.c_str(), 20, 150, 50, BLACK);
                    
                    std::string tempLE = std::to_string(enemyTeam[activePKME]->level);
                    DrawText(tempLE.c_str(), 425, 153, 40, BLACK);
                    
                    DrawRectangle(250, 219,  lerp(0, 240, (float)enemyTeam[activePKME]->health/(float)enemyTeam[activePKME]->maxHealth), 16, GREEN);
                }else if(!moveMenu){
                    
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{100, 50, 500, 200})){
                        DrawRectangleRounded({100, 50, 500, 200}, 0.2, 0, BLACK);
                         if(party[0] != NULL)DrawText(party[0]->name.c_str(), 150, 75, 50, WHITE);
                         if(IsMouseButtonPressed(0)&& party[0] != NULL){
                             activePKM = 0;
                             PartyMenu = false;
                         }
                        
                    }else{
                        DrawRectangleRounded({100, 50, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[0] != NULL)DrawText(party[0]->name.c_str(), 150, 75, 50, DEFCOLOR(255,255,255,100));
                    }
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{100, 300, 500, 200})){
                        DrawRectangleRounded({100, 300, 500, 200}, 0.2, 0, BLACK);
                        if(party[1] != NULL)DrawText(party[1]->name.c_str(), 150, 325, 50, WHITE);
                        if(IsMouseButtonPressed(0) && party[1] != NULL){
                             activePKM = 1;
                             PartyMenu = false;
                         }
                    }else{
                        DrawRectangleRounded({100, 300, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[1] != NULL )DrawText(party[1]->name.c_str(), 150, 325, 50, DEFCOLOR(255,255,255,100));
                    }
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{100, 550, 500, 200})){
                        DrawRectangleRounded({100, 550, 500, 200}, 0.2, 0, BLACK);
                        if(party[2] != NULL)DrawText(party[2]->name.c_str(), 150, 575, 50, WHITE);
                        if(IsMouseButtonPressed(0) && party[2] != NULL){
                             activePKM = 2;
                             PartyMenu = false;
                         }
                    }else{
                        DrawRectangleRounded({100, 550, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[2] != NULL)DrawText(party[2]->name.c_str(), 150, 575, 50, DEFCOLOR(255,255,255,100));
                    }
                    
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()}, {700, 50, 500, 200})){
                        DrawRectangleRounded({700, 50, 500, 200}, 0.2, 0, BLACK);
                        if(party[3] != NULL)DrawText(party[3]->name.c_str(), 750, 75, 50, WHITE);
                        if(IsMouseButtonPressed(0) && party[3] != NULL){
                             activePKM = 3;
                             PartyMenu = false;
                         }
                    }else{
                        DrawRectangleRounded({700, 50, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[3] != NULL)DrawText(party[3]->name.c_str(), 750, 75, 50, DEFCOLOR(255,255,255,100));
                    }
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{700, 300, 500, 200})){
                        DrawRectangleRounded({700, 300, 500, 200}, 0.2, 0, BLACK);
                        if(party[4] != NULL)DrawText(party[4]->name.c_str(), 750, 325, 50, WHITE);
                        if(IsMouseButtonPressed(0)&& party[4] != NULL){
                             activePKM = 4;
                             PartyMenu = false;
                         }
                    }else{
                        DrawRectangleRounded({700, 300, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[4] != NULL)DrawText(party[4]->name.c_str(), 750, 325, 50,DEFCOLOR(255,255,255,100));
                    }
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{700, 550, 500, 200})){
                        DrawRectangleRounded({700, 550, 500, 200}, 0.2, 0, BLACK);
                        if(party[5] != NULL)DrawText(party[5]->name.c_str(), 750, 575, 50, WHITE);
                        if(IsMouseButtonPressed(0)&& party[5] != NULL){
                             activePKM = 5;
                             PartyMenu = false;
                         }
                    }else{
                        DrawRectangleRounded({700, 550, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[5] != NULL)DrawText(party[5]->name.c_str(), 750, 575, 50, DEFCOLOR(255,255,255,100));
                    }
                    
                    
                    
                    
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{100, 800, 200, 75})){
                        
                        DrawRectangle(100, 800, 200, 75, RED);
                        DrawText("Cancel", 110, 810, 50, WHITE);
                        if(IsMouseButtonPressed(0))PartyMenu = false;
                        
                    }else{
                       DrawRectangleLines(100, 800, 200, 75, RED);
                        DrawText("Cancel", 110, 810, 50, RED);
                        
                    }
                  

                }else{
                    
                }
            
                
            
          
           
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
