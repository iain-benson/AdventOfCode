// Online C++ compiler to run C++ program online
#include <iostream>
#include <iterator>
#include <regex>
#include <set>
#include <string>
#include <vector>

std::vector<std::string> input = {
"seeds: 79 14 55 13"
"",
"seed-to-soil map:",
"50 98 2",
"52 50 48",
"",
"soil-to-fertilizer map:",
"0 15 37",
"37 52 2",
"39 0 15",
"",
"fertilizer-to-water map:",
"49 53 8",
"0 11 42",
"42 0 7",
"57 7 4",
"",
"water-to-light map:",
"88 18 7",
"18 25 70",
"",
"light-to-temperature map:",
"45 77 23",
"81 45 19",
"68 64 13",
"",
"temperature-to-humidity map:",
"0 69 1",
"1 0 69",
"",
"humidity-to-location map:",
"60 56 37",
"56 93 4",
};

int main() {

    std::set<int> seeds;
    std::map<int, int> seedToSoil;
    std::map<int, int> soilToFert;
    std::map<int, int> fertToWater;
    std::map<int, int> waterToLight;
    std::map<int, int> lightToTemp;
    std::map<int, int> tempToHumid;
    std::map<int, int> humidToLoc;
    
    std::map<int, int>* currentMap;

    for ( auto line: input ) {
        std::regex space("[ ]");
        std::regex colon("[:]");
        std::sregex_token_iterator iter1(line.begin(), line.end(), colon, -1);
        std::sregex_token_iterator end;
        std::vector<std::string> split(iter1, end);
        
        if ( split[0] == "seeds" ) {
            std::sregex_token_iterator iter2(split[1].begin(), split[1].end(), space, -1);
            std::vector<std::string> seedVec(iter2, end);
            
            for ( auto seed: seedVec ) {
                if ( seed != "" ) {
                    seeds.insert(atoi(seed.c_str()));
                }
            }
        } else if (split[0] == "seed-to-soil map") {
            currentMap = &seedToSoil;
        } else if (split[0] == "soil-to-fertilizer map") {
            currentMap = &soilToFert;
        } else if (split[0] == "fertilizer-to-water map") {
            currentMap = &fertToWater;
        } else if (split[0] == "water-to-light map") {
            currentMap = &waterToLight;
        } else if (split[0] == "light-to-temperature map") {
            currentMap = &lightToTemp;
        } else if (split[0] == "temperature-to-humidity map") {
            currentMap = &tempToHumid;
        } else if (split[0] == "humidity-to-location map") {
            currentMap = &humidToLoc;
        } else if (split[0] != "") {
            
            std::sregex_token_iterator iter3(line.begin(), line.end(), space, -1);
            std::vector<std::string> mapping(iter3, end);
            
            int destStart = atoi(mapping[0].c_str());
            int srcStart = atoi(mapping[1].c_str());
            int len = atoi(mapping[2].c_str());
            
            for ( int dest = destStart, src = srcStart ;
                  src < srcStart + len ;
                  ++src, ++dest ) {
                currentMap->emplace(std::make_pair(src, dest));
            }
            
        }
    }

    int minLoc = 999;

    for ( auto seed: seeds ) {
        
        int soil = seedToSoil.count(seed)?seedToSoil[seed]:seed;
        int fert = soilToFert.count(soil)?soilToFert[soil]:soil;
        int water = fertToWater.count(fert)?fertToWater[fert]:fert;
        int light = waterToLight.count(water)?waterToLight[water]:water;
        int temp = lightToTemp.count(light)?lightToTemp[light]:light;
        int humid = tempToHumid.count(temp)?tempToHumid[temp]:temp;
        int loc = humidToLoc.count(humid)?humidToLoc[humid]:humid;
        
        minLoc = std::min(minLoc, loc);
    }
    
    std::cout << "Minimum location: " << minLoc << std::endl;
    
    return 0;
}



