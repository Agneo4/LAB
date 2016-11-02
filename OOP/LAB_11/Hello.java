package LAB_11;

import javax.swing.*;

public class Hello {
    public static void main(String[] args) {
        JFrame frame = new JFrame("HelloWorldSwing");
        JLabel label = new JLabel("Hello World");
        frame.add(label);
        frame.setSize(400, 50);
        frame.setVisible(true);
    }
}
