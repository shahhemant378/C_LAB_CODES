import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

class Node{
    int p_id;
    int at;
    int bt;
    int Gcom=0;
    int tat;
    int wt;
    int rt;
    int dbt;
    int intime=-1;

    Node(int p_id,int at,int bt){
        this.p_id=p_id;
        this.at=at;
        this.bt=bt;
        this.dbt=bt;
    }
}

public class roundRobin {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        Node[] p = new Node[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter PID AT BT: ");
            int pid = sc.nextInt();
            int at = sc.nextInt();
            int bt = sc.nextInt();
            p[i] = new Node(pid, at, bt);
        }

        System.out.println("Enter the quantam time: ");
        int qt=sc.nextInt();


        // Step 1: Sort by Arrival Time
        Arrays.sort(p, Comparator.comparingInt(a -> a.at));

        
        Queue<Node> q=new LinkedList<>();

        int completed=0;
        int i=0;
        Node currNode=p[0];
        while (!q.isEmpty() || i<n ) {
             if(!q.isEmpty()){
            currNode=q.poll();
         }else if(i<n){
            currNode=p[i];
            i++;

            if(completed < currNode.at)
                    completed = currNode.at;
         }

         if(currNode.intime==-1){
            currNode.intime=completed;
         }

         if(currNode.dbt>=qt)
            completed+=qt;
        else
            completed+=currNode.dbt;

         if(currNode.dbt>=qt)
            currNode.dbt-=qt;
        else    
            currNode.dbt=0;

        currNode.Gcom=completed;
        currNode.tat=currNode.Gcom-currNode.at;
        currNode.wt=currNode.tat-currNode.bt;
        currNode.rt=currNode.intime-currNode.at;
         

          // add newly arrived processes
            while(i<n && p[i].at<=completed){
                q.add(p[i]);
                i++;
            }

            // if process still has burst time
            if(currNode.dbt>0){
                q.add(currNode);
            }
        
         

        }

           Arrays.sort(p, Comparator.comparingInt(a -> a.p_id));

            for(int j=0;j<n;j++){
                Node curNode=p[j];
                 System.out.println(
                    "PID: " + curNode.p_id +
                    " AT: " + curNode.at +
                    " BT: " + curNode.bt +
                    " CT: " + curNode.Gcom +
                    " TAT: " + curNode.tat +
                    " WT: " + curNode.wt +
                    " RT: " + curNode.rt
            );
            }
    }
}
