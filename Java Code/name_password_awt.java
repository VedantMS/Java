import java.awt.*;
import java.awt.event.*;

class exc extends Exception {
    exc (String s) {
        super(s);
    }
}

class name_password_awt extends Frame  implements ActionListener{

    Label user, pass, txt;
    TextField t1, t2;
    Button b;
    int c = 0;

    name_password_awt() {
        user = new Label("Enter Username: ");
        pass = new Label("Enter Password: ");
        txt = new Label("");
        t1 = new TextField();
        t2 = new TextField();
        b = new Button("Login");

        t2.setEchoChar('*');

        user.setBounds(40, 50, 100, 30);
        t1.setBounds(180, 50, 150, 30);
        pass.setBounds(40, 100, 100, 30);
        t2.setBounds(180, 100, 150, 30);
        b.setBounds(40, 150, 40, 40);
        txt.setBounds(100, 150, 250, 40);

        add(user);
        add(pass);
        add(t1);
        add(t2);
        add(b);
        add(txt);

        b.addActionListener(this);

        setSize(400, 400);
        setTitle("Login Window");
        setLayout(null);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String username = t1.getText();
        String password = t2.getText();

        try {
            if(!username.equals(password)) {
                c++;
                throw new exc("Invalid Username or Password. Chance: " + c + "/3");
            }
            else {
                txt.setText("Access Granted. ");
            }
        }
        catch (exc ex) {
            txt.setText(ex.getMessage());
            if(c == 3) {
                txt.setText("Access Denied. ");
                b.setEnabled(false);
            }
        }
    }

    public static void main(String args[]) {
        new name_password_awt();
    }
}