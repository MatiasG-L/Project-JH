#pragma once
class Move{
    public:
    std::string name;
    int baseDmg;
    std::string type;
    int pp;
    int maxPP;
    int accuracy;
    int priority;
    std::string split;
    int moveContact;
    
    Move(std::string name, int baseDmg, std::string type, int pp, int accuracy, int priority, std::string split, int moveContact){
        this->name = name;
        this->baseDmg = baseDmg;
        this->type = type;
        this->pp = pp;
        maxPP = pp;
        this->accuracy = accuracy;
        this->priority = priority;
        this->split = split;
        this->moveContact = moveContact;
    }
    
    Move(){}
};