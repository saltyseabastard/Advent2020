#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
#include "day1.h"

using namespace std;

int main() {

    Day1 d1;

    vector<int> day1Input = Utilities::getIntVectorFromFile("day1Input.txt");
    int multiple = d1.calculate(day1Input);

    cout<<multiple<<endl;

    return 0;
}
