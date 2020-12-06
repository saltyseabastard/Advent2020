#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"

#include "day6.h"

using namespace std;

int main() {

    Day6 day;

    vector<string> dayInput = Utilities::getStringVectorFromFile("day6Input.txt");
    long answer = day.calculate2(dayInput);

    cout<<"ANSWER: "<<answer<<endl;

    return 0;
}

