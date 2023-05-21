#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"  
#include <iostream>
#include <string>
#include <sstream>
#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>

namespace ariel {
    class SmartTeam : public Team {
    public:
        SmartTeam(Character* leader);
        void attack(Team* enemy) override;
        Character* get_best_enemy(Team* enemyTeam, Character* attacker);
        
    };
}

#endif
