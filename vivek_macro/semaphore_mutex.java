import java.util.concurrent.Semaphore;
import java.util.Scanner;

public class semaphore_mutex{
    Semaphore read= new Semaphore(1);
    Semaphore write= new Semaphore(1);

    static int count=0;
    public class Read implements Runnable{
        @Override
        public void run(){
            try{
                read.acquire();
                count++;
                if(count==1){
                    write.acquire();
                }
                read.release();
                System.out.println(" Thread "+ Thread.currentThread().getName()+" is running");
                Thread.sleep(2500);
                System.out.println(" Thread "+ Thread.currentThread().getName() +" has finished running");
                count--;
                read.acquire();
                if(count==0){
                    write.release();
                }
                read.release();

            }catch(InterruptedException e){
                System.out.println(e.getMessage());
            }
        }
    }
    public class Write implements Runnable{
        @Override
        public void run(){
            try{
                write.acquire();
                System.out.println(" Thread "+ Thread.currentThread().getName()+"is writing");
                Thread.sleep(1000);
                System.out.println(" Thread "+ Thread.currentThread().getName()+" has finished writing");
                write.release();
            }catch(InterruptedException e){
                System.out.println(e.getMessage());
            }
        }
    }
    void fun(){
        Read rd=new Read();
        Write rt=new Write();
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter number: ");
        int n=sc.nextInt();

        int a[]=new int[n];
        System.out.println("Enter the sequence : 1 for reading & 0 for writing.");
        for(int i=0;i<n;i++){
            a[i]=sc.nextInt();
        }

        Thread process[]=new Thread[n];
        for(int i=0;i<n;i++){
            if(a[i]==1){
                process[i]=new Thread(rd);
                process[i].setName(" thread "+(i+1));
            }
            else if(a[i]==0){
                process[i]=new Thread(rt);
                process[i].setName(" thread "+(i+1));
            }
        }
        for(int i=0;i<n;i++){
            process[i].start();
        }
        sc.close();
    }
    public static void main(String args[]){
        semaphore_mutex rw=new semaphore_mutex();
        rw.fun();
    }
}