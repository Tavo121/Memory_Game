package Visuals;

import javax.swing.*;
/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: Java.
 * Clase PowerUps.
 * @author Gustavo Alvarado Aburto.
 * @version 1.0.
 *
 * Descripcion: Esta clase se encarga de ejecutar la funcion de los powerUps implementados.
 */
public class PowerUps {
    /**
     * Este metodo se encarga de asignar 30 puntos mas al jugador que encuentre la primera pareja de cartas
     * @param playerScore Label del puntaje del jugador.
     */
    public void firstPairOfCards(JLabel playerScore){
        int score = Integer.parseInt(playerScore.getText()) + 30;
        playerScore.setText(String.valueOf(score));
    }
}
