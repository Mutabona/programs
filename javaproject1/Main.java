import javax.swing.*;
import java.awt.event.*;

public class Main {
    public static void main(String[] args) {
        JFrame window = new JFrame("FirstProgram");
        window.setBounds(5, 5, 500, 500);
        window.setLayout(null);
        JFileChooser fileChooser = new JFileChooser();
        JTextField firstField = new JTextField();
        JTextField secondField = new JTextField();
        firstField.setBounds(5,5,150,50);
        secondField.setBounds(5,65,150,50);

        window.add(firstField);
        window.add(secondField);

        window.setVisible(true);


    }
}