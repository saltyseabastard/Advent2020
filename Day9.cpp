//
// Created by sandw on 12/9/2020.
//

#include "Day9.h"

using namespace std;

long Day9::calculate1(std::vector<std::string> input) {
    int preamble = 25;
    vector<long> xmas;

    for (int i = 0; i < input.size(); ++i) {
        xmas.push_back(stol(input[i]));
    }

    for (int i = preamble; i < xmas.size(); ++i) {

        bool valid = false;
        long current = xmas[i];

        for (int j = i - preamble; j < i; ++j) {

            long firstNumber = xmas[j];

            for (int k = i - preamble; k < i; ++k) {

                long secondNumber = xmas[k];

                if (firstNumber == secondNumber) continue;

                if (firstNumber + secondNumber == current) {
                    cout<<current<<" VALID"<<endl;
                    valid = true;
                    break;
                }
            }
        }

        if (!valid) {
            cout<<xmas[i]<<" NOT VALID"<<endl;
            return xmas[i];
        }
    }
}

long Day9::calculate2(std::vector<std::string> input) {
    long goal = 69316178;

    vector<long> xmas;
    vector<long> addedNumbers;

    for (int i = 0; i < input.size(); ++i) {
        if (stol(input[i]) < goal)
            xmas.push_back(stol(input[i]));
    }

    for (int i = 0; i < xmas.size(); ++i) {
        addedNumbers.push_back(xmas[i]);

        for (int j = i+1; j < xmas.size(); ++j)
        {
            addedNumbers.push_back(xmas[j]);
            long sum = accumulate(addedNumbers.begin(), addedNumbers.end(), 0);
            if (sum == goal) {
                // find min
                long min = 9999999999999;
                for (int k = 0; k < addedNumbers.size(); ++k) {
                    if (addedNumbers[k] < min)
                        min = addedNumbers[k];
                }

                // find max
                long max = -9999999999999;
                for (int k = 0; k < addedNumbers.size(); ++k) {
                    if (addedNumbers[k] > max)
                        max = addedNumbers[k];
                }

                return max + min;
            }
            else if (sum > goal)
            {
                continue;
            }
        }

        addedNumbers.clear();
    }

    return 0;
}
