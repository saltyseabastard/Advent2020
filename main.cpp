#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"

#include "day10.h"

using namespace std;

int main() {

    Day10 day;

    vector<string> dayInput = Utilities::getStringVectorFromFile("day10Input.txt");
    long answer = day.calculate2(dayInput);

    cout<<"ANSWER: "<<answer<<endl;

    return 0;
}

