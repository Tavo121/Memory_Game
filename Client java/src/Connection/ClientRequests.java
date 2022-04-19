package Connection;

import org.json.simple.JSONObject;

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
}
