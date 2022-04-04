//
// Created by tavo on 28/3/22.
//

#include <string>
#include "headers/CommandHandler.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include "headers/Server.h"

using namespace std;
using namespace nlohmann;

void CommandHandler::Handle(string Json){
    json JSONParsed = json::parse(Json);
    JSON = JSONParsed;
    CommandMap[JSONParsed["Type"]]();
}

CommandHandler::CommandHandler() {
    CommandMap["Names"] = [this]() {SaveNames(JSON);};
}

 void CommandHandler::SaveNames(json JSON) {
    J1 = JSON["P1"];
    J2 = JSON["P2"];
    cout << J1 << J2 << std::endl;

}
