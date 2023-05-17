#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <string>
#include <sstream>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character{
    private:
    bool member=false;
    bool leader=false;
    string name;
    Point location;
    int hitp;
        

    public:
    Character(const string& name, const Point& location, int hitp);
    Character(const string& name, const Point& location);
    Character(const Character& other); // Copy constructor
    Character& operator=(const Character& other); // Copy assignment operator
    Character(Character&& other)noexcept; // Move constructor
    Character& operator=(Character&& other)noexcept; 
    virtual ~Character() = default;
    bool get_is_member();
    void set_is_member();
    void set_is_leader();
    bool get_is_leader();
    int getHP();
    string getName();
    bool isAlive();
    double distance(Character* other);
    void hit(int amount);
    Point& getLocation();
    void setLocation(Point location);
    virtual string print();
       
    };
}

#endif 