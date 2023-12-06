/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> input = {

"Time:        62     64     91     90",
"Distance:   553   1010   1473   1074"

/*
"Time:      7  15   30",
"Distance:  9  40  200"
*/
};

int main()
{

    unsigned int total = 1;

    std::regex space("[ :]+");
    std::sregex_token_iterator end;

    std::sregex_token_iterator timesIter(input[0].begin(), input[0].end(), space, -1);
    std::vector<std::string> timesSplit(timesIter, end);

    std::sregex_token_iterator distsIter(input[1].begin(), input[1].end(), space, -1);
    std::vector<std::string> distsSplit(distsIter, end);

    for ( int i = 1 ; i < timesSplit.size() ; ++i ) {
        float raceTime = atof(timesSplit[i].c_str());
        float raceDistance = atof(distsSplit[i].c_str());
        
        int minSpeed = std::ceil(0.5 * (raceTime - sqrt(raceTime*raceTime-4.0*raceDistance)) + 0.0001);
        int maxSpeed = std::floor(0.5 * (raceTime + sqrt(raceTime*raceTime-4.0*raceDistance)) - 0.0001);

        std::cout << raceTime << ", " << raceDistance << ", " << minSpeed << ", " << maxSpeed << ", " << maxSpeed - minSpeed + 1 << std::endl;
        
        total = total * (maxSpeed - minSpeed + 1);
    }

    std::cout << "Part 1 Total: " << total << std::endl;

    input[0].erase(std::remove_if(input[0].begin(), input[0].end(), isspace), input[0].end());
    input[1].erase(std::remove_if(input[1].begin(), input[1].end(), isspace), input[1].end());

    std::sregex_token_iterator timesIter2(input[0].begin(), input[0].end(), space, -1);
    std::vector<std::string> timesSplit2(timesIter2, end);

    std::sregex_token_iterator distsIter2(input[1].begin(), input[1].end(), space, -1);
    std::vector<std::string> distsSplit2(distsIter2, end);

    double raceTime = atof(timesSplit2[1].c_str());
    double raceDistance = atof(distsSplit2[1].c_str());
        
    unsigned int minSpeed = std::ceil(0.5 * (raceTime - sqrt(raceTime*raceTime-4.0*raceDistance)) + 0.0001);
    unsigned int maxSpeed = std::floor(0.5 * (raceTime + sqrt(raceTime*raceTime-4.0*raceDistance)) - 0.0001);
        
    std::cout << std::fixed << std::setprecision(0) << raceTime << ", " << raceDistance << ", " << minSpeed << ", " << maxSpeed << ", " << maxSpeed - minSpeed + 1 << std::endl;

    std::cout << "Part 2 Total: " << maxSpeed - minSpeed + 1 << std::endl;
    return 0;
}
