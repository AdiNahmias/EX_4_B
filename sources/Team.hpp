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
#include <stdexcept>
#include <limits>
#include <numeric>
using namespace std;

namespace ariel {
    class Team {
    private:
        vector<Character*> fighters;
        Character* leader;

    public:
        Team(Character* leader);
        virtual ~Team();
        Team(const Team& other);
        Team& operator=(const Team& other);
        Team& operator=(Team&& other) = default;
        Team(Team&& other) = default;
        Character* chose_enemy(Team* enemyTeam);
        Character* getLeader() const;
        vector<Character*>& getFighters();
        void setLeader(Character* new_leader);
        virtual void add(Character* fighter);
        void attack(Team* enemy);
        int stillAlive() const;
        void print() const;
    };
}

#endif