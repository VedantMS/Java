import java.awt.*;
import javax.swing.*;

class JavaMenu extends JFrame{
    JavaMenu() {
        JMenuBar mb = new JMenuBar();

        JMenu m1 = new JMenu("File");
        JMenu m2 = new JMenu("Edit");
        JMenu m3 = new JMenu("Help");
        JMenu m4 = new JMenu("About");

        JMenuItem mi1 = new JMenuItem("Open File");
        JMenuItem mi2 = new JMenuItem("Save File");
        JMenuItem mi3 = new JMenuItem("New");
        JMenuItem mi4 = new JMenuItem("Exit");
        m1.add(mi1);
        m1.add(mi2);
        m1.add(m2);

        m2.add(mi3);
        m2.add(mi4);

        mb.add(m1);
        mb.add(m3);
        mb.add(m4);

        setJMenuBar(mb);

        setSize(300, 300);
        setLayout(null);
        setVisible(true);
        setTitle("Menu Bar");
    }
}

class Java2
{
    public static void main(String[] args) {
        new JavaMenu();
    }
}
