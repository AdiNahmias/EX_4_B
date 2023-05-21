#include "SmartTeam.hpp"
#include <cmath>

namespace ariel {
    SmartTeam::SmartTeam(Character* leader) : Team(leader) {}


    Character* SmartTeam::get_best_enemy(Team* enemyTeam, Character* attacker){
        int priority = 0;
        int min_priority = numeric_limits<double>::max();
        Character* best_enemy = nullptr;

        Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker);
        for(Character* enemy : enemyTeam->getFighters()){
        if(cowboy != nullptr){
            priority = (enemy->getHP()/10);
            
        }else{
            Ninja* ninja = dynamic_cast<Ninja*>(attacker);
            if(ninja->distance(enemy) <= 1){
                priority = (enemy->getHP()/40);
            }else{
                ninja->move(enemy);
            }
        }

        if(priority < min_priority){
            min_priority = priority;
            best_enemy = enemy;
        }
        
    }
    return best_enemy;

    }

    
    void SmartTeam::attack(Team* enemy) {
        if (enemy==nullptr || getLeader() ==nullptr){
        throw invalid_argument("Enemy/leader is nullptr");
        }

        if((enemy->stillAlive()) == 0 || (this->stillAlive()) == 0){
        throw runtime_error("Attacking a dead team");
        }
    
        //check if there the leader is alive and find another one if he is dead
        if (!(getLeader()->isAlive())) {
            double dist = 0;
            double min_dist = numeric_limits<double>::max();
            Character* new_one = nullptr;
            for(Character *new_leader: getFighters()){
                if(new_leader->isAlive()){
                    dist = new_leader->distance(getLeader());
                    if(dist < min_dist){
                        min_dist = dist;
                        new_one = new_leader;
                    }
                }
            }
            setLeader(new_one);
        }
        //------------------------------------------------
        Character* bestEnemy = nullptr;
        for(Character* fighter : getFighters()){
            if(enemy->stillAlive() > 0){
                if(fighter != nullptr && fighter->isAlive()){
                bestEnemy = get_best_enemy(enemy,fighter);
                }
            }
            if(bestEnemy != nullptr && bestEnemy->isAlive()){
                if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)){
                    if(cowboy && cowboy->hasboolets()){
                    cowboy->shoot(bestEnemy);
                    }else{
                      cowboy->reload();  
                    }
                }else{
                    Ninja* ninja = dynamic_cast<Ninja*>(fighter);
                    ninja->slash(bestEnemy);
                    
                }
            }
        }
    }

}