//
// Created by sandw on 12/5/2020.
//

#include "Day5.h"

using namespace std;

int Day5::calculate1(std::vector<std::string> input) {

    vector<Seat> seats;
    for (int i = 0; i < input.size(); ++i) {
        Seat seat;

        // parse off the /n
        string code = input[i].substr(0, input[i].size()-1);

        int rowTopRange = 127;
        int rowBottomRange = 0;
        int colTopRange = 7;
        int colBottomRange = 0;

        for (int j = 0; j < 7; ++j) {
            int value = pow(2, 6-j);
            if (code[j] == 'F') {

                rowTopRange -= value;
            }
        }

        for (int j = 0; j < 3; ++j) {
            int value = pow(2, 2-j);
            if (code[j + 7] == 'L') {

                colTopRange -= value;
            }
        }

        seat.row = rowTopRange;
        seat.column = colTopRange;
        seat.id = rowTopRange*8 + colTopRange;
        seats.push_back(seat);
    }

    int maxID = 0;
    for (int i = 0; i < seats.size(); ++i) {
        if (seats[i].id > maxID)
            maxID = seats[i].id;
    }

    vector<int> sortedIDs;
    for (int i = 0; i < seats.size(); ++i) {
        sortedIDs.push_back(seats[i].id);
    }

    sort(sortedIDs.begin(), sortedIDs.end());
    int mySeatID = 0;
    for (int i = 0; i < sortedIDs.size(); ++i) {
        cout<<sortedIDs[i]<<endl;

        if (i < sortedIDs.size() - 2)
            if (sortedIDs[i+1] - sortedIDs[i] > 1 && sortedIDs[i+2] - sortedIDs[i] > 1)
                mySeatID = sortedIDs[i+1];
    }

    return mySeatID - 1;
}


