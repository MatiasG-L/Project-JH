#include "raylib.h"
#include "Move.h"
#pragma once
class Pokemon{
    public:
    
    int health;
    typedef struct{
        int HP;
        int Attack;
        int Defense;
        int SpAttack;
        int SpDefense;
        int speed;
    }Stats;
    
    Stats stats;
    
    int maxHealth;
    bool fainted;
    std::string name;
    std::string type;
    int level;
    int exp;
    int stage;
    Texture2D spriteFront;
    Texture2D spriteBack;
    typedef struct Moveset{
      Move *Move1;
      Move *Move2;
      Move *Move3;
      Move *Move4;
    }Moveset;
    Moveset moveset;
    int dexNum;
    
    Pokemon(int health, int maxHealth, std::string name, std::string type, int level, int exp, int stage, Texture2D spriteFront, Texture2D spriteBack, Moveset moveset, Stats stats){
        this->health = health;
        this->name = name;
        this->type = type;
        this->level = level;
        this->exp  = exp;
        this->stage = stage;
        this->spriteFront = spriteFront;
        this->spriteBack = spriteBack;
        this->moveset = moveset;
        this->maxHealth = maxHealth;
        this->stats = stats;
        fainted = false;
    }
    
    
};