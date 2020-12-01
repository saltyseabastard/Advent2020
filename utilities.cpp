//
// Created by sandw on 12/1/2020.
//

#include "utilities.h"

vector<int> Utilities::getIntVectorFromFile(string filename) {
    string line_;
    vector<int> intVector_;
    ifstream input_ (filename);

    if (input_.is_open())
    {
        while (getline(input_, line_))
        {
            int i = std::stoi(line_);
            intVector_.push_back(i);
            cout<<i<<endl;
        }

        input_.close();
    }

    return intVector_;
}