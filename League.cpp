//
// Created by 97252 on 6/8/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "League.hpp"
#include "Game.hpp"
#include "Team.hpp"
#include "random"

using namespace std;

NBA::League::League(std::vector<Team> &set1) {


    if (set1.size() == 20) {

        for (int i = 0; i < set1.size(); ++i) {
            this->myLeague.push_back(&set1.at(i));
        }


    }
        /** complete  the league to 20 teams **/
    else {
        for (int i = 0; i < set1.size(); ++i) {
            this->myLeague.push_back(&set1.at(i));
        }


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
            std::uniform_real_distribution<float> distr(0, 1);
            float star = distr(gen);
            Team temp_team{name, star};

            this->helper.push_back(temp_team);
        }
        for (int i = 0; i < 20; ++i) {
            this->myLeague.push_back(&helper.at(i));
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

        std::uniform_real_distribution<float> distr(0, 1);

        float star = distr(gen);

        Team temp_team{name, star};
        this->helper.push_back(temp_team);
    }


    for (int i = 0; i < 20; ++i) {
        this->myLeague.push_back(&helper.at(i));
    }


}


const vector<NBA::Team *> &NBA::League::getMyTeam() const {
    return (this->myLeague);
}


bool myCoompre(NBA::Team *team, NBA::Team *team2) {

    float stat, stat2;

    if (team->getLose() != 0 && team2->getLose() != 0) {
        stat = team->getWin() / team->getLose();
        stat2 = team2->getWin() / team2->getLose();

        return stat > stat2;
    }


    return team->getScore() > team2->getScore();
}


std::vector<std::string> NBA::League::top_n(int n) {

    std::vector<string> ans;
    std::sort(this->myLeague.begin(), this->myLeague.end(), myCoompre);

    std::vector<Team *> temp_n;
    temp_n.assign(this->myLeague.begin(), this->myLeague.begin() + n);
    for (int i = 0; i < temp_n.size(); ++i) {
        ans.push_back(temp_n.at(i)->getName());
    }

    return ans;

}

std::tuple<std::string, int> NBA::League::Sequence_of_losses() {
    string temp;
    int lose = 0;

    for (int i = 0; i < this->myLeague.size(); ++i) {
        if (lose < this->myLeague.at(i)->getMaxLost()) {
            lose = this->myLeague.at(i)->getMaxLost();
            temp = this->myLeague.at(i)->getName();
        }
    }

    tuple<std::string, int> ans = {temp, lose};
    return ans;
}


std::tuple<std::string, int> NBA::League::Sequence_of_victories() {
    string temp;
    int maxWIN = 0;

    for (int i = 0; i < this->myLeague.size(); ++i) {
        if (maxWIN < this->myLeague.at(i)->getMaxWin()) {
            maxWIN = this->myLeague.at(i)->getWin();
            temp = this->myLeague.at(i)->getName();
        }
    }

    tuple<std::string, int> ans = {temp, maxWIN};
    return ans;
}

std::tuple<std::string, int> NBA::League::max_score() {
    string temp;
    int score = 0;

    for (int i = 0; i < this->myLeague.size(); ++i) {
        if (score < this->myLeague.at(i)->getScore()) {
            score = this->myLeague.at(i)->getScore();
            temp = this->myLeague.at(i)->getName();
        }
    }

    tuple<std::string, int> ans = {temp, score};
    return ans;
}

int NBA::League::Scored_than_absorbed() {
    int count = 0;

    for (int i = 0; i < this->myLeague.size(); ++i) {
        if (this->myLeague.at(i)->getScore() < this->myLeague.at(i)->getAbsorbed()) { count++; }
    }


    return count;
}


std::ostream &NBA::operator<<(ostream &os, const League &other) {

    std::vector<Team *> temp;
    for (int i = 0; i < other.myLeague.size(); ++i) {
        temp.push_back(other.myLeague.at(i));
    }


    std::sort(temp.begin(), temp.end(), myCoompre);
    os << "Rank:      " << " " << "   Win: " << "           Lose: " << "        Score: " << "\n";
    for (int i = 0; i < temp.size(); ++i) {


        os << i + 1 << " :" << temp.at(i)->getName() << "   ========= " << temp.at(i)->getWin()
           << "   ========= " << temp.at(i)->getLose() << "   ========= " << temp.at(i)->getScore()
           << "\n";

    }


    return os;

}















