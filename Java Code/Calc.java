import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class SimpleCalculator extends JFrame implements ActionListener {
    JTextField input;
    String operator = "";
    double num1 = 0;

    SimpleCalculator() {
        setTitle("Calculator");
        setSize(300, 400);
        setLayout(new BorderLayout());

        input = new JTextField();
        input.setEditable(false);
        input.setHorizontalAlignment(JTextField.RIGHT);
        add(input, BorderLayout.NORTH);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(4, 4, 5, 5));
        add(panel, BorderLayout.CENTER);

        String[] buttons = {
                "7","8","9","/",
                "4","5","6","*",
                "1","2","3","-",
                "0","C","=","+"
        };

        for (String text : buttons) {
            JButton b = new JButton(text);
            b.addActionListener(this);
            panel.add(b);
        }

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String cmd = ((JButton)e.getSource()).getText();

        if (cmd.matches("[0-9]")) {
            input.setText(input.getText() + cmd);
        } else if (cmd.matches("[+\\-*/]")) {
            num1 = Double.parseDouble(input.getText());
            operator = cmd;
            input.setText("");
        } else if (cmd.equals("=")) {
            double num2 = Double.parseDouble(input.getText());
            double res = 0;
            switch (operator) {
                case "+": res = num1 + num2; break;
                case "-": res = num1 - num2; break;
                case "*": res = num1 * num2; break;
                case "/": res = num1 / num2; break;
            }
            input.setText(String.valueOf(res));
        } else if (cmd.equals("C")) {
            input.setText("");
            num1 = 0;
            operator = "";
        }
    }

    public static void main(String[] args) {
        new SimpleCalculator();
    }
}
