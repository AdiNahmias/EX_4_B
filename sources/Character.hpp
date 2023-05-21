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
        int priority_enemy = 0;
        bool member=false;
        bool leader=false;
        string name;
        Point location;
        int hitp;
            

    public:
        Character(const string& name, const Point& location, int hitp);
        Character(const string& name, const Point& location);
        Character(const Character&) = delete; // delete copy constructor
        Character& operator=(const Character&) = delete; // delete copy assignment operator
        Character(Character&&) = delete; // delete move constructor
        Character& operator=(Character&&) = delete; // delete move assignment operator
        virtual ~Character() = default;
        bool get_is_member();
        void set_is_member();
        void set_is_leader();
        bool get_is_leader();
        int getHP();
        string getName() const;
        bool isAlive() const;
        double distance(Character* other);
        void hit(int amount);
        const Point& getLocation() const;
        void setLocation(Point location);
        virtual string print() = 0;
        
    };
}

#endif 