//
// Created by tavo on 28/3/22.
//

#include <string>
#include "../headers/CommandHandler.h"
#include "../headers/Server.h"
#include <nlohmann/json.hpp>
#include <iostream>

using namespace std;
using namespace nlohmann;

void CommandHandler::Handle(string Json){
    json JSONParsed = json::parse(Json);
    JSON = JSONParsed;
    CommandMap[JSONParsed["Type"]]();
}

 void CommandHandler::SaveNames(json JSON) {
    J1 = JSON["P1"];
    J2 = JSON["P2"];
}

void CommandHandler::sendMatrixSize(){
    json JSONResponse;
    JSONResponse["Type"] = "MatrixSize";
    JSONResponse["Matrix"] = "5x6";
    string response = to_string(JSONResponse);
    Server::sender(response, server);
}

void CommandHandler::sendNames(){
    json JSONResponse;
    JSONResponse["Type"] = "PlayerNames";
    JSONResponse["P1"] = J1;
    JSONResponse["P2"] = J2;
    string response =  to_string(JSONResponse);
    Server::sender(response, server);
}

CommandHandler::CommandHandler(int socket) {
    server = socket;
    CommandMap["Names"] = [this]() {SaveNames(JSON);};
    CommandMap["MatrixSize"] = [this]() {sendMatrixSize();};
    CommandMap["PlayerNames"] = [this]() {sendNames();};
}
