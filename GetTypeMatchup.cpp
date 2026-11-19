#pragma once
#include <string>

enum Type{
    Water = 1,  // 1
    Fire,       // 2
    Grass,      // 3
    Psychic,    // 4
    Dragon,     // 5
    Dark,       // 6
    Poison,     // 7
    Rock,       // 8
    Normal,     // 9
    Steel,      // 10
    Ground,     // 11
    Ice,        // 12
    Ghost,      // 13
    Flying,     // 14
    Fighting,   // 15
    Fairy,      // 16
    Electric,   // 17
    Bug         // 18
};

float GetTypeMatchUp(int type1, int type2){
    switch(type1){
        case Water:
            if(type2 == Fire || type2 == Ground || type2 == Rock){
                return 2; //effective
            }else if(type2 == Water || type2 == Grass || type2 == Dragon){
                return 0.5; //resistant
            }else return 1; //neutral
        /*-----------------------------------------------------------------------------*/
        case Fire:
            if(type2 == Grass || type2 == Ice || type2 == Bug || type2 == Steel){
                return 2; //effective
            }else if(type2 == Fire || type2 == Water || type2 == Rock || type2 == Dragon){
                return 0.5; //resistant
            }else return 1; //neutral
        /*-----------------------------------------------------------------------------*/
        case Grass:
            if(type2 == Water || type2 == Ground || type2 == Rock){
                return 2; //effective
            }else if(type2 == Fire || type2 == Grass || type2 == Poison || type2 == Flying || type2 == Bug || type2 == Dragon || type2 == Steel){
                return 0.5; //resistant
            }else return 1; //neutral
        /*-----------------------------------------------------------------------------*/
        case Psychic:
            if(type2 == Fighting || type2 == Poison){
                return 2; //effective
            }else if(type2 == Psychic || type2 == Steel){
                return 0.5; //resistant
            }else if(type2 == Dark){
                return 0; //No Effect
            }else return 1; //neutral
        /*-----------------------------------------------------------------------------*/
        case Dragon:
            if(type2 == Dragon){
                return 2; //effective
            }else if(type2 == Steel){
                return 0.5; //resistant
            }else if(type2 == Fairy){
                return 0; //No Effect
            }else return 1; //neutral
        /*-----------------------------------------------------------------------------*/
        case Dark:
            if(type2 == Psychic || type2 == Ghost){
                return 2; //effective
            }else if(type2 == Fighting || type2 == Dark || type2 == Fairy){
                return 0.5; //resistant
            }else return 1; //neutral
        /*-----------------------------------------------------------------------------*/
        case Poison:
            if(type2 == Grass || type2 == Fairy){
                return 2; //effective
            }else if(type2 == Poison || type2 == Rock || type2 == Ground || type2 == Ghost){
                return 0.5; //resistant
            }else if(type2 == Steel){
                return 0; //No Effect
            }else return 1; //neutral
        /*-----------------------------------------------------------------------------*/
        case Normal:
            if(type2 == 99){
                return 2; //effective
            }else if(type2 == Rock || type2 == Steel){
                return 0.5; //resistant
            }else if(type2 == Ghost){
                return 0; //No Effect
            }else return 1; //neutral
        /*-----------------------------------------------------------------------------*/
        case Electric:
            if(type2 == Water || type2 == Flying){
                return 2; //effective
            }else if(type2 == Electric || type2 == Dragon || type2 == Grass){
                return 0.5; //resistant
            }else if(type2 == Ground){
                return 0; //No Effect
            }else return 1; //neutral
        /*-----------------------------------------------------------------------------*/
        case Ice:
            if(type2 == Grass || type2 == Ground || type2 == Flying || type2 == Dragon){
                return 2; //effective
            }else if(type2 == Water || type2 == Ice || type2 == Steel || type2 == Fire){
                return 0.5; //resistant
            }else return 1; //neutral
        /*-----------------------------------------------------------------------------*/
        case Fighting:
            if(type2 == Normal || type2 == Ice || type2 == Rock || type2 == Dark || type2 == Steel){
                return 2; //effective
            }else if(type2 == Poison || type2 == Flying || type2 == Psychic || type2 == Bug || type2 == Fairy){
                return 0.5; //resistant
            }else if(type2 == Ghost){
                return 0; //No Effect
            }else return 1; //neutral
         /*-----------------------------------------------------------------------------*/
         case Ground:
            if(type2 == Fire || type2 == Electric || type2 == Poison || type2 == Rock || type2 == Steel){
                return 2; //effective
            }else if(type2 == Grass || type2 == Bug){
                return 0.5; //resistant
            }else if(type2 == Flying){
                return 0; //No Effect
            }else return 1; //neutral
         /*-----------------------------------------------------------------------------*/
         case Flying:
            if(type2 == Grass || type2 == Fighting || type2 == Bug){
                return 2; //effective
            }else if(type2 == Electric || type2 == Steel || type2 == Rock){
                return 0.5; //resistant
            }else return 1; //neutral
         /*-----------------------------------------------------------------------------*/
         case Bug:
            if(type2 == Grass || type2 == Psychic || type2 == Dark){
                return 2; //effective
            }else if(type2 == Fire || type2 == Fighting || type2 == Poison || type2 == Flying || type2 == Ghost || type2 == Steel || type2 == Fairy){
                return 0.5; //resistant
            }else return 1; //neutral
         /*-----------------------------------------------------------------------------*/
         case Rock:
            if(type2 == Fire || type2 == Ice || type2 == Flying || type2 == Bug){
                return 2; //effective
            }else if(type2 == Ground || type2 == Fighting || type2 == Steel){
                return 0.5; //resistant
            }else return 1; //neutral
         /*-----------------------------------------------------------------------------*/
         case Ghost:
            if(type2 == Psychic || type2 == Ghost){
                return 2; //effective
            }else if(type2 == Dark){
                return 0.5; //resistant
            }else if(type2 == Normal){
                return 0; //No Effect
            }else return 1; //neutral
         /*-----------------------------------------------------------------------------*/
         case Steel:
            if(type2 == Ice || type2 == Rock || type2 == Fairy){
                return 2; //effective
            }else if(type2 == Fire || type2 == Water || type2 == Electric || type2 == Steel){
                return 0.5; //resistant
            }else return 1; //neutral
            
    };
}