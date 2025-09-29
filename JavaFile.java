import java.io.*;

class JavaFile {
    public static void main(String[] args) throws IOException
    {
        RandomAccessFile f1 = new RandomAccessFile("C:\\Users\\Vedant\\Desktop\\Java\\Java Project 1\\src\\A.txt", "r");
        RandomAccessFile f2 = new RandomAccessFile("C:\\Users\\Vedant\\Desktop\\Java\\Java Project 1\\src\\B.txt", "rw");

        long len = f1.length();

        f1.seek(0);

        for(int i = 0; i < len; i++) {
            f2.write(f1.read());
        }

        f1.seek(0);
        f2.seek(f2.length());
        f2.write('\n');

        for(int i = 0; i < len; i++) {
            int ch = (f1.read());
            char c = (char) ch;
            if(Character.isUpperCase(c)) {
                f2.write(Character.toLowerCase(c));
            }
            else if(Character.isLowerCase(c)) {
                f2.write(Character.toUpperCase(c));
            }
            else
                f2.write(c);
        }
    }


}
