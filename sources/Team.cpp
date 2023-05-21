#include "Team.hpp"
#include <cmath>
#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
using namespace std;

namespace ariel {

    Team::Team(Character* leader) : leader(leader) {
        fighters.push_back(leader);
        if (this->leader == nullptr) {
        throw runtime_error("Leader is not initialized");
        }
        if(this->leader->get_is_leader()){
            throw runtime_error("This leader already a leader");
        }
        leader->set_is_leader();
    }
    Team::~Team(){
        for(Character* fighter : fighters){
            delete fighter;
        }
    }

    Team::Team(const Team& other) : leader(other.leader){
            // Copy the state of the `other` object
            // to the new `Team` object
            // ...
    }

    Team& Team::operator=(const Team& other) {
        if (this != &other) {
            // Copy the state of the `other` object
            // to the current object
            // ...
        }
        return *this;
    }


    void Team::add(Character* fighter) {
        if(fighter->get_is_member()){
            throw runtime_error("This member already a member");
        }else{
            fighter->set_is_member();
        }
        if(fighters.size() == 10){
            throw runtime_error("There are no more places in the group");
        }
        if (fighters.size() < 10) {
            if(Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)){
            fighters.insert(fighters.begin(),fighter);
            }else{
                fighters.push_back(fighter);
            }
        }
    }

    vector<Character*>& Team::getFighters(){
        return fighters;
    }
    
    Character* Team::getLeader() const {
    return this->leader;
    }

    void Team::setLeader(Character* new_leader) {
        this->leader = new_leader;
    }

    Character* Team::chose_enemy(Team* enemyTeam){
    Character* my_enemy = nullptr;
    double dist = 0;
    double min_dist = numeric_limits<double>::max();
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

void Team::attack(Team* enemy){

    if (enemy==nullptr || leader==nullptr){
       throw invalid_argument("Enemy/leader is nullptr");
    }

    if((enemy->stillAlive()) == 0 || (this->stillAlive()) == 0){
        throw runtime_error("Attacking a dead team");
    }
    
    //check if there the leader is alive and find another one if he is dead
    if (!(leader->isAlive())) {
        double dist = 0;
        double min_dist = numeric_limits<double>::max();
        Character* new_one = nullptr;
        for(Character *new_leader: fighters){
            if(new_leader->isAlive()){
                dist = new_leader->distance(leader);
                if(dist < min_dist){
                    min_dist = dist;
                    new_one = new_leader;
                }
            }
        }
        setLeader(new_one);
    }

    Character* closestEnemy = nullptr;
    if(enemy->stillAlive() >0){
        closestEnemy = chose_enemy(enemy);
    }

    for(Character* fighter : fighters){
        if(fighter != nullptr && fighter->isAlive()){
            if(closestEnemy != nullptr && closestEnemy->isAlive()){
                if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)){
                    if (cowboy && cowboy->hasboolets()) {    
                        cowboy->shoot(closestEnemy);
                    } 
                    else{
                        cowboy->reload();
                    }
                }
                if(Ninja* ninja = dynamic_cast<Ninja*>(fighter)){
                    if(ninja->distance(closestEnemy) < 1){
                        ninja->slash(closestEnemy);
                    }
                    else{
                        ninja->move(closestEnemy);
                    }
                }
            }
            else{
                Character* new_enemy = chose_enemy(enemy);
                closestEnemy = new_enemy;
                if(closestEnemy !=nullptr && closestEnemy->isAlive()){
                    if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)){
                        if (cowboy && cowboy->hasboolets()) {    
                            cowboy->shoot(closestEnemy);
                        } 
                        else{
                            cowboy->reload();
                        }
                    }
                    else if(Ninja* ninja = dynamic_cast<Ninja*>(fighter)){
                        if(ninja->distance(closestEnemy) < 1){
                            ninja->slash(closestEnemy);
                        }
                        else{
                            ninja->move(closestEnemy);
                        }
                    }
                }
            }

        } 
    }

}
          
int Team::stillAlive() const {
    int count = 0;
    for (Character* fighter : fighters) {
        if (fighter != nullptr && fighter->isAlive()) {
            count++;
        }
    }
    return count;
}

void Team::print() const {
    string ans;
    for (Character* fighter : fighters) {
        ans += fighter->print() + "\n";
    }
    cout<< ans <<endl;
}

   
}