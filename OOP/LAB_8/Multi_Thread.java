package LAB_8;

public class Multi_Thread{
    /**
     *
     * @param argc
     */
    public static void main(String[] argc){
        Threads a1=new Threads("Thread 1");
        Threads a2=new Threads("Thread 2");
        Threads a3=new Threads("Thread 3");

        System.out.println("Thread 1 is alive : "+a1.t.isAlive());
        System.out.println("Thread 2 is alive : "+a2.t.isAlive());
        System.out.println("Thread 3 is alive : "+a3.t.isAlive());

        System.out.println("Waiting for Threads to Finish");
        try{
            a1.t.join();
            a2.t.join();
            a3.t.join();
        }catch (InterruptedException ex) {
                System.out.println(ex);
            }

        System.out.println("Thread 1 is alive : "+a1.t.isAlive());
        System.out.println("Thread 2 is alive : "+a2.t.isAlive());
        System.out.println("Thread 3 is alive : "+a3.t.isAlive());		
    }
}