//
// Created by sandw on 12/1/2020.
//

#include "day1.h"
int Day1::calculate(std::vector<int> intVector)
{
    for (int i = 0; i < intVector.size(); i++) {
        for (int j = 0; j < intVector.size(); j++) {
            for (int k = 0; k < intVector.size(); k++) {
                if (intVector[i]+intVector[j]+intVector[k] == 2020)
                    return intVector[i]*intVector[j]*intVector[k];
            }
        }
    }

    return -1;
}