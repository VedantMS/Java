import java.text.SimpleDateFormat;
import java.util.*;

class Time_and_Date {
    public static void main(String[] args) {
        Date a = new Date();

        System.out.println(new SimpleDateFormat("dd/MM/yyyy").format(a));
        System.out.println(new SimpleDateFormat("MM-dd-yyyy").format(a));
        System.out.println(new SimpleDateFormat("EEEE MMMM dd yyyy").format(a));
        System.out.println(new SimpleDateFormat("EEE MMMM dd HH:mm:ss z yyyy").format(a));
        System.out.println(new SimpleDateFormat("dd/MM/yyyy HH:mm:ss a Z").format(a));
    }
}
