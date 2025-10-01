import java.util.*;

class ex1 extends Exception{
    ex1(String s) {
        super(s);
    }
}

class Pass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for(int i = 0; i < 3; i++) {
            System.out.println("Enter Username: ");
            String username = sc.nextLine();
            System.out.println("Enter Password: ");
            String password = sc.nextLine();

            try {
                if(username.equals(password)) {
                    System.out.println("Welcome " + username);
                    break;
                }

                else
                    throw new ex1("Invalid Username or Password.");
            }

            catch (ex1 e) {
                System.out.println("Exception: " + e.getMessage());
            }
        }

    }
}
