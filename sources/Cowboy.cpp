#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(const string& name, const Point& location)
        : Character(name, location, 110), bullets(6)
    {}


    int Cowboy::getBullet(){
        return this->bullets;
    }

    bool Cowboy::hasbullets() const{
            return bullets > 0;
    }


    void Cowboy::shoot(Character* enemy){
       if( !(enemy->isAlive()) || !hasbullets()){
            cout << "No one was shot. Cowboy is either dead or has no bullets." << endl;
            return;
        }
        enemy->hit(10);
        this->bullets --;
        
    }

    void Cowboy::reload(){
        bullets = 6;
    }

    string Cowboy::print() {
        string str_point = this->getLocation().print();  // Assuming the Character class has a getLocation() function
        string ans = "Name: " + this->getName() + ", Location: " + str_point + ", Hit point: " + to_string(this->getHP())+
        ", Bullets: " +to_string(this->bullets);
        return ans;
    }

    
    
}
