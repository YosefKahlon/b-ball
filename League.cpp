//
// Created by 97252 on 6/8/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "League.hpp"
#include "Game.hpp"
#include "Team.hpp"
#include "random"

using namespace std;

NBA::League::League(const std::vector<Team> &set1) {
//    Team a{"F",4};
//    set1.push_back(a);

    if (set1.size() == 20) {
        this->myLeague = set1;


    }
        /** complete  the league to 20 teams **/
    else {
        this->myLeague = set1;


        std::string str;
        string alphabet[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                               "s", "t", "u", "v", "w", "x", "y", "z"};
        std::vector<string> dic_name;
        char r;
        for (int i = 0; i < 20 - set1.size(); ++i) {
            str = "Macbi - ";
            str += alphabet[i];
            std::string name = str;

            std::random_device rd; // obtain a random number from hardware
            std::mt19937 gen(rd()); // seed the generator
            std::uniform_int_distribution<> distr(1, 10); // define the range
            float star = distr(gen);
            Team temp_team{name, star};
            this->myLeague.push_back(temp_team);
        }

    }
}

NBA::League::League() {

    std::string str;
    string alphabet[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                           "s", "t", "u", "v", "w", "x", "y", "z"};
    std::vector<string> dic_name;
    char r;
    for (int i = 0; i < 20; ++i) {
        str = "Macbi - ";
        str += alphabet[i];
        std::string name = str;

        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(1, 10); // define the range
        float star = distr(gen);
        Team temp_team{name, star};
        this->myLeague.push_back(temp_team);
    }

}


// print

const vector<NBA::Team> &NBA::League::getMyTeam() const {
    return this->myLeague;
}



//void NBA::League::updateLeague(std::string win, std::string lose, int score_win, int score_lose) {
//
//    bool stop_win = false;
//    bool stop_lose = false;
//
//
//
//}




