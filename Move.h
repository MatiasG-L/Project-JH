class Move{
    public:
    std::string name;
    int baseDmg;
    std::string type;
    int pp;
    int accuracy;
    int priority;
    
    Move(std::string name, int baseDmg, std::string type, int pp, int accuracy, int priority){
        this->name = name;
        this->baseDmg = baseDmg;
        this->type = type;
        this->pp = pp;
        this->accuracy = accuracy;
        this->priority = priority;
    }
};