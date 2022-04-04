//
// Created by tavo on 28/3/22.
//

#ifndef MEMORY_GAME_COMMANDHANDLER_H
#define MEMORY_GAME_COMMANDHANDLER_H

#include <functional>
#include <map>
#include <nlohmann/json.hpp>

using namespace std;
using namespace nlohmann;

class CommandHandler {
public:
    void Handle(string json);
    string J1, J2;
    CommandHandler();

private:
    map<string, function<void()>> CommandMap;
    void SaveNames(json JSON);
    json JSON;
};


#endif //MEMORY_GAME_COMMANDHANDLER_H
