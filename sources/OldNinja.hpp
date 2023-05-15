#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    private:
        int bullets;
    public:
        
        OldNinja(const std::string& name, const Point& location);
        
    };
}

#endif