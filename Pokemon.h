#include "raylib.h"
#include "Move.h"
#include "GetTypeMatchUp.cpp"
#pragma once
class Pokemon{
    public:
    
    int health;
    int maxHealth;
    typedef struct{
        int HP;
        int Attack;
        int Defense;
        int SpAttack;
        int SpDefense;
        int Speed;
    }Stats;
    
    Stats baseStats;
    Stats IV;
    Stats stats;
 
    bool fainted;
    std::string name;
    int type;
    int type2;
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
    
    Pokemon(std::string name, int type, int level, int exp, int stage, Texture2D spriteFront, Texture2D spriteBack, Moveset moveset, Stats baseStats){
        this->name = name;
        this->type = type;
        this->type2 = -1;
        this->level = level;
        this->exp  = exp;
        this->stage = stage;
        this->spriteFront = spriteFront;
        this->spriteBack = spriteBack;
        this->moveset = moveset;
        this->baseStats = baseStats;
        fainted = false;
        IV = {GetRandomValue(0,31),GetRandomValue(0,31),GetRandomValue(0,31),GetRandomValue(0,31),GetRandomValue(0,31),GetRandomValue(0,31)};
        stats.HP = (0.01 * (2*(float)baseStats.HP + (float)IV.HP) * (float)level) + (float)level + 10;
        stats.Attack = (0.01 * ((float)baseStats.Attack + (float)IV.Attack) * (float)level) + 5; 
        stats.Defense = (0.01 * ((float)baseStats.Defense + (float)IV.Defense) * (float)level) + 5;
        stats.SpAttack = (0.01 * ((float)baseStats.SpAttack + (float)IV.SpAttack) * (float)level) + 5;
        stats.SpDefense = (0.01 * ((float)baseStats.SpDefense + (float)IV.SpDefense) * (float)level) + 5;
        stats.Speed = (0.01 * ((float)baseStats.Speed + (float)IV.Speed) * (float)level) + 5;
        health = stats.HP;
    }
    Pokemon(std::string name, int type, int type2, int level, int exp, int stage, Texture2D spriteFront, Texture2D spriteBack, Moveset moveset, Stats baseStats){
        this->name = name;
        this->type = type;
        this->type2 = type2;
        this->level = level;
        this->exp  = exp;
        this->stage = stage;
        this->spriteFront = spriteFront;
        this->spriteBack = spriteBack;
        this->moveset = moveset;
        this->baseStats = baseStats;
        fainted = false;
        IV = {GetRandomValue(0,31),GetRandomValue(0,31),GetRandomValue(0,31),GetRandomValue(0,31),GetRandomValue(0,31),GetRandomValue(0,31)};
        stats.HP = (0.01 * (2*(float)baseStats.HP + (float)IV.HP) * (float)level) + (float)level + 10;
        stats.Attack = (0.01 * ((float)baseStats.Attack + (float)IV.Attack) * (float)level) + 5; 
        stats.Defense = (0.01 * ((float)baseStats.Defense + (float)IV.Defense) * (float)level) + 5;
        stats.SpAttack = (0.01 * ((float)baseStats.SpAttack + (float)IV.SpAttack) * (float)level) + 5;
        stats.SpDefense = (0.01 * ((float)baseStats.SpDefense + (float)IV.SpDefense) * (float)level) + 5;
        stats.Speed = (0.01 * ((float)baseStats.Speed + (float)IV.Speed) * (float)level) + 5;
        health = stats.HP;
    }
    
    void takeDamage(Move *move, Pokemon *poke){
        int base = (((float)(poke->level * 2)/5)+2) * (float)move->baseDmg;//calculates a base damage
        
        bool crit = false;
        if(GetRandomValue(0, 100) < 6.25){//determines a crit
            crit = true;
        }
        
        if(move->split == "Physical"){//calculates a new base damage after a special physical split
            base *= poke->stats.Attack;
            base = (float)base / (float)stats.Defense;
        }else if(move->split == "Special"){
            base *= poke->stats.SpAttack;
            base = (float)base / (float)stats.SpDefense;
        }
        base = (float)base / 50;
        base += 2;

        if(move->type == poke->type || move->type == poke->type2)base = (float)base * 1.5;// grants a same type attack bonus (stab)
        float typeBonus = 1;
        if(type2 != -1){
            typeBonus *= GetTypeMatchUp(move->type, type);
            typeBonus *= GetTypeMatchUp(move->type, type2);
        }else{
            typeBonus *= GetTypeMatchUp(move->type, type);
        }
        
        if(crit) base *= typeBonus * 2;
        base *= ((float)GetRandomValue(217, 255)/255);

        health -= base;
        std::cout << "\n" << base <<  "\n";
        move->pp -= 1;
        if(health <= 0){
            fainted = true;
            health = 0;
        }
    }
    
};