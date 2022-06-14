//
// Created by 97252 on 6/8/2022.
//

#ifndef B_BALL_LEAGUE_HPP
#define B_BALL_LEAGUE_HPP

#include <unordered_map>
#include <vector>
#include <map>
#include "Team.hpp"

namespace NBA {

    class League {
    private:
        std::vector<Team*> myLeague;
        std::vector<Team> helper ;
    public:

        explicit League(std::vector<Team> &set1);

        League();


        const std::vector<Team *> &getMyTeam() const;

//        // return the n top team
//        std::vector<Team> top_n(int n);
//
//        std::vector<Team> get_team();
//
        //  void updateLeague(std::string win ,std::string lose , int score_win ,int  score_lose);

        // League(League *pLeague);
    };
}

#endif //B_BALL_LEAGUE_HPP
