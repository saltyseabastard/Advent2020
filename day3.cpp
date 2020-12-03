//
// Created by sandw on 12/3/2020.
//

#include "day3.h"
using namespace std;

int Day3::calculate1(std::vector<std::string> input, int columnIteration, int rowIteration) {
    int rows = input.size();
    int currentColumn = 0;
    int treesHit = 0;

    for (int i = rowIteration; i < rows; i+=rowIteration) {

        string currentLine = input[i].substr(0, input[i].size() - 1);

        currentColumn += columnIteration;
        currentColumn %= currentLine.size();

        bool hit = currentLine[currentColumn] == '#';
        treesHit += hit ? 1 : 0;
        char hitChar = hit ? 'X' : 'O';

        currentLine[currentColumn] = hitChar;

        cout<<currentLine<<endl;
    }

    return treesHit;
}

long Day3::calculate2(std::vector<std::string> input) {

    long tt11 = calculate1(input, 1, 1);
    cout<<"======================================================="<<endl;
    long tt31 = calculate1(input, 3, 1);
    cout<<"======================================================="<<endl;
    long tt51 = calculate1(input, 5, 1);
    cout<<"======================================================="<<endl;
    long tt71 = calculate1(input, 7, 1);
    cout<<"======================================================="<<endl;
    long tt12 = calculate1(input, 1, 2);

    cout<<tt11<<" "<<tt31<<" "<<tt51<<" "<<tt71<<" "<<tt12<<endl;

    return tt11*tt31*tt51*tt71*tt12;
}
