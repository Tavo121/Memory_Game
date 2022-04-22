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
/**
 * Este metodo se encarga de ejecutar una accion en funcion a el tipo de peticion.
 * @param Json Estructura json en string que contiene la peticion del cliente.
 */
void CommandHandler::Handle(string Json){
    json JSONParsed = json::parse(Json);
    JSON = JSONParsed;
    CommandMap[JSONParsed["Type"]]();
}

 void CommandHandler::SaveNames(json JSON) { //Guardado y muestra de nombres en la interfaz del servidor.
    J1 = JSON["P1"];
    J2 = JSON["P2"];
    Instance->setPlayerNames(J1, J2);
    for(int i=0; i<pagedArray.positionsInMemory.size(); i++){
        Instance->setCardsInMemory(pagedArray.positionsInMemory[i]);
    }
}
/**
 * Este metodo se encarga de responder a la peticion del tamaño de la matriz.
 */
void CommandHandler::sendMatrixSize(){
    json JSONResponse;
    JSONResponse["Type"] = "MatrixSize";
    JSONResponse["Matrix"] = "6x5";
    string response = to_string(JSONResponse);
    Server::sender(response, server);
}

/**
 * Este metodo se encarga de responder a la peticion de los nombres de jugadores.
 */
void CommandHandler::sendNames(){
    json JSONResponse;
    JSONResponse["Type"] = "PlayerNames";
    JSONResponse["P1"] = J1;
    JSONResponse["P2"] = J2;
    string response =  to_string(JSONResponse);
    Server::sender(response, server);
}

void CommandHandler::sendCardImage() {
    json JSONResponse;
    JSONResponse["Type"] = "ID";
    JSONResponse["ID"] = pagedArray(JSON["I"], JSON["J"]);
    string response =  to_string(JSONResponse);
    Server::sender(response, server);
}

/**
 * Constructor de la clase, almacena instancias necesarias y crea el HashMap con los metodos para las peticiones.
 * @param socket socket del servidor para envio de datos.
 * @param windowInstance instancia de la ventana del servidor para realizar modificaciones a la misma.
 */
CommandHandler::CommandHandler(int socket, ServerInterface* windowInstance) {
    server = socket;
    Instance = windowInstance;
    CommandMap["Names"] = [this]() {SaveNames(JSON);};
    CommandMap["MatrixSize"] = [this]() {sendMatrixSize();};
    CommandMap["PlayerNames"] = [this]() {sendNames();};
    CommandMap["Card"] = [this]() {sendCardImage();};
}
