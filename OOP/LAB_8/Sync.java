package LAB_8;

/**
 *
 * @author adarsh
 */

class Count{
    int c=0;
    public void count(){
        System.out.println("Counter is : " + c);
    }
}

class Threads1 implements Runnable{
    String name;
    int pri;
    Thread t;
    Count c;

    Threads1(String name, Count c){
        this.name=name;
        this.c=c;
        t=new Thread(this, name);
        t.start();
    }
    @Override
    public void run(){
        synchronized(c){
            c.count();
        }
        
        for(int i=0; i<10; i++)
            c.c++;
        System.out.println(t.getName() + " is Running.");
        if(t.getName().compareTo("Thread 2")==0)
            synchronized(c){
                c.count();
            }
    }    
}

public class Sync{

    /**
     *
     * @param argc
     * @throws InterruptedException
     */
    public static void main(String[] argc) throws InterruptedException{
        Count c=new Count();
        Threads1 t1=new Threads1("Thread 1", c);
        Threads1 t2=new Threads1("Thread 2", c);

        t1.t.join();
        t2.t.join();
    }
}