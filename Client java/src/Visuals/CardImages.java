package Visuals;

import javax.swing.*;
import java.util.ArrayList;
import java.util.List;
/**
 * Instituto Tecnologico de Costa Rica
 * Area de Ingenieria en Computadores
 *
 * Lenguaje: Java.
 * Clase CardImages.
 * @author Gustavo Alvarado Aburto.
 * @version 1.0.
 *
 * Descripcion: Esta clase se encarga de generar la imagen para las tarjetas del tablero.
 */
public class CardImages {
    private final List<ImageIcon> list = new ArrayList<>(10);

    public CardImages(){
        list.add(new ImageIcon("/home/tavo/Documentos/Tarjetas/Card1.png"));
        list.add(new ImageIcon("/home/tavo/Documentos/Tarjetas/Card2.png"));
        list.add(new ImageIcon("/home/tavo/Documentos/Tarjetas/Card3.png"));
        list.add(new ImageIcon("/home/tavo/Documentos/Tarjetas/Card4.png"));
        list.add(new ImageIcon("/home/tavo/Documentos/Tarjetas/Card5.png"));
        list.add(new ImageIcon("/home/tavo/Documentos/Tarjetas/Card6.png"));
        list.add(new ImageIcon("/home/tavo/Documentos/Tarjetas/Card7.png"));
        list.add(new ImageIcon("/home/tavo/Documentos/Tarjetas/Card8.png"));
        list.add(new ImageIcon("/home/tavo/Documentos/Tarjetas/Card9.png"));
        list.add(new ImageIcon("/home/tavo/Documentos/Tarjetas/Card10.png"));
    }

    public ImageIcon getIcon(int ID){
        return list.get(ID-1);
    }
}
