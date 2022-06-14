//
// Created by 97252 on 6/8/2022.
//

#include <iostream>
#include "Schedule.hpp"


NBA::Schedule::Schedule(NBA::League &league_) {

    this->league = &league_;
    std::vector<Game> games;


    int numDays = (39 - 1); // Days needed to complete tournament
    int halfSize = 39 / 2;
    Team first = this->league->getMyTeam().at(0);
    std::vector<Team> teams;
    teams = this->league->getMyTeam();
    teams.erase(teams.cbegin());
    int teamsSize = teams.size();

    for (int day = 0; day < numDays; day++) {

        std::cout << "------------- Day --------------" << (day + 1) << std::endl;
        int teamIdx = day % teamsSize;

        if (day + 1 <= 19) {

            std::cout << "{0} vs {1}" << teams[teamIdx].getName() << "      " << first.getName() << "\n" << std::endl;
            Game game{teams[teamIdx], first, this->league};
            games.push_back(game);

            for (int idx = 1; idx < halfSize; idx++) {
                int firstTeam = (day + idx) % teamsSize;
                int secondTeam = (day + teamsSize - idx) % teamsSize;

                std::cout << "{0} vs {1}" << teams[firstTeam].getName() << "      " << teams[secondTeam].getName()
                          << "\n" << std::endl;
                Game game{teams[firstTeam], teams[secondTeam],this->league};
                games.push_back(game);

            }
        } else {


            std::cout << "{0} vs {1}" << teams[teamIdx].getName() << "      " << first.getName() << "\n" << std::endl;
            Game game{teams[teamIdx], first, this->league};
            games.push_back(game);

            for (int idx = 1; idx < halfSize; idx++) {
                int firstTeam = (day + idx) % teamsSize;
                int secondTeam = (day + teamsSize - idx) % teamsSize;

                std::cout << "{0} vs {1}" << teams[firstTeam].getName() << "      " << teams[secondTeam].getName()
                          << "\n" << std::endl;
                Game game{teams[firstTeam], teams[secondTeam], this->league};
                games.push_back(game);

            }

        }

    }


}




