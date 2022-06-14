//
// Created by 97252 on 6/8/2022.
//

#include "Team.hpp"


NBA::Team::Team(const std::string &name_, float talent_) {
    this->name = name_;
    this->talent = talent_;
    this->win = 0;
}


float NBA::Team::getTalent() const {
    return talent;
}

void NBA::Team::setTalent(float talent_) {
    Team::talent = talent_;
}

const std::string &NBA::Team::getName() const {
    return this->name;
}

bool NBA::Team::operator!=(const NBA::Team &other) const {
    return this->getName() != other.getName();
}

int NBA::Team::getWin() const {
    return this->win;
}

void NBA::Team::setWin(int w) {
    this->win += w;
}




