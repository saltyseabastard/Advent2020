#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"

using namespace std;

int main() {

    Day4 day;

    vector<string> dayInput = Utilities::getStringVectorFromFile("day4Input.txt");
    long answer = day.calculate1(dayInput);

    cout<<"ANSWER: "<<answer<<endl;

    return 0;
}

