package LAB_8;

import java.util.*;

class A extends Thread{
	int i;
	A(int i){this.i=i;}
        @Override
	public void run(){
            for(int k=0; k<10; k++)
                System.out.println("Thread " + i + " is running.");
	}
}

class B implements Runnable{
	int i;
	B(int i){this.i=i;}
        @Override
	public void run(){
            for(int k=0; k<10; k++)
                System.out.println("Thread " + i + " is running.");
	}
}

public class Menu{

	public static void main(String[] argc){
            Scanner sc=new Scanner(System.in);
            int o;
            do{
                System.out.println("Choose");
                System.out.println("1. Multi-Threading via Thread class");
                System.out.println("2. Multi-Threading via Runnable interface");
                o=sc.nextInt();
                try {
                    if(o==1){
                        A a=new A(1);
                        a.start();
                        a.join();
                    }

                    else if(o==2){
                        B b=new B(2);
                        Thread t=new Thread(b);
                        t.start();
                        t.join();
                    }
                }catch (InterruptedException ex) {
                        System.out.println(ex);
                    }
            }while(o!=3);
	}
}