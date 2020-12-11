//
// Created by sandw on 12/10/2020.
//

#include "day10.h"

using namespace std;

long Day10::calculate1(std::vector<std::string> input) {
    vector<int> adapters;
    for (int i = 0; i < input.size(); ++i) {
        adapters.push_back(stoi(input[i]));
    }

    sort(adapters.begin(), adapters.end());

    int ones = 1;
    int threes = 1; // adapter is 3 less than device so add 1 here

    for (int i = 0; i < adapters.size() - 1; ++i) {
        if (adapters[i+1] - adapters[i] == 1) {
            ones++;
        }
        else {
            threes++;
        }
    }

    cout<<"ones "<<ones<<" threes "<<threes<<endl;
    return ones * threes;
}

long Day10::calculate2(std::vector<std::string> input) {
    vector<int> adapters;
    for (int i = 0; i < input.size(); ++i) {
        adapters.push_back(stoi(input[i]));
    }

    sort(adapters.begin(), adapters.end());

    long connectionPossibilities = 1;

    for (int i = 0; i < adapters.size(); ++i) {

        bool reachedEnd = false;

        // Check ahead for next 3-jump
        int continuousValsFromThisIndex = 0;
        for (int j = i; j < adapters.size(); ++j) {
            int numCurr = adapters[j];
            int numNext = adapters[j+1];

            if (numNext - numCurr == 1) {
                continuousValsFromThisIndex++;
                cout<<adapters[j]<<" ";

                if (j+1 == adapters.size())
                    reachedEnd = true;
            }
            else
            {
                i = j;
                cout<<adapters[j];
                continuousValsFromThisIndex++;

                // break out if this is the last index
                if (j+1 == adapters.size()) {
                    reachedEnd = true;
                }

                break;
            }
        }

        connectionPossibilities *= getTrib(continuousValsFromThisIndex);
        if (reachedEnd)
            break;
    }

    return connectionPossibilities;
}

int Day10::getTrib(int value) {
    // Tribonacci sequence
    //1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136
    int trib;
    //value++;

    if (value == 15)
        trib = 3136;
    else if (value == 14)
        trib = 1705;
    else if (value == 13)
        trib = 927;
    else if (value == 12)
        trib = 504;
    else if (value == 11)
        trib = 274;
    else if (value == 10)
        trib = 149;
    else if (value == 9)
        trib = 81;
    else if (value == 8)
        trib = 44;
    else if (value == 7)
        trib = 24;
    else if (value == 6)
        trib = 13;
    else if (value == 5)
        trib = 7;
    else if (value == 4)
        trib = 4;
    else if (value == 3)
        trib = 2;
    else if (value == 2)
        trib = 1;
    else if (value == 1)
        trib = 1;
    else if (value == 0)
        trib = 1;

    cout<<" = "<<value<<" trib("<<trib<<")"<<endl;
    return trib;
}