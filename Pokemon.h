#include "raylib.h"
#include "Move.h"
class Pokemon{
    public:
    
    int health;
    std::string name;
    std::string type;
    int level;
    int exp;
    int stage;
    Texture2D spriteFront;
    Texture2D spriteBack;
    Move moveset[4];
    
    Pokemon(int health, std::string name, std::string type, int level, int exp, int stage, Texture2D spriteFront, Texture2D spriteBack, Move moveset[4]; ){
        
    }
    
    
};