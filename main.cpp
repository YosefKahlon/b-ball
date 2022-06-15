#include <iostream>

#include "Team.hpp"
#include "Game.hpp"
#include "League.hpp"
#include "Schedule.hpp"


#include <vector>

using namespace std;

using namespace  NBA;




int main() {


    League myl{};
    Schedule s(myl);

  //  cout <<  std::get<0>(myl.max_score())  << " socre " << std::get<1>(myl.max_score())<< endl;
   // cout<< myl.Scored_than_absorbed() << endl;
   cout << myl << endl;

//    for (int i = 0; i < myl.top_n(5).size(); ++i) {
//        cout <<myl.top_n(5).at(i)<< endl;
//    }







    return 0;
}
