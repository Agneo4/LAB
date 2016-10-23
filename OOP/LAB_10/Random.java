package LAB_10;

import java.util.*;
import java.io.*;

public class Random{
    public static void main(String[] args)    {
        File file=new File("/home/adarsh/JAVA-workspace/LAB/src/LAB_10/file.txt");
        int opt=0;
        while(opt!=4)
        {
            System.out.print("1.Write\n2.Read\n3.Append\n4.Exit\n\nYour choice: ");
            Scanner sc=new Scanner(System.in);
            opt=sc.nextInt();
            switch(opt)
            {
                case 1:	System.out.println("Enter string to write: ");
                        String str=sc.next();
                        try
                        {
                            RandomAccessFile fw = new RandomAccessFile(file, "rw");
                            fw.writeUTF(str);
                            fw.close();
                        }
                        catch(Exception e)
                        {
                            System.out.println(e);
                        }
                        System.out.println("\nFile written successfully!");
                        break;

                case 2:	try
                        {
                            byte[] b = new byte[100];
                            long len = file.length();
                            RandomAccessFile fr = new RandomAccessFile(file, "rw");
                            fr.seek(0);
                            fr.readFully(b, 0, (int)len);
                            fr.close();
                            String str1 = new String(b, "UTF-8");
                            System.out.println(str1);
                        }
                        catch(Exception e)
                        {
                            System.out.println(e);
                        }
                        break;

                case 3:	System.out.println("Enter string to append: ");
                        String str2=sc.next();
                        try
                        {
                            long length = file.length();
                            RandomAccessFile fw1 = new RandomAccessFile(file, "rw");
                            fw1.seek(length);
                            fw1.writeUTF(str2);
                            fw1.close();
                        }
                        catch(Exception e)
                        {
                            System.out.println(e);
                        }
                        System.out.println("File edited successfully!");
                        break;

            }
        }
    }
}