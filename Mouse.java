import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Mouse extends JFrame {
    JLabel l;
    JTextField t;

    Mouse() {
        l = new JLabel();
        l.setBounds(40, 20, 120, 40);

        t = new JTextField();
        t.setBounds(40, 80, 200, 40);
        t.setEditable(false);

        setTitle("Mouse Location");
        setSize(300, 300);
        setLayout(null);
        setVisible(true);
        add(l);
        add(t);

        addMouseMotionListener(new MouseMotionAdapter() {
            public void mouseMoved(MouseEvent e) {
                int x = e.getX();
                int y = e.getY();
                l.setText("X: " + x + "    " + "Y: " + y);
            }
        });

        addMouseListener(new MouseAdapter() {

            public void mouseClicked(MouseEvent e) {
                int x = e.getX();
                int y = e.getY();
                t.setText("Mouse Clicked: " + x + "    " + y);
            }
        });

    }

    public static void main(String[] args) {
        new Mouse();
    }
}
