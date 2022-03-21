import java.io.*;
import java.net.Socket;

public class Client {
    private final String HOST = "127.0.0.1";
    private final int PORT = 5000;
    private PrintWriter out;
    private BufferedReader in;

    public Client(){
        try{
            Socket sc = new Socket(HOST, PORT);

            out = new PrintWriter(sc.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(sc.getInputStream()));

            while(true){
                System.out.println("Server: " + in.readLine());

                System.out.println("Enter a msg: ");
                BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
                String msg = reader.readLine();

                out.println(msg);

                if(msg.equals("Exit")){
                    break;
                }
            }
            sc.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}
