package Visuals;

import Connection.ClientRequests;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;

public class GameInterface {
    private JFrame Frame;
    private JLabel P1, P2, Name1, Name2, Score1, Score2, playerTurn, TURN;
    private int iSize, jSize, X = 110, Y = 10, Height = 130, Width = 100, Clicks = 0;
    private static GameInterface instance;
    private final ClientRequests request = ClientRequests.getInstance();
    private Font font = new Font("default", Font.BOLD, 14);
    private final CardImages images = new CardImages();
    public int ID;
    public boolean turn, gotID = false; //true=J1, false=J2


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
        Name1.setFont(font);
        Name2.setFont(font);
        Name1.setForeground(Color.BLUE);
        Name2.setForeground(Color.RED);
        Frame.add(Name1);
        Frame.add(Name2);
        setScores();
        setPlayerTurn();
    }

    public void setMatrixI_J(int matrixI, int matrixJ){
        iSize = matrixI;
        jSize = matrixJ;
    }

    public void setScores(){
        Score1 = new JLabel("0");
        Score2 = new JLabel("0");
        Score1.setBounds(10,830, 20,20);
        Score2.setBounds(150,830, 20,20);
        Score1.setFont(font);
        Score2.setFont(font);
        Score1.setForeground(Color.BLUE);
        Score2.setForeground(Color.RED);
        Frame.add(Score1);
        Frame.add(Score2);
    }

    public void setPlayerTurn(){
        playerTurn = new JLabel("Turno");
        TURN = new JLabel();
        playerTurn.setBounds(350, 765, 100, 25);
        TURN.setBounds(350, 790, 100,25);
        playerTurn.setFont(font);
        TURN.setFont(font);
        if(turn){
            TURN.setText(Name1.getText());
            TURN.setForeground(Color.BLUE);
        }else{
            TURN.setText(Name2.getText());
            TURN.setForeground(Color.RED);
        }
        Frame.add(playerTurn);
        Frame.add(TURN);
    }

    public void createCardSlots(){
        ArrayList<JLabel> Labels = new ArrayList<>(iSize*jSize);
        ImageIcon icon = new ImageIcon("Marco.png");
        int count = 0; //fila
        while(count<iSize){
            for(int i=0; i<jSize; i++){//columna
                JLabel slot = new JLabel(icon);
                slot.setBounds(X,Y,70,100);
                int I = count;
                int J = i;
                int Id = ID;
                slot.addMouseListener(new MouseListener() {
                    @Override
                    public void mouseClicked(MouseEvent e) {
                        request.requestCard(I, J);
                        Clicks++;
                        if(Clicks == 2){
                            Clicks = 0;
                            switchTurn();
                        }
                        while(true){
                            if(!gotID){
                                continue;
                            }else{
                                slot.setIcon(images.getIcon(ID));
                                gotID = false;
                                break;
                            }
                        }
                    }

                    @Override
                    public void mousePressed(MouseEvent e) {

                    }

                    @Override
                    public void mouseReleased(MouseEvent e) {

                    }

                    @Override
                    public void mouseEntered(MouseEvent e) {

                    }

                    @Override
                    public void mouseExited(MouseEvent e) {

                    }
                });
                X = X + 120;
                Labels.add(slot);
            }
            Y = Y + 120;
            X = 110;
            count++;
        }
        for(JLabel item : Labels){
            Frame.add(item);
        }
    }

    private void switchTurn(){
        turn = !turn;
        if(turn){
            TURN.setText(Name1.getText());
            TURN.setForeground(Color.BLUE);
        }else{
            TURN.setText(Name2.getText());
            TURN.setForeground(Color.RED);
        }
    }

    public static void main(String[] args) {
        GameInterface Interface = new GameInterface();
        Interface.launchInterface(Integer.valueOf("6"),Integer.valueOf("5"));
    }
}
