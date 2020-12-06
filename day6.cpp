//
// Created by sandw on 12/6/2020.
//

#include "day6.h"
using namespace std;

int Day6::calculate1(std::vector<std::string> input) {

    int totalYes = 0;
    string yesInGroup = "";

    for (int i = 0; i < input.size(); ++i) {
        cout<<input[i]<<endl;

        // if input[i] is \n, add string to totalYes and debug
        if (input[i].size() == 1) {
            totalYes += yesInGroup.size();
            cout<<"FOUND "<<yesInGroup.size()<<endl;
            yesInGroup.clear();
        }

        // if the string does not contain any of these characters, add them
        for (int j = 0; j < input[i].size(); ++j) {
            if (input[i][j] == '\r' || input[i][j] == '\n')
                continue;

            if (yesInGroup.find(input[i][j]) == string::npos)
            {
                yesInGroup += input[i][j];
            }
        }
    }

    return totalYes;
}

int Day6::calculate2(std::vector<std::string> input) {

    int totalYes = 0;
    int groupCount = 0;
    vector<YesCount> yesCounts;

    for (int i = 0; i < input.size(); ++i) {
        cout<<input[i]<<endl;

        // if input[i] is \n, add string to totalYes and debug
        if (input[i].size() == 1) {

            for (int j = 0; j < yesCounts.size(); ++j) {
                if (yesCounts[j].count == groupCount)
                    totalYes++;
            }

            groupCount = 0;
            yesCounts.clear();
        }
        else
        {
            groupCount++;
        }


        // if the string does not contain any of these characters, add them
        for (int j = 0; j < input[i].size(); ++j) {
            if (input[i][j] == '\r' || input[i][j] == '\n')
                continue;

            bool alreadyContainedLetter = false;
            for (int k = 0; k < yesCounts.size(); ++k) {
                if (yesCounts[k].letter == input[i][j]) {
                    yesCounts[k].count++;
                    alreadyContainedLetter = true;
                    break;
                }
            }
            if (!alreadyContainedLetter)
            {
                YesCount yc;
                yc.count = 1;
                yc.letter = input[i][j];
                yesCounts.push_back(yc);
            }
        }
    }

    return totalYes;
}