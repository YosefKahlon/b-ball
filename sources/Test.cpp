//
// Created by 97252 on 6/15/2022.
//
#include "../doctest.h"
#include "iostream"
#include "League.hpp"
#include "Schedule.hpp"
#include "Team.hpp"
#include "Game.hpp"

using namespace NBA;
using namespace std;

TEST_CASE ("League") {
    League l;

            CHECK_EQ(l.getMyTeam().size(), 20);
    vector<string> name =
            {"Macbi - a", "Macbi - b", "Macbi - c", "Macbi - d", "Macbi - e", "Macbi - f", "Macbi - g", "Macbi - h",
             "Macbi - i", "Macbi - j", "Macbi - k", "Macbi - l", "Macbi - m", "Macbi - n", "Macbi - o", "Macbi - p",
             "Macbi - q", "Macbi - r", "Macbi - s", "Macbi - t"};

    for (uint i = 0; i < l.getMyTeam().size(); ++i) {
                CHECK_EQ(l.getMyTeam().at(i)->getName(), name.at(i));
                CHECK_FALSE(l.getMyTeam().at(i)->getTalent() > 1);
                CHECK(l.getMyTeam().at(i)->getTalent() > 0);
    }

    Schedule S{l};
            CHECK(get<1>(l.max_score()) > 100);
            CHECK(get<1>(l.top_talent()) < 1);
            CHECK(get<1>(l.top_talent()) > 0);
            CHECK(get<1>(l.Sequence_of_victories()) > 0);

    for (int i = 0; i < 20; ++i) {
        vector<string> top_n = l.top_n(i);
                CHECK_EQ(top_n.size(), i);
    }

}