#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
#include "day1.h"
#include "day2.h"
#include "day3.h"

using namespace std;

int main() {

    Day3 d3;

    vector<string> dayInput = Utilities::getStringVectorFromFile("day3Input.txt");
    long answer = d3.calculate2(dayInput);

    cout<<"ANSWER: "<<answer<<endl;

    return 0;
}
