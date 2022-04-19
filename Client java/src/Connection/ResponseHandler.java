package Connection;

import Visuals.GameInterface;
import org.json.simple.JSONObject;

import java.util.HashMap;

public class ResponseHandler {
    private final HashMap<String, Runnable> responseMap;
    private JSONObject json;
    private GameInterface GameInstance;

    public ResponseHandler(){
        responseMap = new HashMap<>();
        responseMap.put("MatrixSize", this::getMatrix);
        responseMap.put("PlayerNames", this::getNames);
    }

    public void handle(JSONObject response){
        json = response;
        responseMap.get(json.get("Type")).run();
    }

    private void getMatrix(){
        String size = (String) json.get("Matrix");
        String[] rowCol = size.split("x");
        GameInstance = GameInterface.getInstance();
        GameInstance.launchInterface(Integer.valueOf(rowCol[0]), Integer.valueOf(rowCol[1]));
    }

    private void getNames(){
        GameInstance.setPlayerNames((String) json.get("P1"), (String) json.get("P2"));
    }
}
