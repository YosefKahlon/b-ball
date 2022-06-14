//
// Created by 97252 on 6/8/2022.
//

#ifndef B_BALL_GAME_HPP
#define B_BALL_GAME_HPP

#include "Team.hpp"
#include "League.hpp"
namespace NBA {
    class Game {

    private:
        Team *home;
        Team *out;
        Team *winner;
        Team *loser;
        League *league;
        int score_out;
        int score_home;


    public:
        Game( Team& home_,Team& out_ , League * league_);


        int getScoreOut() const;

        void setScoreOut(int scoreOut);

        int getScoreHome() const;

        void setScoreHome(int scoreHome);

        Team *getWinner() const;

        void setWinner(Team *winner);

        void setLoser(Team *loser);

        Team *getLoser() const;
    };
}

#endif //B_BALL_GAME_HPP
