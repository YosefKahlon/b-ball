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

    public:
        Team(const std::string& name_ , float talent_);


        const std::string &getName() const;

        float getTalent() const;

        void setTalent(float talent);

        bool operator != (const Team &other ) const;
    };

}

#endif //B_BALL_TEAM_HPP
