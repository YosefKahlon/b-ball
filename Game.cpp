//
// Created by 97252 on 6/8/2022.
//

#include <iostream>
#include "Game.hpp"
#include "random"

NBA::Game::Game(NBA::Team &home_, NBA::Team &out_ ) {


    this->home = &home_;
    this->out = &out_;
//    this->league= &l;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::normal_distribution<> distr_out(50, 100);
    std::normal_distribution<> distr_home(55, 100);

 // std:: cout << this->home->getWin() << std ::endl;
    const int min_o = 50;
    const int min_h = 55;
    const int max = 100;

    int score_o = 0;
    int score_h = 0;

    while (true) {
        score_o = (int) distr_out(gen);
        score_h = (int) distr_home(gen);
      //  std::cout << score_o << "  dis " << score_h <<"\n";
        if (score_o >= min_o && score_o <= max && score_h >= min_h && score_h <= max) {
            break;
        }
    }
    int coin = 0;
    home_.getTalent() > out_.getTalent() ? score_h += 10 : score_o += 10;

    setScoreHome(score_h);




    setScoreOut(score_o);

//    this->home->setScore(score_h);
//    this->out->setScore(score_o);
    if (score_o == score_h) {
        std::normal_distribution<> coins(55, 100);
        coin = (int) coins(gen);
        if (coin < 0) {
            setWinner(this->out);
            setLoser(this->home);

        } else {
            setWinner(this->home);
            setLoser(this->out);
        }

    }
    else if (score_o < score_h){
        setWinner(this->out);
        setLoser(this->home);
     //   this->league->updateLeague(this->getWinner()->getName() , this->getLoser()->getName(),this->score_out,this->score_home);
        this->home->setWin(1);
    }
    else {
        setWinner(this->home);
        setLoser(this->out);
        this->out->setWin(1);
    //    this->league->updateLeague(this->getWinner()->getName() , this->getLoser()->getName(),this->score_home,this->score_out);
    }

//    std:: cout << "------------------------this is test  -------------------------------- \n" ;
//
//    for (int i = 0; i < this->league->getMyTeam().size(); ++i) {
//        std ::cout << this->league->getMyTeam().at(i).getName()   << " --->   " << this->league->getMyTeam().at(i).getScore() << std::endl;
//
//    }
//    std:: cout << "------------------------end  test  -------------------------------- \n";



}


int NBA::Game::getScoreOut() const {
    return score_out;
}

void NBA::Game::setScoreOut(int scoreOut) {
    score_out = scoreOut;
}

int NBA::Game::getScoreHome() const {
    return score_home;
}

void NBA::Game::setScoreHome(int scoreHome) {
    score_home = scoreHome;
}

NBA::Team *NBA::Game::getWinner() const {
    return this->winner;
}

NBA::Team *NBA::Game::getLoser() const {
    return this->loser;
}

void NBA::Game::setWinner(NBA::Team *winner_) {
    Game::winner = winner_;
}

void NBA::Game::setLoser(NBA::Team *loser_) {
    Game::loser = loser_;
}

