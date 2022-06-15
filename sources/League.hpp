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

        // stat
        std::vector<std::string> top_n(int n);
        std::tuple<std::string , int> Sequence_of_victories();
        std::tuple<std::string , int> Sequence_of_losses();
        std::tuple<std::string, int> max_score();
        std::tuple<std::string , float> top_talent();
        int Scored_than_absorbed();



        friend std::ostream &operator<<(std::ostream &os, const League &output );

    };
}

#endif //B_BALL_LEAGUE_HPP
