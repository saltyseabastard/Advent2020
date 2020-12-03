//
// Created by sandw on 12/2/2020.
//

#include "day2.h"
using namespace  std;

int Day2::calculate1(vector<string> input)
{
    int goodPasswords = 0;
    for (int i = 0; i < input.size(); ++i) {
        char matchChar;
        int minChar, maxChar;
        string password;

        string::size_type posDash = input[i].find('-');
        string::size_type posSpace = input[i].find(' ');
        string::size_type posColon = input[i].find(':');

        minChar = stoi(input[i].substr(0, posDash));
        maxChar = stoi(input[i].substr(posDash + 1, posSpace));
        matchChar = input[i].at(posSpace + 1);
        password = input[i].substr(posColon + 2);

        int matchingCharsInPassword = 0;
        for (int j = 0; j < password.size(); ++j) {
            if (password[j] == matchChar)
            {
                matchingCharsInPassword++;
            }
        }

        if (matchingCharsInPassword >= minChar && matchingCharsInPassword <= maxChar)
            goodPasswords++;

    }

    return goodPasswords;
}

int Day2::calculate2(vector<string> input)
{
    cout<<"TESTING"<<endl;
    int goodPasswords = 0;

    for (int i = 0; i < input.size(); ++i) {
        char matchChar;
        int minChar, maxChar;
        string password;

        string::size_type posDash = input[i].find('-');
        string::size_type posSpace = input[i].find(' ');
        string::size_type posColon = input[i].find(':');

        minChar = stoi(input[i].substr(0, posDash));
        maxChar = stoi(input[i].substr(posDash + 1, posSpace));
        matchChar = input[i].at(posSpace + 1);
        password = input[i].substr(posColon + 2);
        password = password.substr(0, password.size()-1); // Get rid of /r in password

        if ((password[minChar - 1] == matchChar || password[maxChar - 1] == matchChar) &&
            !(password[minChar - 1] == matchChar && password[maxChar - 1] == matchChar)) {
            goodPasswords++;
            cout<<"TEST min="<<minChar<<" max="<<maxChar<<" match="<<matchChar<<" "<<password;
            cout<<" GOOD: "<<goodPasswords<<endl;
        }
        else
            cout<<"min="<<minChar<<" max="<<maxChar<<" match="<<matchChar<<" "<<password<<endl;
    }

    return goodPasswords;
}