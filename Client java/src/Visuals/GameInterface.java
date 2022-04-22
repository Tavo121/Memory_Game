package Visuals;

import Connection.ClientRequests;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.Stack;

public class GameInterface {
    private JFrame Frame;
    private JLabel P1, P2, Name1, Name2, Score1, Score2, playerTurn, TURN;
    private int iSize, jSize, X = 110, Y = 10, Height = 130, Width = 100, Clicks = 0, i1, j1, i2, j2;
    private Stack<JLabel> labelList = new Stack<>();
    private static GameInterface instance;
    private final ClientRequests request = ClientRequests.getInstance();
    private Font font = new Font("default", Font.BOLD, 14);
    private final CardImages images = new CardImages();
    private final PowerUps powerUp = new PowerUps();
    private ArrayList<JLabel> Labels = new ArrayList<>(iSize*jSize);
    public int ID;
    public boolean turn, firstPair, gotID = false; //true=J1, false=J2


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
        ImageIcon icon = new ImageIcon("Marco.png");
        int count = 0; //fila
        while(count<iSize){
            for(int i=0; i<jSize; i++){//columna
                JLabel slot = new JLabel(icon);
                slot.setBounds(X,Y,70,100);
                int I = count;
                int J = i;
                slot.addMouseListener(new MouseListener() {
                    @Override
                    public void mouseClicked(MouseEvent e) {
                        request.requestCard(I, J);
                        Clicks++;
                        if(Clicks == 1){
                            i1 = I;
                            j1 = J;
                        }
                        if(Clicks == 2){
                            i2 = I;
                            j2 = J;
                            Clicks = 0;
                            request.requestCardValidation();
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

    public void addPoints(){
        if(turn){
            if(firstPair){
                addPowerUpButton("P2");
            }
            int score = Integer.parseInt(Score2.getText()) + 10;
            Score2.setText(String.valueOf(score));
        }else{
            if(firstPair){
                addPowerUpButton("P1");
            }
            int score = Integer.parseInt(Score1.getText()) + 10;
            Score1.setText(String.valueOf(score));
        }
    }

    public void swapCards() {
        try{
            Thread.sleep(1000);
        }catch(InterruptedException e){
            e.printStackTrace();
        }
        Labels.get((i1*5)+j1).setIcon(new ImageIcon("Marco.png"));
        Labels.get((i2*5)+j2).setIcon(new ImageIcon("Marco.png"));
    }

    private void addPowerUpButton(String player){ //Primer power up
        JButton firstPowerUp = new JButton();
        if(player.equals("P2")){
            firstPowerUp.setBounds(150,850, 40, 20);
            firstPowerUp.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    powerUp.firstPairOfCards(Score2);
                    firstPowerUp.setVisible(false);
                }
            });
            Frame.add(firstPowerUp);
            firstPair = false;
        }else{
            firstPowerUp.setBounds(10,850, 40, 20);
            firstPowerUp.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    powerUp.firstPairOfCards(Score1);
                    firstPowerUp.setVisible(false);
                }
            });
            Frame.add(firstPowerUp);
            firstPair = false;
        }
    }
}
