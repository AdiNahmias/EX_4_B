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

Character::Character(const Character& other)
        : name(other.name), location(other.location), hitp(other.hitp)
{}

Character& Character::operator=(const Character& other)
{
    if (this != &other) {
        name = other.name;
        location = other.location;
        hitp = other.hitp;
    }
    return *this;
}

Character::Character(Character&& other)noexcept
    : name(move(other.name)), location(move(other.location)), hitp(move(other.hitp))
{
    other.hitp = 0;
}

Character& Character::operator=(Character&& other)noexcept
{
    if (this != &other) {
        name = move(other.name);
        location = move(other.location);
        hitp = move(other.hitp);
        other.hitp = 0;
    }
    return *this;
}


int Character::getHP(){
    return  this->hitp;
}

string Character::getName(){
    return this->name;
}

bool Character::isAlive(){
    return hitp > 0;
}

double Character::distance(Character* other){
    double distance = this->location.distance(other->location);
    return distance;
}

void Character::hit(int amount) {
    hitp -= amount;
}

Point& Character::getLocation(){
    return location;
}

void Character::setLocation(Point location){
    this->location = location;
}

string Character::print(){
    string str_point = this->location.print();
    string ans = "Name:"+ this->name +", Location:"+ str_point + ", Hit point:"+ to_string(hitp);
    return ans;
    
    }

}