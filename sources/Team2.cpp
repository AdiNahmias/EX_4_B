#include "Team2.hpp"
#include <cmath>

namespace ariel {

    
    Team2::Team2(Character* leader) : Team(leader) {}

    void Team2::add(Character* fighter) {
    if(fighter->get_is_member()){
        throw runtime_error("This member already a member");
    }else{
        fighter->set_is_member();
    }
    if(getFighters().size() == 10){
        throw runtime_error("There are no more places in the group");
    }
    if (getFighters().size() < 10) {
        getFighters().insert(getFighters().begin(),fighter);
        }
    }
        
}