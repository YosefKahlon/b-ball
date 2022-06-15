//
// Created by 97252 on 6/8/2022.
//

#ifndef B_BALL_TEAM_HPP
#define B_BALL_TEAM_HPP
#include "string"

namespace NBA {
    class Team {

    private:
        std::string name;
        float talent ;
        int win;
        int lose;
        int win_lose;
        int max_win;
        int max_lose;
        int score;
        int count_win;
        int count_lose;
        int Absorbed;

    public:
        Team(const std::string& name_ , float talent_);

        int getAbsorbed() const;

        void add_absored(int absorbed);

        int getScore() const;

        void addScore(int score);

        const std::string &getName() const;

        float getTalent() const;

        int getWin() const;

        int getLose() const;

        int getWinLosse() const;

        void setWinLosse(int winLosse);

        int getMaxWin() const;

        bool operator > (const Team &other ) const;
        bool operator < (const Team &other ) const;
        bool operator == (const Team &other ) const;
        bool operator != (const Team &other ) const;
        int getMaxLost() const;


        void addLose();
        void addWin();
    };

}

#endif //B_BALL_TEAM_HPP
