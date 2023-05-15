#include "Ninja.hpp"
#include <cmath>

namespace ariel
{
    Ninja::Ninja(const std::string& name, const Point& location, int hitp, int speed)
        : Character(name, location, hitp), speed(speed)
    {}

    int Ninja::getSpeed(){
        return this->speed;
    }


    void Ninja::move(Character* enemy){

        if (this->isAlive()) {
        // Calculate the distance between the ninja and the enemy
        double distance = this->getLocation().distance(enemy->getLocation());
        // Calculate the amount to move based on the ninja's speed
        double moveDistance = speed;
            // Move towards the enemy if it's less than the move distance
            if (distance < moveDistance) {
                setLocation(enemy->getLocation());
            }
            else {
                // Calculate the direction vector towards the enemy
                double d_x = enemy->getLocation().getX() - this->getLocation().getX();
                double d_y = enemy->getLocation().getY() - this->getLocation().getY();
                // Calculate the unit direction vector
                double unitDx = d_x / distance;
                double unitDy = d_y / distance;
                // Calculate the new location by adding the unit direction vector
                // multiplied by the move distance to the current location
                setLocation(Point(getLocation().getX() + unitDx * moveDistance, getLocation().getY() + unitDy * moveDistance));
            }
        }
    }

    void Ninja::slash(Character* enemy){

        if (isAlive()){
            // Calculate the distance between the ninja and the enemy
            double distance = this->getLocation().distance(enemy->getLocation());
            // Check if the enemy is less than 1 meter away
            if (distance < 1.0) {
                enemy->hit(40);
            }
        }
    }



}

