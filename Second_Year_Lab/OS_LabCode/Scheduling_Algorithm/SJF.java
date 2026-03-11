

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

    Node(int p_id,int at,int bt){
        this.p_id=p_id;
        this.at=at;
        this.bt=bt;
    }
}

public class SJF {

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

        // Step 1: Sort by Arrival Time
        Arrays.sort(p, Comparator.comparingInt(a -> a.at));

        PriorityQueue<Node> q=new PriorityQueue<>((a,b)->a.bt-b.bt);
        

        int completed=0;
        int i=0;
        Node currNode=p[0];
        while (!q.isEmpty() || i<n ) {
         if(!q.isEmpty()){
            currNode=q.poll();
         }else if(i<n){
            currNode=p[i];
            i++;
         }
        

        completed+=currNode.bt;

        currNode.Gcom=completed;
        currNode.tat=currNode.Gcom-currNode.at;
        currNode.wt=currNode.tat-currNode.bt;
        currNode.rt=currNode.wt;

        while(true){
            if(i<n && p[i].at<completed){
                q.add(p[i]);
                i++;
            }else
                break;
   
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
