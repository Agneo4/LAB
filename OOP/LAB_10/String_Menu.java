/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LAB_10;

import java.io.*;
import java.util.Scanner;

/**
 *
 * @author student7
 */
public class String_Menu {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        Scanner sc=new Scanner (System.in);
        
        BufferedReader br;
        BufferedWriter bw;
        
        FileWriter fw;
        FileReader fr;
        
        File file1=new File("/home/student7/NetBeansProjects/LAB/src/LAB_10/file1.txt");
        if (!file1.exists())
	     file1.createNewFile();

        int o=0;
        while(o!=5){
            System.out.println("1. To write to a File.");
            System.out.println("2. To read from the File.");
            System.out.println("3. To copy one file to another File.");
            o=sc.nextInt();
            switch(o){
                case 1: System.out.println("Enter data you want to write");
                        String s=sc.next();
                        fw=new FileWriter(file1);
                        bw=new BufferedWriter(fw);
                        bw.write(s);
                        bw.close();
                        break;
                        
                case 2: fr=new FileReader(file1);
                        br=new BufferedReader(fr);
                        while(br.ready()){
                            System.out.print((char)br.read());
                        }
                        br.close();
                        break;
                        
                case 3: fr=new FileReader(file1);
                        br=new BufferedReader(fr);
                        
                        File file2=new File("/home/student7/NetBeansProjects/LAB/src/LAB_10/file2.txt");
                        if (!file2.exists())
                             file2.createNewFile();
                        
                        fw=new FileWriter(file2);
                        bw=new BufferedWriter(fw);
                        
                        while(br.ready()){
                            int ch=br.read();
                            bw.write((char)ch);
                        }
                        br.close();
                        bw.close();
                        break;
            }
        }          

    }
    
}
