//
// Created by 97252 on 6/8/2022.
//

#ifndef B_BALL_SCHEDULE_HPP
#define B_BALL_SCHEDULE_HPP

#include <unordered_map>
#include "League.hpp"
#include "Game.hpp"

namespace NBA {
    class Schedule {

    private:
        League * league;



    public:
        explicit Schedule(League &league_) ;

    };
}

#endif //B_BALL_SCHEDULE_HPP
