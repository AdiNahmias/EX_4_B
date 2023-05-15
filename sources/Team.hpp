#ifndef TEAM_HPP
#define TEAM_HPP
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
    class Team {
    private:
        vector<Character*> fighters;
        Character* leader;

    public:
        Team(Character* leader);
        void add(Character* fighter);
        void attack(Team* enemy);
        int stillAlive() const;
        void print() const;
    };
}

#endif