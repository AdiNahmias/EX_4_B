#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    private:
        int bullets;
    public:
        
        TrainedNinja(const std::string& name, const Point& location);
        
    };
}

#endif