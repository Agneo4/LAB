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
class Emp implements Serializable
{
	String name, city;
	double basicSalary, totalSalary, da, hra;
	
	public void input()
	{
            Scanner sc=new Scanner(System.in);
            System.out.print("Enter Name : ");
            name=sc.nextLine();
            System.out.print("Enter City : ");
            city=sc.nextLine();
            System.out.print("Enter Basic Salary : ");
            basicSalary=sc.nextDouble();
            System.out.print("Enter Dearness Allowance : ");
            da=sc.nextDouble();
            System.out.print("Enter House-Rent Allowance : ");
            hra=sc.nextDouble();
        }
        
        public void calculate()
        {
            totalSalary=basicSalary*(1+da/100+hra/100);
        }
        
        public void show()
        {
            System.out.println("Name : " + name);
            System.out.println("City : " + city);
            System.out.println("Basic Salary : " + basicSalary);
            System.out.println("Dearness Allowance : " + da);
            System.out.println("House-Rent Allowance : " + hra);
            System.out.println("Total Salary : " + totalSalary);
	}
}

public class Company_Write {

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
                Emp s=new Emp();
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
            Emp s;
            while(fis.available()>0){
                s=(Emp) fi.readObject();
                s.calculate();
                s.show();
                fo.writeObject(s);
                fo.flush();
            }
            fi.close();
            fo.close();
        }catch(IOException i){
            System.out.println(i);
        }  
    }
}