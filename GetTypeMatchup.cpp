#include <string>

float GetTypeMatchUp(std::string type1, std::string type2){
    if(type1 == "Water"){
        if(type2 == "Fire" || type2 == "Ground" || type2 == "Rock"){
            return 2;
        }else if(type2 == "Water" || type2 == "Grass" || type2 == "Dragon"){
            return 0.5;
        }else return 1;
    }else if(type1 == "Fire"){
        if(type2 == "Grass" || type2 == "Ice" || type2 == "Bug" || type2 == "Steel"){
            return 2;
        }else if(type2 == "Fire" || type2 == "Water" || type2 == "Rock" || type2 == "Dragon"){
            return 0.5;
        }else return 1;
    }else if(type1 == "Grass"){
        if(type2 == "Water" || type2 == "Ground" || type2 == "Rock"){
            return 2;
        }else if(type2 == "Fire" || type2 == "Grass" || type2 == "Poison" || type2 == "Flying" || type2 == "Bug" || type2 == "Dragon" || type2 == "Steel"){
            return 0.5;
        }else return 1;
    }else if(type1 == "Psychic"){
        if(type2 == "Fighting" || type2 == "Poison"){
            return 2;
        }else if(type2 == "Psychic" || type2 == "Steel"){
            return 0.5;
        }else return 1;
    }else if(type1 == "Dragon"){
        if(type2 == "Dragon"){
            return 2;
        }else if(type2 == "Steel"){
            return 0.5;
        }else if("Fairy") return 0;
        else return 1;
    }else if (type1 == "Dark"){
        if(type2 == "Psychic" || type2 == "Ghost"){
            return 2;
        }else if(type2 == "Fighting" || type2 == "Dark" || type2 == "Fairy"){
            return 0.5;
        }else return 1;
    }else if(type1 == "Poison"){
        if(type2 == "Grass" || type2 == "Fairy"){
            return 2;
        }else if(type2 == "Poison" || type2 == "Rock" || type2 == "Ground" || type2 == "Ghost"){
            return 0.5;
        }else return 1;
    }
    
}