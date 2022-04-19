package Visuals;

import Connection.ClientRequests;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class GameInterface {
    private JFrame Frame;
    private JLabel P1, P2, Name1, Name2;
    private int iSize, jSize, X = 20, Y = 10, Height = 130, Width = 100;
    private static GameInterface instance;
    private final ClientRequests request = ClientRequests.getInstance();

    /**
     * Patron Singleton
     * @return retorna una instancia a la clase GameInterface
     */
    public static GameInterface getInstance(){
        if(instance == null){
            instance = new GameInterface();
            return instance;
        }else{
            return instance;
        }
    }

    private GameInterface(){

    }

    public void launchInterface(int matrixI, int matrixJ){
        createFrame();
        createPlayerLabels();
        setMatrixI_J(matrixI, matrixJ);
        createCardSlots();
        request.requestNames();
    }

    public void createFrame(){
        Frame = new JFrame();
        Frame.setSize(800,1000);
        Frame.setVisible(true);
        Frame.setResizable(false);
        Frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        Frame.setLayout(null);
    }

    public void createPlayerLabels(){
        Font font = new Font("default", Font.BOLD, 16);
        P1 = new JLabel("Jugador 1");
        P2 = new JLabel("Jugador 2");
        P1.setFont(font);
        P2.setFont(font);
        P1.setBounds(10,765,100,20);
        P2.setBounds(150,765,100,20);
        Frame.add(P1);
        Frame.add(P2);
    }

    public void setPlayerNames(String J1, String J2){
        Name1 = new JLabel(J1);
        Name2 = new JLabel(J2);
        Name1.setBounds(10, 790, 80, 20);
        Name2.setBounds(150, 790, 80, 20);
        Name1.setFont(new Font("default", Font.BOLD, 14));
        Name2.setFont(new Font("default", Font.BOLD, 14));
        Name1.setForeground(Color.BLUE);
        Name2.setForeground(Color.RED);
        Frame.add(Name1);
        Frame.add(Name2);
    }

    public void setMatrixI_J(int matrixI, int matrixJ){
        iSize = matrixI;
        jSize = matrixJ;
    }

    public void createCardSlots(){
        ArrayList<JLabel> Labels = new ArrayList<>(iSize*jSize);
        ImageIcon icon = new ImageIcon("Marco.png");
        int count = 0;
        while(count<iSize){
            for(int i=0; i<jSize; i++){
                JLabel slot = new JLabel(icon);
                slot.setBounds(X,Y,100,145);
                X = X + 130;
                Labels.add(slot);
            }
            Y = Y + 150;
            X = 20;
            count++;
        }
        for(JLabel item : Labels){
            Frame.add(item);
        }
    }

    public static void main(String[] args) {
        GameInterface Interface = new GameInterface();
        Interface.launchInterface(Integer.valueOf("5"),Integer.valueOf("6"));
    }
}
