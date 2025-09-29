class ex extends Exception
{
    ex(String s) {
        super(s);
    }
}

public class Exce {
    public static void main(String[] args) {
        int a[] = {1, 2, 3, 4, 5};
        int b[] = {1, 2, 0, 4, 5};

        try
        {
            for(int i = 0; i < 5; i++) {
                if(b[i] == 0)
                    throw new ex("Cannot be divided by 0");
                else
                    System.out.println(a[i] / b[i]);
            }
        }

        catch(ex e) {
            System.out.println("Exception: " + e.getMessage());
        }

        for(int i = 0; i < 5; i++) {
            try
            {
                if(b[i] == 0)
                    throw new ex("Cannot be divided by 0.");
                else
                    System.out.println(a[i] / b[i]);
            }

            catch(ex e) {
                System.out.println("Exception: " + e.getMessage());
            }
        }
    }
}
