#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"

#include "day9.h"

using namespace std;

int main() {

    Day9 day;

    vector<string> dayInput = Utilities::getStringVectorFromFile("day9Input.txt");
    long answer = day.calculate2(dayInput);

    cout<<"ANSWER: "<<answer<<endl;

    return 0;
}

