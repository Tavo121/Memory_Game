package Connection;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.*;
import java.net.Socket;
/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: Java.
 * Clase Client, hereda ResponseHandler.
 * @author Gustavo Alvarado Aburto.
 * @version 1.0.
 *
 * Descripcion: Esta clase se encarga establecer al conexion al puerto habilitado por el servidor.
 */
public class Client extends ResponseHandler implements Runnable {
    private final String HOST = "127.0.0.1";
    private final int PORT = 5050;
    private PrintWriter out;
    private BufferedReader in;
    private Socket Client;

    /**
     * Constructor, inicializa los componentes necesarios para la conexion.
     */
    public Client(){
        try{
            System.out.println("Client started");
            Client = new Socket(HOST, PORT); //socket de cliente.
            out = new PrintWriter(Client.getOutputStream(), true); //canal de envio de datos.
            in = new BufferedReader(new InputStreamReader(Client.getInputStream())); //canal de recepcion de datos.

        }catch(IOException e){
            e.printStackTrace();
        }
    }

    public void send(String text){
        out.println(text); //envio de peticiones al servidor, formato JSON string.
    }

    /**
     * Este metodo se encarga de mantenerse antento a las respuestar del servidor y el manejo de las mismas.
     */
    public void listen() {
        while(true){
            try{
                String response = in.readLine();
                JSONParser parser = new JSONParser();
                JSONObject JSONResponse = (JSONObject) parser.parse(response); //conversion de respuesta del servidor a JSON
                handle(JSONResponse); //manejo de la respuesta recibida del servidor.
            }catch(IOException | ParseException e){
                e.printStackTrace();
            }
        }
    }

    /**
     * Hilo que mantiene la ejecucion del metodo listen.
     */
    @Override
    public void run() {
        listen();
    }
}
