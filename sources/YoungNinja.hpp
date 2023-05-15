#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    private:
        int bullets;
    public:
        
        YoungNinja(const std::string& name, const Point& location);
        
    };
}

#endif