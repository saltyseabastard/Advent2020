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

vector<string> Utilities::getStringVectorFromFile(string filename) {
    string line_;
    vector<string> stringVector_;
    ifstream input_ (filename);

    if (input_.is_open())
    {
        while (getline(input_, line_))
        {
            stringVector_.push_back(line_);
            //cout<<line_<<endl;
        }

        input_.close();
    }

    return stringVector_;
}

vector<std::string> Utilities::split(const string &text, char sep) {
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}