//
// Created by sandw on 12/4/2020.
//

#include "day4.h"
using namespace std;

int Day4::calculate1(std::vector<std::string> input)
{
    vector<string> passports;
    string passport;

    for (int i = 0; i < input.size(); ++i) {
        // parses out the blank lines
        if (input[i].size() > 2)
        {
            // parse out /r/n
            passport += input[i].substr(0, input[i].size() - 1);
            passport += " ";
        }
        else
        {
            passports.push_back(passport);
            passport.clear();
        }
    }

    int validPassports = 0;
    for (int i = 0; i < passports.size(); ++i) {
        //cout<<passports[i]<<endl;
        bool valid = validatePassport(passports[i]);
        if (valid)
            validPassports++;

        //cout<<valid<<endl;
    }

    return validPassports;
}

bool Day4::validatePassport(string passport)
{
    /*
     *  byr (Birth Year)
        iyr (Issue Year)
        eyr (Expiration Year)
        hgt (Height)
        hcl (Hair Color)
        ecl (Eye Color)
        pid (Passport ID)
     */

/*    std::size_t byr = passport.find("byr");
    std::size_t iyr = passport.find("iyr");
    std::size_t eyr = passport.find("eyr");
    std::size_t hgt = passport.find("hgt");
    std::size_t hcl = passport.find("hcl");
    std::size_t ecl = passport.find("ecl");
    std::size_t pid = passport.find("pid");

    return (byr!=std::string::npos && iyr!=std::string::npos && eyr!=std::string::npos &&
            hgt!=std::string::npos && hcl!=std::string::npos && ecl!=std::string::npos &&
            pid!=std::string::npos);*/


// split by space into arrays
    vector<string> fields;
    size_t pos = 0;
    while ((pos = passport.find(" ")) != string::npos)
    {
        fields.push_back(passport.substr(0, pos));
        passport.erase(0, pos + 1);
    }

// invalidate array with count 7 if no cid
    if (fields.size() < 7) return false;

// invalidate if size is 7 and array contains CID (meaning it's missing a different field)
    if (fields.size() == 7)
    {
        for (int i = 0; i < fields.size(); ++i) {
            if ((pos = fields[i].find("cid")) != string::npos) {
                return false;
            }
        }
    }
// size is 7 or 8, validate remaining fields
    for (int i = 0; i < fields.size(); ++i) {
        if (fields[i].find("byr") != string::npos) {
            int year = stoi(fields[i].substr(fields[i].find(":") + 1));
            if (year < 1920 || year > 2002){
                cout<<"BYR out of range 1920 - 2002"<<endl;
                return false;
            }

        }
        if (fields[i].find("iyr") != string::npos) {
            int year = stoi(fields[i].substr(fields[i].find(":") + 1));
            if (year < 2010 || year > 2020){
                cout<<"IYR out of range 2010 - 2020"<<endl;
                return false;
            }

        }
        if (fields[i].find("eyr") != string::npos) {
            int year = stoi(fields[i].substr(fields[i].find(":") + 1));
            if (year < 2020 || year > 2030){
                cout<<"EYR out of range 2020 - 2030"<<endl;
                return false;
            }

        }
        if (fields[i].find("hgt") != string::npos) {
            if (fields[i].find("cm") != string::npos) {
                int hgt = stoi(fields[i].substr(fields[i].find(":") + 1));
                if (hgt < 150 || hgt > 193) {
                    cout << "HGT out of range CM 150 - 193" << endl;
                    return false;
                }
            }

            if (fields[i].find("in") != string::npos){
                int hgt = stoi(fields[i].substr(fields[i].find(":") + 1));
                if (hgt < 59 || hgt > 76) {
                    cout<<"HGT out of range IN 59-76"<<endl;
                    return false;
                }
            }
        }
        if (fields[i].find("hcl") != string::npos) {
            if (fields[i].find("#") == string::npos)
                return false;
            string hex = fields[i].substr(fields[i].find("#") + 1);
            for (int j = 0; j < hex.size(); ++j) {
                if (isxdigit(hex[j] == 0))
                {
                    cout<<"HCL contained invalid digit"<<endl;
                    return false;
                }
            }
        }
        if (fields[i].find("ecl") != string::npos) {
            string eye = fields[i].substr(fields[i].find(":") + 1);
            std::size_t amb = fields[i].find("amb");
            std::size_t blu = fields[i].find("blu");
            std::size_t brn = fields[i].find("brn");
            std::size_t gry = fields[i].find("gry");
            std::size_t grn = fields[i].find("grn");
            std::size_t hzl = fields[i].find("hzl");
            std::size_t oth = fields[i].find("oth");

            if (amb==string::npos && blu==string::npos && brn==string::npos &&
                gry==string::npos && grn==string::npos && hzl==string::npos &&
                oth==string::npos) {
                cout<<"ECL "<<eye<< " was invalid"<<endl;
                return false;
            }
        }
        if (fields[i].find("pid") != string::npos) {
            string pid = fields[i].substr(fields[i].find(":") + 1);

            if (pid.size() != 9) {
                cout<<"pid count was != 9"<<endl;
                return false;
            }
        }


    }

    string fullCorrect;
    for (int j = 0; j < passport.size(); ++j) {
        fullCorrect+=passport[j];
    }

    cout<<"\nCORRECT " <<fullCorrect<<"\n"<<endl;
    return true;
    //102 not correct
}