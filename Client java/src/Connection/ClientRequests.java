package Connection;

import org.json.simple.JSONObject;
/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: Java.
 * Clase ClientRequests.
 * @author Gustavo Alvarado Aburto.
 * @version 1.0.
 *
 * Descripcion: Esta clase se encarga enviar las peticiones del cliente al servidor.
 */
public class ClientRequests {
    private JSONObject request;
    private static ClientRequests instance;
    public Client ClientInstance;

    public static ClientRequests getInstance(){
        if(instance == null){
            instance = new ClientRequests();
            return instance;
        }else{
            return instance;
        }
    }

    private ClientRequests(){
    }

    public void requestMatrix(){
        request = new JSONObject();
        request.put("Type", "MatrixSize");
        ClientInstance.send(request.toJSONString());
    }

    public void requestNames(){
        request = new JSONObject();
        request.put("Type", "PlayerNames");
        ClientInstance.send(request.toJSONString());
    }

    public void requestCard(int i, int j){
        request = new JSONObject();
        request.put("Type", "Card");
        request.put("I", i);
        request.put("J", j);
        ClientInstance.send(request.toJSONString());
    }

    public void requestCardValidation(){
        request = new JSONObject();
        request.put("Type", "Validate");
        ClientInstance.send(request.toJSONString());
    }
}
