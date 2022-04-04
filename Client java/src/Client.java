import java.io.*;
import java.net.Socket;

public class Client {
    private final String HOST = "127.0.0.1";
    private final int PORT = 5000;
    private PrintWriter out;
    private BufferedReader in;
    private Socket Client;

    public Client(){
        try{
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
}
