//
// Created by sandw on 12/7/2020.
//

#include "day7.h"
#include "utilities.h"

using namespace std;

unordered_map<string, vector<bagContents>> allBags;

int Day7::calculate1(std::vector<std::string> input) {

    int bagsChecked = 0;

    for (int i = 0; i < input.size(); ++i) {
        vector<string> tokens;

        tokens = Utilities::split(input[i], ' ');

        if (tokens.empty() || tokens.size() < 2) continue;

        // Get first bagContents
        string topColor = tokens[0] + " " + tokens[1];
        vector<bagContents> topContents;

        // go through words, split by bagContents
        for (int j = 0; j < tokens.size(); ++j) {
            // get bags after first
            if (j > 2 && tokens[j].find("bag") != string::npos){
                if (tokens[4] == "no") continue;

                bagContents currentBag;
                currentBag.color = tokens[j-2] + " " + tokens[j-1];
                currentBag.count = stoi(tokens[j-3]);

                topContents.push_back(currentBag);
            }
        }

        allBags.insert(make_pair(topColor, topContents));
        //cout<<topBag.color<<endl;
        bagsChecked++;
    }

/*    int total = 0;
    int tempCount = 0;

    // Do some crazy recursion

    unordered_map<string, double>:: iterator itr;
    cout << "\nAll Elements : \n";
    for (auto itr = allBags.begin(); itr != allBags.end(); itr++)
    {
        total += getBagContents(itr->first, &itr->second);
        tempCount++;
        //cout<<"TOP LEVEL "<<tempCount<<endl;
    }*/

    vector<bagContents>* shinyGoldContents = getBagByColor("shiny gold");
    int total = 0;

    for (int i = 0; i < shinyGoldContents->size(); ++i) {
        total += getBagContents2(&(*shinyGoldContents)[i]);
    }

    return total;
}

int Day7::getBagContents2(bagContents *contents) {

    vector<bagContents> *actualContents = getBagByColor(contents->color);

    int totalContents = 0;

    if (actualContents->size() == 0)
        return contents->count;

    for (int i = 0; i < actualContents->size(); ++i) {
        totalContents += getBagContents2(&(*actualContents)[i]);
    }

    return contents->count + contents->count * totalContents;
}

int Day7::getBagContents(string name, vector<bagContents> *contents) {

    // If it's gold, return 1
    if (name == "shiny gold") {
        return 0;
    }

    for (int i = 0; i < contents->size(); ++i) {
        if ((*contents)[i].color == "shiny gold")
            return 1;
    }

    for (int i = 0; i < contents->size(); ++i) {
        vector<bagContents>* actualContents = getBagByColor((*contents)[i].color);
        // If we found gold, return 1
        if (getBagContents((*contents)[i].color, actualContents) == 1)
            return 1;
    }

    // Didn't find gold
    return 0;
}

vector<bagContents>* Day7::getBagByColor(std::string coloredBag)
{
    return &allBags.at(coloredBag);

    throw std::runtime_error("Couldn't find the bagContents");
}