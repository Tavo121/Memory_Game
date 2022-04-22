package Visuals;

import Connection.Client;
import Connection.ClientRequests;
import org.json.simple.JSONObject;
import java.util.Random;
import org.json.simple.parser.ParseException;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class StartingInterface {
    private JFrame Frame;
    private JLabel Background, UsernameText, Title, P1, P2;
    private JButton Play;
    private JTextField Player1, Player2;
    private int width, height;
    private Client ClientInstance;

    public StartingInterface(int width, int height, Client client){
        this.width = width;
        this.height = height;
        createFrame();
        createBackgroud();
        addUsernameTexts();
        createButton();
        createTextFields();
        ClientInstance = client;
    }

    public void createFrame(){
        Frame = new JFrame();
        Frame.setVisible(true);
        Frame.setTitle("Memory game");
        Frame.setLayout(null);
        Frame.setSize(width, height);
        Frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }

    public void createBackgroud(){
        Background = new JLabel();
        Background.setOpaque(true);
        Background.setBackground(Color.decode("#32a893"));
        Background.setBounds(0, 0, width, height);
        Frame.add(Background);

        Title = new JLabel("MEMORY GAME");
        Title.setBounds(95, 80, 400,50);
        Title.setFont(new Font("Default", Font.BOLD, 36));
        Background.add(Title);
    }

    public void addUsernameTexts(){
        UsernameText = new JLabel("Ingrese nombres de usuario");
        P1 = new JLabel("Jugador 1");
        P2 = new JLabel("Jugador 2");
        UsernameText.setBounds(110,150,300,30);
        P1.setBounds(115,250,100,30);
        P2.setBounds(295,250,100,30);
        UsernameText.setFont(new Font("default", Font.BOLD, 16));
        Background.add(UsernameText);
        Background.add(P1);
        Background.add(P2);
    }

    public void createButton(){
        Play = new JButton("Play");
        Play.setBounds(190,300,100,30);
        Background.add(Play);

        Play.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                if(Player1.getText().equals("") || Player2.getText().equals("")){
                    JOptionPane.showMessageDialog(Frame,"Favor ingrese los 2 nombres de usuario");
                }else{
                    ClientRequests resquest = ClientRequests.getInstance();
                    resquest.ClientInstance = ClientInstance;
                    JSONObject json = new JSONObject();
                    json.put("Type", "Names");
                    json.put("P1", Player1.getText());
                    json.put("P2", Player2.getText());
                    ClientInstance.send(json.toJSONString());
                    Frame.dispose();
                    resquest.requestMatrix();
                }
            }
        });
    }

    public void createTextFields(){
        Player1 = new JTextField();
        Player2 = new JTextField();
        Player1.setBounds(90,220,120,30);
        Player2.setBounds(270,220,120,30);
        Background.add(Player1);
        Background.add(Player2);
    }

}
