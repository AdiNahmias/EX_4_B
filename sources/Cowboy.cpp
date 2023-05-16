#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(const string& name, const Point& location)
        : Character(name, location, 110), bullets(6)
    {}


    int Cowboy::getBullet(){
        return this->bullets;
    }

    bool Cowboy::hasboolets() const{
            return bullets > 0;
    }


    void Cowboy::shoot(Character* enemy){
        if(!(this->hasboolets())){
            return;
        }
        if(!(this->isAlive())){
            throw runtime_error("Dead character cant do shoot"); 
        }
        if(enemy == this){
            throw runtime_error("No self harm"); 
        }
       if( !(enemy->isAlive())){
            throw runtime_error("Cowboy is either dead or has no bullets"); 
        }
        enemy->hit(10);
        this->bullets --;
        
    }

    void Cowboy::reload(){
        if(this->isAlive()){
        bullets = 6;
        }else{
            throw runtime_error("The cowboy is dead cant reload");
        }
    }

    string Cowboy::print() {
        string str_point = this->getLocation().print();  // Assuming the Character class has a getLocation() function
        string ans = "Name: " + this->getName() + ", Location: " + str_point + ", Hit point: " + to_string(this->getHP())+
        ", Bullets: " +to_string(this->bullets);
        return ans;
    }

    
    
}
