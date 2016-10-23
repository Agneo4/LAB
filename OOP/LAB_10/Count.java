/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LAB_10;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author student7
 */
public class Count {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        File file1=new File("/home/adarsh/JAVA-workspace/LAB/src/LAB_10/file1.txt");
        if (!file1.exists())
	    	file1.createNewFile();
        int ca=0, cv=0, cl=0, cw=0;
        FileReader fr;
        fr = new FileReader(file1);
        BufferedReader br;
        br = new BufferedReader(fr);
        br.mark(100);
        while(br.ready()){
            ca++;
            char c=Character.toLowerCase((char)br.read());
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                cv++;
        }
        br.reset();
        String s;
        while(br.ready()){
            s=br.readLine();
            if(s.isEmpty()) break;
            for(int i=0; i<s.length(); i++)
                if(s.charAt(i)==' ' || s.charAt(i)=='.')
                cw++;
            cl++;
        }
        br.close();
        System.out.println("Number of characters : "+ca);
        System.out.println("Number of vowels : "+cv);
        System.out.println("Number of words : "+cw);
        System.out.println("Number of lines : "+cl);
    }
    
}