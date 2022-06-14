#include <iostream>
#include <fstream>
#include "Team.hpp"
#include "Game.hpp"
#include "League.hpp"
#include "Schedule.hpp"
#include <tuple>
#include <iostream>
#include <vector>

using namespace std;

using namespace  NBA;


static void ListMatches(std::vector<string> ListTeam) {


    int numDays = (39 - 1); // Days needed to complete tournament
    int halfSize = 39 / 2;

    string s = ListTeam[0];
    std::vector<string> teams;
    teams = ListTeam;
    teams.erase(teams.cbegin());


    int teamsSize = teams.size();

    for (int day = 0; day < numDays; day++) {

        cout << " ------------------Day ---------------------------  " << (day + 1) << endl;


        int teamIdx = day % teamsSize;
       cout << "{0} vs {1}" << teams[teamIdx] << "      " << s << endl;


        for (int idx = 1; idx < halfSize; idx++) {
            int firstTeam = (day + idx) % teamsSize;
            int secondTeam = (day + teamsSize - idx) % teamsSize;

           // if (teams[firstTeam] == "11" &&  teams[secondTeam] == "1" ) {

                cout << "{0} vs {1}" << teams[firstTeam] << "      " << teams[secondTeam]  << endl;
           // }
         //   else if (teams[firstTeam] == "10" &&  teams[secondTeam] == "9" ){  cout << "{0} vs {1}" << teams[firstTeam] << "      " << teams[secondTeam] << "\n" << endl;}

        }
    }
}


int main() {
    std::vector<Team> l;
//    l.reserve(20);
//    for (int i = 0; i < 20; ++i) {
//        l.push_back(to_string(i));
//    }
//    ListMatches(l);




    League myl{l};
    Schedule s(myl);

//        NBA::Team a{"a", 4.5};
//        NBA::Team b{"b", 4.5};
//
  //     NBA::Game g{a, b,myl};
////        std::cout << "p " << g.getWinner()->getName() <<"\n";
//
////
////        l.push_back(a);
////        l.push_back(b);
////
////
////        Schedule s {myl};
////
////        myl.print_League();




    return 0;
}
