#include "Team.hpp"
#include <cmath>

namespace ariel {
    Team::Team(Character* leader) : leader(leader) {
        fighters.push_back(leader);
    }


    void Team::add(Character* fighter) {
        if (fighters.size() < 10) {
            fighters.push_back(fighter);
        }
    }

    void Team::attack(Team* enemy) {}

    int Team::stillAlive() const {
        
        return 0;
    }

    void Team::print() const {
        
    }
}
