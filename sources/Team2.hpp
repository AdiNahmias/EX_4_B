#ifndef TEAM2_HPP
#define TEAM2_HPP
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
using namespace std;

namespace ariel {
    class Team2 : public Team{

    public:
        
        Team2(Character* leader);
        void add(Character* fighter) override;
        
    };
}

#endif