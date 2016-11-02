package LAB_8;

/**
 *
 * @author adarsh
 */
public class Threads implements Runnable{
    String name;
    int pri;
    Thread t;
    Threads(String name){
        this.name=name;
        t=new Thread(this, name);
        t.start();
    }
    Threads(String name, int pri){
        this.name=name;
        this.pri = pri;            
        t=new Thread(this, name);
        t.setPriority(this.pri);
        t.start();
    }

    @Override
    public void run(){
        for(int i=0; i<10; i++)
            System.out.println(t.getName() + " is running.");
    }
}