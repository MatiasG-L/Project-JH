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
#include <cmath>
#include <queue>

#include "raylib.h"
#include "Move.h"
#include "Pokemon.h"
#include "GetTypeMatchUp.cpp"
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
    #include "Pokedex.cpp"
    
    
    Texture2D baseE = LoadTexture("Assets/Battle Assets/Battle Base Grass Opp.png");
    Texture2D Background = LoadTexture("Assets/Battle Assets/Background Grass.png");
    Texture2D baseP = LoadTexture("Assets/Battle Assets/Battle Base Grass Ally.png");
    Texture2D HPboxP = LoadTexture("Assets/Battle Assets/PlayerHPBox.png");
    Texture2D HPboxE = LoadTexture("Assets/Battle Assets/EnemyHPBox.png");
    /*
    Pokemon constructer paramaters:
    (health, name,  type,  level,  exp,  stage, spriteFront,  spriteBack, *moveset[4], stats{})
    */
     
     int win = 0;
        
    //initializes camera values
    Camera2D camera = { 0 };
    camera.offset = {screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera.target = {800,450};
    
    bool PartyMenu = false;
    bool moveMenu = false;
    //moves turn is a array with 2 indexes movesTurn[0] is meant only for the player to store its selected move to be used movesTurn[1] if for the oponents pokemon
    Move *movesTurn[] = {NULL, NULL};
    bool turn;
    float bobTimer = 0;
    
    bool atkANM = false;
    bool atkANME= false;
    
    float timerATK = 0; 
    float timerATKE = 0;
    
    Vector2 pkmPos = {100,225};
    Vector2 pkmPosE = {1000,0};
    
    
    
    
    Pokemon *enemyTeam[6] = {new Pokemon(pokedex[GetRandomValue(0, std::size(pokedex)-1)]), new Pokemon(pokedex[GetRandomValue(0,std::size(pokedex)-1)]), new Pokemon(pokedex[GetRandomValue(0,std::size(pokedex)-1)]), NULL, NULL, NULL};
    Pokemon *party[6] = {new Pokemon(pokedex[GetRandomValue(0,std::size(pokedex)-1)]), new Pokemon(pokedex[GetRandomValue(0,std::size(pokedex)-1)]), new Pokemon(pokedex[GetRandomValue(0,std::size(pokedex)-1)]), NULL, NULL,NULL};
    
    int activePKM = 0;
    int activePKME = 0;
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    //determines turn order based on pokemon speed (although actual order of attack will be determined later on)
    if(party[activePKM]->stats.Speed > enemyTeam[activePKME]->stats.Speed){
        turn = true;
    }else{
        turn = false;
    }
    
    
    while (!WindowShouldClose()){    // Detect window close button or ESC key
    
    //cycles through your team to check if all pokemon have fainted if so win -1 leading to a loss
    int checkTeam = 0;
    for(int i = 0; i < 6; i++){
        if(party[i] == NULL || party[i]->fainted){
            checkTeam++;
        }
    }
    if(checkTeam == 6) win = -1;
    //upon your active pokemon fainting it forces the party menu open and cancels your attack animation and clears your move from the turn
    if(party[activePKM]->fainted){
        PartyMenu = true;
        atkANM = false;
        movesTurn[0] = NULL;
    }
    
    //upon your oponents pokemon fainting it forces the enemy into the pokemon of the next slot over not greater than 6 or until current slot +1 = NULL which ever comes sooner
    //if your oponents active pokemon in slot 6 (enemyTeam[5]) faints win 1 leading to a victory
    //Or if your oponents active pokemon faints and the next slot over is NULL win 1 leading to a victory
    //it cancels your oponents animation and clears their move upon fainting
    if(enemyTeam[activePKME]->fainted){
        if(activePKME != 5){
            if(enemyTeam[activePKME+1] != NULL){
                activePKME++;
                atkANM = false;
                movesTurn[0] = NULL;
            }else{
                win = 1;
            }
            
        }else{
            win = 1;
        }
    }
    
    
    //enemy turn
    if(!turn){
        //at times your oponents active pokemon may not have all 4 move slots filled in which case it cycles through for each slot != NULL it increments index
        //this allows the program to know how much moves the active pokemon has availible
        int index = 0;
        if(enemyTeam[activePKME]->moveset.Move1 != NULL){
           index++;
        }
        if(enemyTeam[activePKME]->moveset.Move2 != NULL){
           index++;
        }
        if(enemyTeam[activePKME]->moveset.Move3 != NULL){
           index++;
        }
        if(enemyTeam[activePKME]->moveset.Move4 != NULL){
           index++;
        }
        //given the number obtianed from indexing the move list the oponets active pokemons move is chosen at random from 1 (min) to a max determined by index as determined previously
        int moveNum = GetRandomValue(1,index);
        
        //the moveNum as determined earlier becomes the move the pokemon uses and this move gets put in movesTurn[1] which is the oponents designated index 
        //upon adding the selected move into its designated slot the turn is ended and control is handed to the player
        //(Please note the players move selection is located with the GUI code)
        //this only runs as long as no pokemon is attacking
        if(!atkANM && !atkANME){
           switch(moveNum){
            case 1:
                movesTurn[1] = enemyTeam[activePKME]->moveset.Move1;
                turn = true;
                break;
            case 2:
                movesTurn[1] = enemyTeam[activePKME]->moveset.Move2;
                turn = true;
                break;
            case 3:
                movesTurn[1] = enemyTeam[activePKME]->moveset.Move3;
                turn = true;
                break;
            case 4:
                movesTurn[1] = enemyTeam[activePKME]->moveset.Move4;
                turn = true;
                break;
            } 
        }
         
    }
    //once both slots of the movesTurn array are filled meaning the attacks to be used have been selected it determines who goes first 
    //checking move priority first and then pokemon speed 
    //once a pokemon is selected to go first their attack animation begins playing
      if(movesTurn[0] != NULL && movesTurn[1] != NULL && !atkANM && !atkANME){
          if(movesTurn[0]->priority > movesTurn[1]->priority){
              atkANM = true;

          }else if(movesTurn[0]->priority < movesTurn[1]->priority){
              atkANME = true;
          
          }else{
              if(party[activePKM]->stats.Speed > enemyTeam[activePKME]->stats.Speed){
                atkANM = true;

              }else{
                atkANME = true;

              }
          }
      }
      
      if(IsKeyPressed(KEY_BACKSPACE)) party[activePKM]->health -= 10;
        
        
            //timer in charge of timing the pokemons bob animation (up and down motion when idle)
            if(bobTimer < 0.3 && !atkANM){
                bobTimer += GetFrameTime();
            }else if(!atkANM){
                if(pkmPos.y == 225) pkmPos.y -= 5;
                else pkmPos.y += 5;
                bobTimer = 0;
            }
            //Player attack animation this is where the player deals damage to the enemy and when the player moves over to the enemy for its attack
            //upon completing this animation the delegated slot in the movesTurn array is set to NULL
            if(atkANM && !party[activePKM]->fainted){
                if(timerATK < 0.4){
                    timerATK += GetFrameTime();
                }else{
                    pkmPos = lerpV(pkmPos, pkmPosE, 0.1);
                    if(pkmPos.x > 900){
                        pkmPos = {100, 225};
                        atkANM = false;
                        enemyTeam[activePKME]->takeDamage(movesTurn[0], party[activePKM]);
                        movesTurn[0] = NULL;
                        //checks to see if the enemies slot in movesTurn is NULL if isnt this means the enemy is waiting to attack and it hands the control over to them
                        if(movesTurn[1] != NULL) atkANME = true;
                    }
                    
                } 
            }else if(atkANM && !party[activePKM]->fainted){
                atkANM = false;//safe gaurd to ensure a pokemon doesnt attack after fainting although likely redundant
            }
            //similar to the player attack animation this is where the enemy does damage to the player 
            //upon completion it clears its slot in movesTurn to NULL
             if(atkANME && !enemyTeam[activePKME]->fainted){
                if(timerATKE < 0.4){
                    timerATKE += GetFrameTime();
                }else{
                    pkmPosE = lerpV(pkmPosE, pkmPos, 0.1);
                    if(pkmPosE.x < 150){
                        pkmPosE = {1000, 0};
                        atkANME = false;
                        party[activePKM]->takeDamage(movesTurn[1], enemyTeam[activePKME]);
                        movesTurn[1] = NULL;
                        ////checks the players slot in movesTurn if it isnt NULL then the player is waiting to attack and it hands control over to the player
                        if(movesTurn[0] != NULL) atkANM = true;
                    }
                    
                } 
            }else if(atkANME && enemyTeam[activePKME]->fainted){
                atkANME = false;//safe gaurd to ensure a pokemon doesnt attack after fainting although likely redundant
            }
            
      
      // Draw, where the scene actually gets rendered and drawn out

      
        BeginDrawing();
            
            
            
            //anything drawn inside of the BeginMode2D() and EndMode2D() are going to be drawn onto the world and wont move with the camera but anything drawn after EndMode2D() is drawn onto the screen and moves with the camera useful for UI
                BeginMode2D(camera);
                
                if(PartyMenu)ClearBackground(GRAY);   
                else ClearBackground(WHITE);
                DrawTextureEx(Background, {0,0}, 0, 6.3, WHITE);

                
                EndMode2D();
                
                switch(win){
                    case 0:
                    if(!PartyMenu){
                    DrawTextureEx(baseE, {1000,325}, 0, 4.5, WHITE);
                    DrawTextureEx(baseP, {37,540}, 0, 4.5, WHITE);
                    
                    
                    DrawTextureEx(enemyTeam[activePKME]->spriteFront, pkmPosE, 0, 1, WHITE);
                    DrawTextureEx(party[activePKM]->spriteBack, pkmPos, 0, 1, WHITE);
                    
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
                             if(IsMouseButtonPressed(0))return 0;
                        }else{
                            DrawRectangleLines(875, 700, 250, 150, BLUE);
                            DrawText("Run", 900, 750, 50, BLUE);
                            
                        }
                    }else{
                        //move1
                        
                        if(party[activePKM]->moveset.Move1 != NULL && !atkANM && !atkANME){
                            if(CheckCollisionPointRec({GetMouseX(), GetMouseY()}, {50, 700, 250, 150})){
                                
                                switch(party[activePKM]->moveset.Move1->type){
                                    case Fire:{
                                        DrawRectangle(50, 725, 250, 150, RED);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 725, 30, ORANGE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move1->pp)+" / "+std::to_string(party[activePKM]->moveset.Move1->maxPP);
                                        DrawText(temp.c_str(), 75, 800, 25, ORANGE);
                                        break;
                                     }
                                     case Water:{
                                        DrawRectangle(50, 725, 250, 150, BLUE);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 725, 30, SKYBLUE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move1->pp)+" / "+std::to_string(party[activePKM]->moveset.Move1->maxPP);
                                        DrawText(temp.c_str(), 75, 800, 25, SKYBLUE);
                                        break;
                                     }
                                     case Normal:{
                                        DrawRectangle(50, 725, 250, 150, WHITE);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 725, 30, BLACK);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move1->pp)+" / "+std::to_string(party[activePKM]->moveset.Move1->maxPP);
                                        DrawText(temp.c_str(), 75, 800, 25, BLACK);
                                        break;
                                     }
                                     case Grass:{
                                        DrawRectangle(50, 725, 250, 150, GREEN);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 725, 30, LIME);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move1->pp)+" / "+std::to_string(party[activePKM]->moveset.Move1->maxPP);
                                        DrawText(temp.c_str(), 75, 800, 25, LIME);
                                        break;
                                     }
                                     case Poison:{
                                        DrawRectangle(50, 725, 250, 150, DARKPURPLE);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 725, 30, PURPLE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move1->pp)+" / "+std::to_string(party[activePKM]->moveset.Move1->maxPP);
                                        DrawText(temp.c_str(), 75, 800, 25, PURPLE);
                                        break;
                                     }
                                     case Dragon:{
                                        DrawRectangle(50, 725, 250, 150, ORANGE);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 725, 30, YELLOW);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move1->pp)+" / "+std::to_string(party[activePKM]->moveset.Move1->maxPP);
                                        DrawText(temp.c_str(), 75, 800, 25, YELLOW);
                                        break;
                                     }
                                     case Psychic:{
                                        DrawRectangle(50, 725, 250, 150, PINK);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move1->pp)+" / "+std::to_string(party[activePKM]->moveset.Move1->maxPP);
                                        DrawText(temp.c_str(), 75, 800, 25, WHITE);
                                        break;
                                     }
                                     case Dark:{
                                        DrawRectangle(50, 725, 250, 150, DARKBROWN);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 725, 30, BROWN);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move1->pp)+" / "+std::to_string(party[activePKM]->moveset.Move1->maxPP);
                                        DrawText(temp.c_str(), 75, 800, 25, BROWN);
                                        break;
                                     }
                                     case Flying:{
                                        DrawRectangle(50, 725, 250, 150, SKYBLUE);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move1->pp)+" / "+std::to_string(party[activePKM]->moveset.Move1->maxPP);
                                        DrawText(temp.c_str(), 75, 800, 25, BROWN);
                                        break;
                                     }
                                     case Electric:{
                                        DrawRectangle(50, 725, 250, 150, YELLOW);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move1->pp)+" / "+std::to_string(party[activePKM]->moveset.Move1->maxPP);
                                        DrawText(temp.c_str(), 75, 800, 25, BROWN);
                                        break;
                                     }
                                };
                                
                                
                                if(IsMouseButtonPressed(0) && party[activePKM]->moveset.Move1->pp > 0){
                                     movesTurn[0] = party[activePKM]->moveset.Move1; 
                                     //enemyTeam[activePKME]->takeDamage(party[activePKM]->moveset.Move1, party[activePKM]);
                                     moveMenu = false;
                                     turn = false;
                                }
                                
                            }else{
                                
                                
                                switch(party[activePKM]->moveset.Move1->type){
                                    
                                    case Fire:
                                        DrawRectangleLines(50, 700, 250, 150, RED);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 30, ORANGE);
                                        break;
                                    case Water:
                                        DrawRectangleLines(50, 700, 250, 150, BLUE);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 30, BLUE);
                                        break;
                                    case Normal:
                                        DrawRectangleLines(50, 700, 250, 150, WHITE);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 30, WHITE);
                                        break;
                                    case Grass:
                                        DrawRectangleLines(50, 700, 250, 150, GREEN);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 30, GREEN);
                                        break;
                                    case Poison:
                                        DrawRectangleLines(50, 700, 250, 150, DARKPURPLE);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 30, DARKPURPLE);
                                        break;
                                    case Dragon:
                                        DrawRectangleLines(50, 700, 250, 150, ORANGE);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 30, YELLOW);
                                        break;
                                    case Psychic:
                                        DrawRectangleLines(50, 700, 250, 150, PINK);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 30, PINK);
                                        break;
                                    case Dark:
                                        DrawRectangleLines(50, 700, 250, 150, DARKBROWN);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 30, DARKBROWN);
                                        break;
                                        
                                    case Flying:
                                        DrawRectangleLines(50, 700, 250, 150, SKYBLUE);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 30, SKYBLUE);
                                        break;
                                    case Electric:
                                        DrawRectangleLines(50, 700, 250, 150, YELLOW);
                                        DrawText(party[activePKM]->moveset.Move1->name.c_str(), 75, 750, 30, YELLOW);
                                        break;
                                    
                                };
                                            
                            }
                        }
                        
                        //move2
                        if(party[activePKM]->moveset.Move2 != NULL&& !atkANM && !atkANME){
                            if(CheckCollisionPointRec({GetMouseX(), GetMouseY()}, {325, 700, 250, 150})){
                                
                                switch(party[activePKM]->moveset.Move2->type){
                                    
                                    case Fire:{
                                        DrawRectangle(325, 725, 250, 150, RED);
                                
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 325, 725, 30, ORANGE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move2->pp)+" / "+std::to_string(party[activePKM]->moveset.Move2->maxPP);
                                        DrawText(temp.c_str(), 350, 800, 25, ORANGE);
                                        break;
                                    }
                                    case Water:{
                                        DrawRectangle(325, 725, 250, 150, BLUE);
                                
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 725, 30, SKYBLUE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move2->pp)+" / "+std::to_string(party[activePKM]->moveset.Move2->maxPP);
                                        DrawText(temp.c_str(), 350, 800, 25, SKYBLUE);
                                        break;
                                    }
                                    case Normal:{
                                         DrawRectangle(325, 725, 250, 150, WHITE);
                                
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 725, 30, BLACK);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move2->pp)+" / "+std::to_string(party[activePKM]->moveset.Move2->maxPP);
                                        DrawText(temp.c_str(), 350, 800, 25, BLACK);
                                        break;
                                    }
                                    case Grass:{
                                        DrawRectangle(325, 725, 250, 150, GREEN);
                                
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 725, 30, LIME);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move2->pp)+" / "+std::to_string(party[activePKM]->moveset.Move2->maxPP);
                                        DrawText(temp.c_str(), 350, 800, 25, LIME);
                                        break;
                                    }
                                    case Poison:{
                                        DrawRectangle(325, 725, 250, 150, DARKPURPLE);
                                
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 725, 30, PURPLE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move2->pp)+" / "+std::to_string(party[activePKM]->moveset.Move2->maxPP);
                                        DrawText(temp.c_str(), 350, 800, 25, PURPLE);
                                        break;
                                    }
                                    case Dragon:{
                                         DrawRectangle(325, 725, 250, 150, ORANGE);
                                
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 725, 30, YELLOW);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move2->pp)+" / "+std::to_string(party[activePKM]->moveset.Move2->maxPP);
                                        DrawText(temp.c_str(), 350, 800, 25, YELLOW);
                                        break;
                                    }
                                    case Psychic:{
                                         DrawRectangle(325, 725, 250, 150, PINK);
                                
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move2->pp)+" / "+std::to_string(party[activePKM]->moveset.Move2->maxPP);
                                        DrawText(temp.c_str(), 350, 800, 25, WHITE);
                                        break;
                                    }
                                    case Dark:{
                                        DrawRectangle(325, 725, 250, 150, DARKBROWN);
                                
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 725, 30, BROWN);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move2->pp)+" / "+std::to_string(party[activePKM]->moveset.Move2->maxPP);
                                        DrawText(temp.c_str(), 350, 800, 25, BROWN);
                                        break;
                                    }
                                    case Flying:{
                                        DrawRectangle(325, 725, 250, 150, SKYBLUE);
                                
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move2->pp)+" / "+std::to_string(party[activePKM]->moveset.Move2->maxPP);
                                        DrawText(temp.c_str(), 350, 800, 25, BROWN);
                                        break;
                                    } 
                                    case Electric:{
                                        DrawRectangle(325, 725, 250, 150, YELLOW);
                                
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move2->pp)+" / "+std::to_string(party[activePKM]->moveset.Move2->maxPP);
                                        DrawText(temp.c_str(), 350, 800, 25, BROWN);
                                        break;
                                    }
                                    
                                };
                                
                                
                                if(IsMouseButtonPressed(0) && party[activePKM]->moveset.Move2->pp > 0){
                                     //enemyTeam[activePKME]->takeDamage(party[activePKM]->moveset.Move2, party[activePKM]);
                                     movesTurn[0] = party[activePKM]->moveset.Move2; 
                                     moveMenu = false;
                                     turn = false;
                                }
                                
                            }else{
                                
                                
                                switch(party[activePKM]->moveset.Move2->type){
                                    
                                    case Fire:
                                        DrawRectangleLines(325, 700, 250, 150, RED);
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 750, 30, ORANGE);
                                        break;
                                    case Water:
                                        DrawRectangleLines(325, 700, 250, 150, BLUE);
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 750, 30, BLUE);
                                        break;
                                    case Normal:
                                        DrawRectangleLines(325, 700, 250, 150, WHITE);
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 750, 30, WHITE);
                                        break;
                                    case Grass:
                                        DrawRectangleLines(325, 700, 250, 150, GREEN);
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 750, 30, GREEN);
                                        break;
                                    case Poison:
                                        DrawRectangleLines(325, 700, 250, 150, DARKPURPLE);
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 750, 30, DARKPURPLE);
                                        break;
                                    case Dragon:
                                        DrawRectangleLines(325, 700, 250, 150, ORANGE);
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 750, 30, YELLOW);
                                        break;
                                    case Psychic:
                                        DrawRectangleLines(325, 700, 250, 150, PINK);
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 750, 30, PINK);
                                        break;
                                    case Dark:
                                        DrawRectangleLines(325, 700, 250, 150, DARKBROWN);
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 750, 30, DARKBROWN);
                                        break;
                                    case Flying:
                                        DrawRectangleLines(325, 700, 250, 150, SKYBLUE);
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 750, 30, SKYBLUE);
                                        break;
                                    case Electric:
                                        DrawRectangleLines(325, 700, 250, 150, YELLOW);
                                        DrawText(party[activePKM]->moveset.Move2->name.c_str(), 350, 750, 30, YELLOW);
                                        break;
                                };                                
                                
                              }
                            }
                            
                            //move3
                        if(party[activePKM]->moveset.Move3 != NULL&& !atkANM && !atkANME){
                            if(CheckCollisionPointRec({GetMouseX(), GetMouseY()}, {600, 700, 250, 150})){
                                

                                switch(party[activePKM]->moveset.Move3->type){
                                    
                                    case Fire:{
                                        DrawRectangle(600, 725, 250, 150, RED);
                                
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 725, 30, ORANGE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move3->pp)+" / "+std::to_string(party[activePKM]->moveset.Move3->maxPP);
                                        DrawText(temp.c_str(), 625, 800, 25, ORANGE);
                                        break;
                                    }
                                    case Water:{
                                        DrawRectangle(600, 725, 250, 150, BLUE);
                                
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 725, 30, SKYBLUE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move3->pp)+" / "+std::to_string(party[activePKM]->moveset.Move3->maxPP);
                                        DrawText(temp.c_str(), 625, 800, 25, SKYBLUE);
                                        break;
                                    }    
                                    case Normal:{
                                         DrawRectangle(600, 725, 250, 150, WHITE);
                                
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 725, 30, BLACK);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move3->pp)+" / "+std::to_string(party[activePKM]->moveset.Move3->maxPP);
                                        DrawText(temp.c_str(), 625, 800, 25, BLACK);
                                        break;
                                    }
                                    case Grass:{
                                        DrawRectangle(600, 725, 250, 150, GREEN);
                                
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 725, 30, LIME);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move3->pp)+" / "+std::to_string(party[activePKM]->moveset.Move3->maxPP);
                                        DrawText(temp.c_str(), 625, 800, 25, LIME);
                                        break;
                                    }
                                    case Poison:{
                                        DrawRectangle(600, 725, 250, 150, DARKPURPLE);
                                
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 725, 30, PURPLE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move3->pp)+" / "+std::to_string(party[activePKM]->moveset.Move3->maxPP);
                                        DrawText(temp.c_str(), 625, 800, 25, PURPLE);
                                        break;
                                    }
                                    case Dragon:{
                                         DrawRectangle(600, 725, 250, 150, ORANGE);
                                
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 725, 30, YELLOW);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move3->pp)+" / "+std::to_string(party[activePKM]->moveset.Move3->maxPP);
                                        DrawText(temp.c_str(), 625, 800, 25, YELLOW);
                                        break;
                                    }
                                    case Psychic:{
                                         DrawRectangle(600, 725, 250, 150, PINK);
                                
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move3->pp)+" / "+std::to_string(party[activePKM]->moveset.Move3->maxPP);
                                        DrawText(temp.c_str(), 625, 800, 25, WHITE);
                                        break;
                                    }
                                    case Dark:{
                                        DrawRectangle(600, 725, 250, 150, DARKBROWN);
                                
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 725, 30, BROWN);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move3->pp)+" / "+std::to_string(party[activePKM]->moveset.Move3->maxPP);
                                        DrawText(temp.c_str(), 625, 800, 25, BROWN);
                                        break;
                                    }
                                    case Flying:{
                                        DrawRectangle(600, 725, 250, 150, SKYBLUE);
                                
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move3->pp)+" / "+std::to_string(party[activePKM]->moveset.Move3->maxPP);
                                        DrawText(temp.c_str(), 625, 800, 25, BROWN);
                                        break;
                                    }
                                    case Electric:{
                                        DrawRectangle(600, 725, 250, 150, YELLOW);
                                
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move3->pp)+" / "+std::to_string(party[activePKM]->moveset.Move3->maxPP);
                                        DrawText(temp.c_str(), 625, 800, 25, BROWN);
                                        break;
                                    }
                                };
                                
                                if(IsMouseButtonPressed(0)  && party[activePKM]->moveset.Move3->pp > 0){
                                     //enemyTeam[activePKME]->takeDamage(party[activePKM]->moveset.Move3, party[activePKM]);
                                     movesTurn[0] = party[activePKM]->moveset.Move3; 
                                     moveMenu = false;
                                     turn = false;
                                }
                                
                            }else{
                                
                                
                                 switch(party[activePKM]->moveset.Move3->type){
                                    
                                    case Fire:
                                        DrawRectangleLines(600, 700, 250, 150, RED);
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 750, 30, ORANGE);
                                        break;
                                    case Water:
                                        DrawRectangleLines(600, 700, 250, 150, BLUE);
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 750, 30, BLUE);
                                        break;
                                    case Normal:
                                        DrawRectangleLines(600, 700, 250, 150, WHITE);
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 750, 30, WHITE);
                                        break;
                                    case Grass:
                                        DrawRectangleLines(600, 700, 250, 150, GREEN);
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 750, 30, GREEN);
                                        break;
                                    case Poison:
                                        DrawRectangleLines(600, 700, 250, 150, DARKPURPLE);
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 750, 30, DARKPURPLE);
                                        break;
                                    case Dragon:
                                        DrawRectangleLines(600, 700, 250, 150, ORANGE);
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 750, 30, YELLOW);
                                        break;
                                    case Psychic:
                                        DrawRectangleLines(600, 700, 250, 150, PINK);
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 750, 30, PINK);
                                        break;
                                    case Dark:
                                        DrawRectangleLines(600, 700, 250, 150, DARKBROWN);
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 750, 30, DARKBROWN);
                                        break;
                                    case Flying:
                                        DrawRectangleLines(600, 700, 250, 150, SKYBLUE);
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 750, 30, SKYBLUE);
                                        break;
                                    case Electric:
                                        DrawRectangleLines(600, 700, 250, 150, YELLOW);
                                        DrawText(party[activePKM]->moveset.Move3->name.c_str(), 625, 750, 30, YELLOW);
                                        break;
                                    
                                };
                                
                                
                            }
                            }
                            
                            
                            
                            //move4
                            if(party[activePKM]->moveset.Move4 != NULL&& !atkANM && !atkANME){
                            if(CheckCollisionPointRec({GetMouseX(), GetMouseY()}, {875, 700, 250, 150})){
                                

                                switch(party[activePKM]->moveset.Move4->type){
                                    
                                    case Fire:{
                                        DrawRectangle(875, 725, 250, 150, RED);
                                
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 725, 30, ORANGE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move4->pp)+" / "+std::to_string(party[activePKM]->moveset.Move4->maxPP);
                                        DrawText(temp.c_str(), 900, 800, 25, ORANGE);
                                        break;
                                    }
                                    case Water:{
                                        DrawRectangle(875, 725, 250, 150, BLUE);
                                
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 725, 30, SKYBLUE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move4->pp)+" / "+std::to_string(party[activePKM]->moveset.Move4->maxPP);
                                        DrawText(temp.c_str(), 900, 800, 25, SKYBLUE);
                                        break;
                                    }
                                    case Normal:{
                                         DrawRectangle(875, 725, 250, 150, WHITE);
                                
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 725, 30, BLACK);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move4->pp)+" / "+std::to_string(party[activePKM]->moveset.Move4->maxPP);
                                        DrawText(temp.c_str(), 900, 800, 25, BLACK);
                                        break;
                                    }
                                    case Grass:{
                                        DrawRectangle(875, 725, 250, 150, GREEN);
                                
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 725, 30, LIME);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move4->pp)+" / "+std::to_string(party[activePKM]->moveset.Move4->maxPP);
                                        DrawText(temp.c_str(), 900, 800, 25, LIME);
                                        break;
                                    }
                                    case Poison:{
                                        DrawRectangle(875, 725, 250, 150, DARKPURPLE);
                                
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 725, 30, PURPLE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move4->pp)+" / "+std::to_string(party[activePKM]->moveset.Move4->maxPP);
                                        DrawText(temp.c_str(), 900, 800, 25, PURPLE);
                                        break;
                                    }
                                    case Dragon:{
                                         DrawRectangle(875, 725, 250, 150, ORANGE);
                                
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 725, 30, YELLOW);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move4->pp)+" / "+std::to_string(party[activePKM]->moveset.Move4->maxPP);
                                        DrawText(temp.c_str(), 900, 800, 25, YELLOW);
                                        break;
                                    }
                                    case Psychic:{
                                         DrawRectangle(875, 725, 250, 150, PINK);
                                
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move4->pp)+" / "+std::to_string(party[activePKM]->moveset.Move4->maxPP);
                                        DrawText(temp.c_str(), 900, 800, 25, WHITE);
                                        break;
                                    }
                                    case Dark:{
                                        DrawRectangle(875, 725, 250, 150, DARKBROWN);
                                
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 725, 30, BROWN);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move4->pp)+" / "+std::to_string(party[activePKM]->moveset.Move4->maxPP);
                                        DrawText(temp.c_str(), 900, 800, 25, BROWN);
                                        break;
                                    }
                                    case Flying:{
                                        DrawRectangle(875, 725, 250, 150, SKYBLUE);
                                
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move4->pp)+" / "+std::to_string(party[activePKM]->moveset.Move4->maxPP);
                                        DrawText(temp.c_str(), 900, 800, 25, BROWN);
                                        break;
                                    }
                                    case Electric:{
                                        DrawRectangle(875, 725, 250, 150, YELLOW);
                                
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 725, 30, WHITE);
                                        std::string temp = "PP: "+std::to_string(party[activePKM]->moveset.Move4->pp)+" / "+std::to_string(party[activePKM]->moveset.Move4->maxPP);
                                        DrawText(temp.c_str(), 900, 800, 25, BROWN);
                                        break;
                                    }
                                    
                                };
                                
                                if(IsMouseButtonPressed(0) && party[activePKM]->moveset.Move4->pp > 0){
                                     //enemyTeam[activePKME]->takeDamage(party[activePKM]->moveset.Move4, party[activePKM]);
                                     movesTurn[0] = party[activePKM]->moveset.Move4; 
                                     moveMenu = false;
                                     turn = false;
                                }
                                
                            }else{
                                
                                
                                switch(party[activePKM]->moveset.Move4->type){
                                    
                                    case Fire:
                                        DrawRectangleLines(875, 700, 250, 150, RED);
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 750, 30, ORANGE);
                                        break;
                                    case Water:
                                        DrawRectangleLines(875, 700, 250, 150, BLUE);
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 750, 30, BLUE);
                                        break;
                                    case Normal:
                                        DrawRectangleLines(875, 700, 250, 150, WHITE);
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 750, 30, WHITE);
                                        break;
                                    case Grass:
                                        DrawRectangleLines(875, 700, 250, 150, GREEN);
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 750, 30, GREEN);
                                        break;
                                    case Poison:
                                        DrawRectangleLines(875, 700, 250, 150, DARKPURPLE);
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 750, 30, DARKPURPLE);
                                        break;
                                    case Dragon:
                                        DrawRectangleLines(875, 700, 250, 150, ORANGE);
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 750, 30, YELLOW);
                                        break;
                                    case Psychic:
                                        DrawRectangleLines(875, 700, 250, 150, PINK);
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 750, 30, PINK);
                                        break;
                                    case Dark:
                                        DrawRectangleLines(875, 700, 250, 150, DARKBROWN);
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 750, 30, DARKBROWN);
                                        break;
                                    case Flying:
                                        DrawRectangleLines(875, 700, 250, 150, SKYBLUE);
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 750, 30, SKYBLUE);
                                        break;
                                    case Electric:
                                        DrawRectangleLines(875, 700, 250, 150, YELLOW);
                                        DrawText(party[activePKM]->moveset.Move4->name.c_str(), 900, 750, 30, YELLOW);
                                        break;
                                    
                                };
                                
                                
                            }
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
                    
                    DrawRectangle(1349, 588,  lerp(0, 216, (float)party[activePKM]->health/(float)party[activePKM]->stats.HP), 13, GREEN);
                    
                    DrawText(party[activePKM]->name.c_str(), 1100,524, 50, BLACK);
                    std::string temp = std::to_string(party[activePKM]->health);
                    DrawText(temp.c_str(), 1325, 615, 40, BLACK);
                    std::string tempM = std::to_string(party[activePKM]->stats.HP);
                    DrawText(tempM.c_str(), 1465, 615, 40, BLACK);
                    
                    std::string tempL = std::to_string(party[activePKM]->level);
                    DrawText(tempL.c_str(), 1500, 524, 40, BLACK);
                    
                    DrawText(enemyTeam[activePKME]->name.c_str(), 20, 150, 50, BLACK);
                    
                    std::string tempLE = std::to_string(enemyTeam[activePKME]->level);
                    DrawText(tempLE.c_str(), 425, 153, 40, BLACK);
                    
                    DrawRectangle(250, 219,  lerp(0, 240, (float)enemyTeam[activePKME]->health/(float)enemyTeam[activePKME]->stats.HP), 16, GREEN);
                }else if(!moveMenu){
                    
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{100, 50, 500, 200})){
                        DrawRectangleRounded({100, 50, 500, 200}, 0.2, 0, BLACK);
                         if(party[0] != NULL&& !party[0]->fainted)DrawText(party[0]->name.c_str(), 150, 75, 50, WHITE);
                         else if(party[0] != NULL && party[0]->fainted)DrawText(party[0]->name.c_str(), 150, 75, 50, RED);
                         if(IsMouseButtonPressed(0)&& party[0] != NULL && !party[0]->fainted){
                             activePKM = 0;
                             PartyMenu = false;
                             turn = false;
                         }
                        
                    }else{
                        DrawRectangleRounded({100, 50, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[0] != NULL)DrawText(party[0]->name.c_str(), 150, 75, 50, DEFCOLOR(255,255,255,100));
                    }
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{100, 300, 500, 200})){
                        DrawRectangleRounded({100, 300, 500, 200}, 0.2, 0, BLACK);
                        if(party[1] != NULL&& !party[1]->fainted)DrawText(party[1]->name.c_str(), 150, 325, 50, WHITE);
                        else if(party[1] != NULL && party[1]->fainted)DrawText(party[1]->name.c_str(), 150, 325, 50, RED);
                        if(IsMouseButtonPressed(0) && party[1] != NULL && !party[1]->fainted){
                             activePKM = 1;
                             PartyMenu = false;
                             turn = false;
                         }
                    }else{
                        DrawRectangleRounded({100, 300, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[1] != NULL )DrawText(party[1]->name.c_str(), 150, 325, 50, DEFCOLOR(255,255,255,100));
                    }
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{100, 550, 500, 200})){
                        DrawRectangleRounded({100, 550, 500, 200}, 0.2, 0, BLACK);
                        if(party[2] != NULL&& !party[2]->fainted)DrawText(party[2]->name.c_str(), 150, 575, 50, WHITE);
                        else if(party[2] != NULL && party[2]->fainted)DrawText(party[2]->name.c_str(), 150, 575, 50, RED);
                        if(IsMouseButtonPressed(0) && party[2] != NULL && !party[2]->fainted){
                             activePKM = 2;
                             PartyMenu = false;
                             turn = false;
                         }
                    }else{
                        DrawRectangleRounded({100, 550, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[2] != NULL)DrawText(party[2]->name.c_str(), 150, 575, 50, DEFCOLOR(255,255,255,100));
                    }
                    
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()}, {700, 50, 500, 200})){
                        DrawRectangleRounded({700, 50, 500, 200}, 0.2, 0, BLACK);
                        if(party[3] != NULL && party[3]->fainted)DrawText(party[3]->name.c_str(), 750, 75, 50, WHITE);
                        else if(party[3] != NULL && party[3]->fainted)DrawText(party[3]->name.c_str(), 750, 75, 50, RED);
                        if(IsMouseButtonPressed(0) && party[3] != NULL && !party[3]->fainted){
                             activePKM = 3;
                             PartyMenu = false;
                             turn = false;
                         }
                    }else{
                        DrawRectangleRounded({700, 50, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[3] != NULL)DrawText(party[3]->name.c_str(), 750, 75, 50, DEFCOLOR(255,255,255,100));
                    }
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{700, 300, 500, 200})){
                        DrawRectangleRounded({700, 300, 500, 200}, 0.2, 0, BLACK);
                        if(party[4] != NULL&& !party[4]->fainted)DrawText(party[4]->name.c_str(), 750, 325, 50, WHITE);
                        else if(party[4] != NULL && party[4]->fainted)DrawText(party[4]->name.c_str(), 750, 325, 50, RED);
                        if(IsMouseButtonPressed(0)&& party[4] != NULL && !party[4]->fainted){
                             activePKM = 4;
                             PartyMenu = false;
                             turn = false;
                         }
                    }else{
                        DrawRectangleRounded({700, 300, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[4] != NULL)DrawText(party[4]->name.c_str(), 750, 325, 50,DEFCOLOR(255,255,255,100));
                    }
                    
                    if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{700, 550, 500, 200})){
                        DrawRectangleRounded({700, 550, 500, 200}, 0.2, 0, BLACK);
                        if(party[5] != NULL&& !party[5]->fainted)DrawText(party[5]->name.c_str(), 750, 575, 50, WHITE);
                        else if(party[5] != NULL && party[5]->fainted)DrawText(party[5]->name.c_str(), 750, 575, 50, RED);
                        if(IsMouseButtonPressed(0)&& party[5] != NULL && !party[5]->fainted){
                             activePKM = 5;
                             PartyMenu = false;
                             turn = false;
                         }
                    }else{
                        DrawRectangleRounded({700, 550, 500, 200}, 0.2, 0, DEFCOLOR(0,0,0,100));
                        if(party[5] != NULL)DrawText(party[5]->name.c_str(), 750, 575, 50, DEFCOLOR(255,255,255,100));
                    }
                    
                    
                    
                    
                    if(!party[activePKM]->fainted){
                        if(CheckCollisionPointRec({GetMouseX(), GetMouseY()},{100, 800, 200, 75})){
                            
                            DrawRectangle(100, 800, 200, 75, RED);
                            DrawText("Cancel", 110, 810, 50, WHITE);
                            if(IsMouseButtonPressed(0))PartyMenu = false;
                            
                        }else{
                           DrawRectangleLines(100, 800, 200, 75, RED);
                            DrawText("Cancel", 110, 810, 50, RED);
                            
                        }
                    }
                  

                    }else{
                    
                    }
                    
                    break;
                    
                    case -1:
                    DrawText("YOU LOSE PRESS SPACE TO CLOSE", 0, 0, 200, RED);
                    if(IsKeyPressed(KEY_SPACE))return -1;
                    break;
                    case 1:
                    DrawText("YOU WIN PRESS SPACE TO CLOSE", 0, 0, 50, GREEN);
                    if(IsKeyPressed(KEY_SPACE))return 1;
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
