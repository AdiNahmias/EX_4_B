#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel{


Character::Character(const string& name, const Point& location, int hitp)
    : name(name), location(location), hitp(hitp)
{}

Character::Character(const string& name, const Point& location)
    : name(name), location(location)
{}


int Character::getHP(){
    return  this->hitp;
}

string Character::getName()const{
    return this->name;
}

bool Character::isAlive() const{
    return hitp > 0;
}

bool Character::get_is_member(){
    return member; 
}

void Character::set_is_member(){
    member = true;
}

bool Character::get_is_leader(){
    return leader; 
}

void Character::set_is_leader(){
    leader = true;
}

double Character::distance(Character* other){
    double distance = this->location.distance(other->location);
    return distance;
}

void Character::hit(int amount) {
    if(amount < 0){
        throw invalid_argument("cant hit with a negative number");
    }
    hitp -= amount;
}

const Point& Character::getLocation()const{
    return location;
}

void Character::setLocation(Point location){
    this->location = location;
}

string Character::print(){
    string str_point = this->location.print();

    string ans = "Name:"+ this->name +", Location:"+ str_point;
    if(hitp > 0){
        ans += ", Hit point:"+ to_string(hitp);
    }else{
        ans += ", Hit point:0";
    }
    return ans;
    
    }

}