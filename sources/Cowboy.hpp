#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets;
    public:
        Cowboy(const std::string& name, const Point& location);
        int getBullet();
        void shoot(Character* enemy);
        bool hasbullets() const;
        void reload();
        string print() override;
        
    };
}

#endif