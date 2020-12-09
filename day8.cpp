//
// Created by sandw on 12/8/2020.
//

#include "day8.h"
#include "utilities.h"

using namespace std;

int Day8::calculate1(std::vector<std::string> input) {
    int accumulator = 0;
    vector<int> linesExecuted;

    for (int i = 0; i < input.size(); ++i) {

        // Try switching each nop or jmp command

        // if repeat line: fail,
        // log last change, clear acc, start over from beginning
        // check switching next jmp/nop from log


        // If we've already done this line, return acc value
        for (int j = 0; j < linesExecuted.size(); ++j) {
            if (linesExecuted[j] == i) {
                return accumulator;
            }
        }

        // log this line
        linesExecuted.push_back(i);

        string command;
        char sign;
        int value;

        // Parse command from input
        command = input[i].substr(0, 3);
        sign = input[i][4];
        value = stoi(input[i].substr(5, input[i].size()-1));

        if (command == "acc")
        {
            if (sign == '+')
                accumulator += value;
            else if (sign == '-')
                accumulator -= value;
        }
        else if (command == "jmp")
        {
            if (sign == '+')
                i += value - 1;
            else if (sign == '-')
                i -= value + 1;

            if (i >= input.size() || i < 0)
                throw "Exited program prematurely";
        }
    }

    return 0;
}

int Day8::calculate2(std::vector<std::string> input) {
    int accumulator = 0;
    vector<int> linesExecuted;
    vector<int> swapsTried;
    bool operatingOnSwap = false;

    for (int i = 0; i < input.size(); ++i) {

        // Try switching each nop or jmp command

        // if repeat line: fail,
        // log last change, clear acc, start over from beginning
        // check switching next jmp/nop from log

        // Check for infinite loop
        bool resetFromInfiniteLoop = false;
        for (int j = 0; j < linesExecuted.size(); ++j) {
            if (linesExecuted[j] == i) {

                accumulator = 0;
                i = -1;
                operatingOnSwap = false;
                linesExecuted.clear();
                resetFromInfiniteLoop = true;
            }
        }
        if (resetFromInfiniteLoop)
            continue;

        // log this line
        linesExecuted.push_back(i);

        string command;
        char sign;
        int value;

        // Parse command from input
        command = input[i].substr(0, 3);
        sign = input[i][4];
        value = stoi(input[i].substr(5, input[i].size()-1));

        if (command == "acc")
        {
            if (sign == '+')
                accumulator += value;
            else if (sign == '-')
                accumulator -= value;
        }
        else if (command == "jmp")
        {
            // Check if we should swap
            bool swapped = false;
            for (int j = 0; j < swapsTried.size(); ++j) {
                if (swapsTried[j] == i) {
                    swapped = true;
                }
            }

            // switching JMP to NOP, tag swap and just pass on
            if (!swapped && !operatingOnSwap) {
                swapsTried.push_back(i);
                operatingOnSwap = true;
                continue;
            }

            if (sign == '+')
                i += value - 1;
            else if (sign == '-')
                i -= value + 1;

            // out of bounds
            if (i >= input.size() || i < 0) {
                accumulator = 0;
                i = -1;
                operatingOnSwap = false;
                linesExecuted.clear();
            }
        }
        else if (command == "nop")
        {
            // Check if we should swap
            bool swapped = false;
            for (int j = 0; j < swapsTried.size(); ++j) {
                if (swapsTried[j] == i) {
                    swapped = true;
                }
            }

            // switching NOP to JMP, tag swap, jump
            if (!swapped && !operatingOnSwap) {
                swapsTried.push_back(i);
                if (sign == '+')
                    i += value - 1;
                else if (sign == '-')
                    i -= value + 1;

                // out of bounds
                if (i >= input.size() || i < 0) {
                    accumulator = 0;
                    i = -1;
                    operatingOnSwap = false;
                    linesExecuted.clear();
                }
            }
        }
    }

    return accumulator;
}