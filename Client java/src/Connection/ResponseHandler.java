package Connection;

import Visuals.GameInterface;
import org.json.simple.JSONObject;
import java.util.HashMap;
/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: Java.
 * Clase ResponseHandler.
 * @author Gustavo Alvarado Aburto.
 * @version 1.0.
 *
 * Descripcion: Esta clase se encarga de manejar las respuestas recibidas del servidor.
 */
public class ResponseHandler {
    private final HashMap<String, Runnable> responseMap;
    private JSONObject json;
    private GameInterface GameInstance;

    /**
     * Constructor, se encarga de crear un HashMap que almacena las acciones para las respustas del servidor.
     */
    public ResponseHandler(){
        responseMap = new HashMap<>();
        responseMap.put("MatrixSize", this::getMatrix);
        responseMap.put("PlayerNames", this::getNames);
        responseMap.put("ID", this::getID);
    }

    /**
     * Este metodo se encarga de manejar las repuestas recibidas del servidor y ejecutar una accion en funcion de esta.
     * @param response repuesta del servidor en formato JSON.
     */
    public void handle(JSONObject response){
        json = response;
        responseMap.get(json.get("Type")).run();
    }

    /**
     * Este metodo se encarga de obtener el tamaño la matriz y lanzar la interfaz del juego.
     */
    private void getMatrix(){
        String size = (String) json.get("Matrix");
        String[] rowCol = size.split("x");
        GameInstance = GameInterface.getInstance();
        GameInstance.launchInterface(Integer.valueOf(rowCol[0]), Integer.valueOf(rowCol[1]));
    }

    private void getNames(){ //Obtiene los nombres de los jugadores y los muestra en la interfaz de juego.
        GameInstance.setPlayerNames((String) json.get("P1"), (String) json.get("P2"));
    }

    private void getID(){
        System.out.println(json.get("ID"));
    }
}
