#include "Team.hpp"
#include <cmath>
#include <iostream>
#include <vector>

namespace ariel {
    Team::Team(Character* leader) : leader(leader) {
        fighters.push_back(leader);
    }

    void Team::add(Character* fighter) {
        if(fighters.size() == 10){
            throw runtime_error("There are no more places in the group");
        }
        if (fighters.size() < 10) {
            fighters.push_back(fighter);
        }
    }
    Character* Team::getLeader() const {
    return this->leader;
    }

    void Team::setLeader(Character* new_leader) {
        this->leader = new_leader;
    }

    Character* Team::chose_enemy(Team* enemyTeam){
    Character* my_enemy;
    double dist = 0;
    double min_dist = 0;
    for (Character* enemy : enemyTeam->fighters) {
        if (enemy->isAlive()) {
            dist = this->leader->distance(enemy);
            if (dist < min_dist) {
                min_dist = dist;
                my_enemy = enemy;
            }
        }
    }
    return my_enemy;
}

void Team::attack(Team* enemy) {

    if (!leader && !(leader->isAlive())) {
        //choose other leader
        double dist = 0;
        double min_dist = 0;
        Character* new_one;
        for(Character *new_leader: fighters){
            if(new_leader->isAlive()){
                dist = new_leader->distance(leader);
            }
            if(dist < min_dist){
                min_dist = dist;
                new_one = new_leader;
            }
        }
        setLeader(new_one);
        //if there is a leader
    }else{
        Character* closestEnemy = chose_enemy(enemy);
        if(closestEnemy){
            for(Character* fighter : fighters){
                if(fighter->isAlive()){
                    if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)){
                        if (cowboy && cowboy->hasboolets()) {
                                cowboy->shoot(closestEnemy);
                            } else {
                                cowboy->reload();
                            }
                    }else if(Ninja* ninja = dynamic_cast<Ninja*>(fighter)){
                        if(ninja->distance(closestEnemy) < 1){
                            ninja->slash(closestEnemy);
                        }
                    }                                                                               
                }
                //chek if the enemy id dead and choose another one
                if(!(closestEnemy-> isAlive())){
                Character* new_enemy = chose_enemy(enemy);
                closestEnemy = new_enemy;
                }

            }//end for
        }
        
    }

}
          
int Team::stillAlive() const {
    int count = 0;
    for (Character* fighter : fighters) {
        if (fighter->isAlive()) {
            count++;
        }
    }
    return count;
}

string Team::print() const {
    string ans;
    for (Character* fighter : fighters) {
        ans += fighter->print() + "\n";
    }
    return ans;
    
}

   
}
