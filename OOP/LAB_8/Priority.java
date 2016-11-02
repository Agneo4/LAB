package LAB_8;

public class Priority{

	public static void main(String[] argc){
            Threads a1=new Threads("Thread 1", 1);
            Threads a2=new Threads("Thread 2", 5);
            Threads a3=new Threads("Thread 3", 10);
            
            System.out.println("Waiting for Threads to Finish");
        try{
            a1.t.join();
            a2.t.join();
            a3.t.join();
        }catch (InterruptedException ex) {
                System.out.println(ex);
            }   
	
	}
}