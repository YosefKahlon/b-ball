//
// Created by 97252 on 6/8/2022.
//

#include <iostream>
#include "Game.hpp"
#include "random"

NBA::Game::Game(NBA::Team &home_, NBA::Team &out_ ) {


    this->home = &home_;
    this->out = &out_;



    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator

    std::normal_distribution<> distr_out(75, 15);
    std::normal_distribution<> distr_home(75, 15);


    const int min_o = 50;
    const int min_h = 55;
    const int max = 100;

    int score_o = 0;
    int score_h = 0;

    while (true) {
        score_o = (int) distr_out(gen);
        score_h = (int) distr_home(gen);

        if (score_o >= min_o && score_o <= max && score_h >= min_h && score_h <= max) {
            break;
        }
    }
    int coin = 0;
    home_.getTalent() > out_.getTalent() ? score_h += 10 : score_o += 10;

    this->home->addScore(score_h);
    this->home->add_absored(score_o);

    this->out->addScore(score_o);
    this->out->add_absored(score_h);


    if (score_o == score_h) {
        std::normal_distribution<> coins(55, 100);
        coin = (int) coins(gen);
        if (coin < 0) {
            this->home->addWin();
            this->out->addLose();
        } else {
            this->out->addWin();
            this->home->addLose();
        }

    }else if (score_o < score_h){
        this->home->addWin();
        this->out->addLose();
    }else {
        this->out->addWin();
        this->home->addLose();
    }






}

