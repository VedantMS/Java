import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

class String_awt extends JFrame implements ActionListener{
    JTextField t1, t2, t3;
    JButton b1, b2;

    String_awt() {
        t1 = new JTextField();
        t2 = new JTextField();
        t3 = new JTextField();
        b1 = new JButton("Concatenation");
        b2 = new JButton("Reverse");

        t1.setBounds(50, 50, 100, 30);
        t2.setBounds(50, 80, 100, 30);
        t3.setBounds(50, 120, 200, 30);
        b1.setBounds(50, 150, 200, 40);
        b2.setBounds(50, 180, 200, 40);

        add(t1);
        add(t2);
        add(t3);
        add(b1);
        add(b2);

        b1.addActionListener(this);
        b2.addActionListener(this);

        setTitle("String AWT");
        setSize(400, 400);
        setLayout(null);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String a = t1.getText();
        String b = t2.getText();
        String c;
        c = a.concat(b);
        if(e.getSource() == b1) {
            t3.setText(c);
        }
        if(e.getSource() == b2) {
            StringBuilder s = new StringBuilder(c);
            t3.setText(s.reverse().toString());
        }
    }

    public static void main(String args[]) {
        new String_awt();
    }
}
