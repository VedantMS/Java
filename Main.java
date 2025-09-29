import java.awt.*;       // For AWT
import java.awt.event.*; // For ActionListener
import javax.swing.*;    // For Swing

public class Main extends JFrame implements ActionListener {
    private JLabel label;         // Swing label
    private JTextField textField; // Swing text field
    private JButton button;       // Swing button

    public Main() {
        // Set window title
        setTitle("AWT & Swing GUI Example");

        // Create components
        label = new JLabel("Enter your name:");
        textField = new JTextField(20);
        button = new JButton("Submit");

        // Add action listener to button
        button.addActionListener(this);

        // Create AWT Panel and set layout
        Panel panel = new Panel();
        panel.setLayout(new FlowLayout());

        // Add components to panel
        panel.add(label);
        panel.add(textField);
        panel.add(button);

        // Add panel to JFrame
        add(panel);

        // Set frame properties
        setSize(350, 150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    // Handle button click
    public void actionPerformed(ActionEvent e) {
        String name = textField.getText();
        if (!name.isEmpty()) {
            label.setText("Hello, " + name + "!");
        } else {
            label.setText("Please enter your name.");
        }
    }

    public static void main(String[] args) {
        // Run GUI in Event Dispatch Thread (EDT)
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new Main();
            }
        });
    }
}
