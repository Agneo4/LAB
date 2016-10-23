/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package LAB_10;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author adarsh
 */
public class Encry_Decry {
    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        int k=19;
        File file1=new File("/home/adarsh/JAVA-workspace/LAB/src/LAB_10/file3.txt");
        File file2=new File("/home/adarsh/JAVA-workspace/LAB/src/LAB_10/file2.txt");
        if (!file1.exists())
	    	file1.createNewFile();
        
        FileReader fr;
        FileWriter fw;
        
        fr = new FileReader(file1);
        fw = new FileWriter(file2);
        
        BufferedReader br;
        BufferedWriter bw;
        
        br = new BufferedReader(fr);
        bw = new BufferedWriter(fw);
        
        while(br.ready()){
            char ch=(char)br.read();
            bw.write((char)(ch+k));
        }
        
        br.close();
        bw.close();
        
        br=new BufferedReader(new FileReader("/home/adarsh/JAVA-workspace/LAB/src/LAB_10/file2.txt"));
        System.out.print('\n');
        while(br.ready())
            System.out.print((char)(br.read()-k));
    }
    
}
