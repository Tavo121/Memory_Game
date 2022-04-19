package Connection;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.*;
import java.net.Socket;

public class Client extends ResponseHandler implements Runnable {
    private final String HOST = "127.0.0.1";
    private final int PORT = 5050;
    private PrintWriter out;
    private BufferedReader in;
    private Socket Client;

    public Client(){
        try{
            System.out.println("Client started");
            Client = new Socket(HOST, PORT);
            out = new PrintWriter(Client.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(Client.getInputStream()));

        }catch(IOException e){
            e.printStackTrace();
        }
    }
    public void send(String text){
        out.println(text);
    }

    public void listen() {
        while(true){
            try{
                String response = in.readLine();
                JSONParser parser = new JSONParser();
                JSONObject JSONResponse = (JSONObject) parser.parse(response);
                handle(JSONResponse);
            }catch(IOException | ParseException e){
                e.printStackTrace();
            }
        }
    }

    @Override
    public void run() {
        listen();
    }
}
