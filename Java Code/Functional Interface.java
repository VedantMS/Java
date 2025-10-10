@FunctionalInterface
interface a
{
    public int cube(int n);
}

public class Java1 implements a
{
    @Override
    public int cube(int n) {

        return n * n * n;
    }

    public static void main(String[] args)
    {
        Java1 j = new Java1();

        int n = 100;

        System.out.println(j.cube(n));
    }
}
