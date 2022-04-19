import Connection.Client;
import Visuals.StartingInterface;

public class ClientMain {

    public static void main(String[] args) {
        Client client = new Client();
        Thread thread = new Thread(client);
        thread.start();
        StartingInterface window = new StartingInterface(500,500, client);
    }
}
