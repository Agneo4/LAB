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
 * @author adarsh
 */

class Student implements Serializable{
    int rno, reg_no;
    String name;
    int m1, m2, m3; //There is a data descrepancy with arrays....So don't change.
    float per;
    char grade;
    
    public void input(){
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the details");
        System.out.print("Name : ");name=sc.next();
        System.out.print("Roll No : ");rno=sc.nextInt();
        System.out.print("Registration No : ");reg_no=sc.nextInt();
        System.out.print("Marks of sub1 : ");m1=sc.nextInt();
        System.out.print("Marks of sub2 : ");m2=sc.nextInt();
        System.out.print("Marks of sub3 : ");m3=sc.nextInt();
    }
    
    public void show(){
        System.out.println("Name : " + name);
        System.out.println("Roll No : " + rno);
        System.out.println("Registration No : " + reg_no);
        System.out.println("Subject 1: " + m1);
        System.out.println("Subject 2: " + m2);
        System.out.println("Subject 3: " + m3);
        System.out.println("Percent : " + per);
        System.out.println("Grade : " + grade);
    }
    
    public void grade(){
        per=(float)(m1+m2+m3)/3;
        if(per>=90) grade='A';
        else if(per>=80 && grade<=90)   grade='B';
        else if(per>=70 && grade<=80)   grade='C';
        else    grade='D';
    }
}   

public class Student_Write {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     * @throws java.lang.ClassNotFoundException
     */
    public static void main(String[] args) throws IOException, ClassNotFoundException{
        try{
            FileOutputStream fos=new FileOutputStream("serial.ser");
            ObjectOutputStream fo;
            fo = new ObjectOutputStream(fos);

            for(int i=0; i<2; i++){
                Student s=new Student();
                s.input();
                fo.writeObject(s);
                fo.flush();
            }
            
            fo.close();
            
            FileInputStream fis=new FileInputStream("serial.ser");
            fos=new FileOutputStream("serial_1.ser");
            fo=new ObjectOutputStream(fos);
            ObjectInputStream fi;
            fi = new ObjectInputStream(fis);
            Student s;
            while(fis.available()>0){
                s=(Student) fi.readObject();
                s.grade();
                s.show();
                fo.writeObject(s);
                fo.flush();
            }
            fi.close();
            fo.close();
        }catch(IOException i){}
    }
}
