#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"
#include "day5.h"

using namespace std;

int main() {

    Day5 day;

    vector<string> dayInput = Utilities::getStringVectorFromFile("day5Input.txt");
    long answer = day.calculate1(dayInput);

    cout<<"ANSWER: "<<answer<<endl;

    return 0;
}

