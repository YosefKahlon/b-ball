//
// Created by 97252 on 6/8/2022.
//

#include "Team.hpp"


NBA::Team::Team(const std::string &name_, float talent_) {
    this->name = name_;
    this->talent = talent_;
    this->win = 0;
    this->max_lose = 0 ;
    this->win_lose = 0;
    this->max_win = 0;
    this->lose = 0;
    this->count_lose = 0;
    this->count_win = 0;
    this->Absorbed = 0;
}


float NBA::Team::getTalent() const {
    return talent;
}


const std::string &NBA::Team::getName() const {
    return this->name;
}



int NBA::Team::getWin() const {
    return this->win;
}

void NBA::Team::addWin() {
    this->win ++;
    this->count_win++;
    this->count_lose = 0;
    //The length of the season's longest winning streak
    if(this->count_win > this->max_win){
        this->max_win = this->count_win;
    }


}

int NBA::Team::getMaxWin() const {
    return max_win;
}


int NBA::Team::getMaxLost() const {
    return max_lose;
}



int NBA::Team::getScore() const {
    return score;
}

void NBA::Team::addScore(int score_ ){
    this->score += score_;
}

void NBA::Team::addLose() {
    this->lose++;
    this->count_lose++;
    this->count_win = 0;
    if (this->count_lose > this->lose){
        this->lose = this->count_lose;
    }


}

bool NBA::Team::operator>(const NBA::Team &other) const {
    return this->win > other.win;
}

bool NBA::Team::operator<(const NBA::Team &other) const {
    return this->win < other.win;
}

bool NBA::Team::operator==(const NBA::Team &other) const {
    return this->win == other.win;
}

bool NBA::Team::operator!=(const NBA::Team &other) const {
    return this->win != other.win;
}

int NBA::Team::getLose() const {
    return lose;
}

int NBA::Team::getAbsorbed() const {
    return Absorbed;
}

void NBA::Team::add_absored(int absorbed) {
    this->Absorbed += absorbed;
}






