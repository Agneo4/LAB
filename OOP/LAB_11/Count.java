package LAB_11;

import java.awt.event.*;
import javax.swing.*;

public class Count extends JPanel {

    private final JButton button;
    private final JLabel label;
    private final JTextField t;
    private int count;

    public Count() {
        label = new JLabel("Counter");
        this.add(label);
        t=new JTextField(10);
        this.add(t);

        button = new JButton("Count");
        button.addActionListener(new MyButtonHandler());

        this.add(button);
    }

    /**
     *
     * @param args
     */
    public static void main(String[] args) {
        JFrame frame = new JFrame("Counter");
        frame.getContentPane().add(new Count());
        frame.setSize(300, 100);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

    }

    private class MyButtonHandler implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent event) {
            ++count;
            t.setText(Integer.toString(count));
        }
    }
}
