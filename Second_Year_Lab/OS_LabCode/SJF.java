//package C_LAB_CODES.Second_Year_Lab.OS_LabCode;
import java.util.*;

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

    public static PriorityQueue<Node> sortQueue(Queue<Node> q){
        PriorityQueue<Node> p=new PriorityQueue<>((a,b)->a.bt-b.bt);
        while(!q.isEmpty()){
            p.add(q.poll());
        }
        return p;
    }

    public static PriorityQueue<Node> sortGc(Queue<Node> q){
        PriorityQueue<Node> p=new PriorityQueue<>((a,b)->a.p_id-b.p_id);
        while(!q.isEmpty()){
            p.add(q.poll());
        }
        return p;
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the no of process: ");
        int n=sc.nextInt();

        PriorityQueue<Node> pq=new PriorityQueue<>((a,b)->a.at-b.at);

        // Input
        for(int i=1;i<=n;i++){
            System.out.println("Enter the process, At and BT: ");
            int p=sc.nextInt();
            int at=sc.nextInt();
            int bt=sc.nextInt();
            pq.add(new Node(p,at,bt));
        }

        Queue<Node> Gc=new LinkedList<>();

        // First process
        Node first=pq.poll();

        first.Gcom=first.at+first.bt;
        first.tat=first.Gcom-first.at;
        first.wt=first.tat-first.bt;
        first.rt=first.wt;

        Gc.add(first);

        int completed=first.Gcom;

        Queue<Node> temp=new LinkedList<>();

        do{
            // Move arrived processes
            while (!pq.isEmpty() && pq.peek().at<=completed) {
                temp.add(pq.poll());
            }

            PriorityQueue<Node> t=sortQueue(temp);

            // CPU idle case
            // if(t.isEmpty()){
            //     if(!pq.isEmpty()){
            //         completed=pq.peek().at;
            //         continue;
            //     } else break;
            // }

            Node chosen=t.poll();

            completed+=chosen.bt;

            chosen.Gcom=completed;
            chosen.tat=chosen.Gcom-chosen.at;
            chosen.wt=chosen.tat-chosen.bt;
            chosen.rt=chosen.wt;

            Gc.add(chosen);

            // return remaining to temp
            while(!t.isEmpty()){
                temp.add(t.poll());
            }

        }while(!pq.isEmpty() || !temp.isEmpty());

        PriorityQueue<Node> sortedGc=sortGc(Gc);

        while(!sortedGc.isEmpty()){
            Node currNode=sortedGc.poll();
            System.out.println(
                "PId: "+ currNode.p_id +
                " At: "+currNode.at+
                " BT: "+currNode.bt+
                " CT: "+currNode.Gcom+
                " TAT: "+currNode.tat+
                " WT: "+currNode.wt+
                " RT: "+currNode.rt
            );
        }
    }
}

//THIS IS WELL COMMENTED CODE OF UPPER CODE

// import java.util.*;

// class Node{
//     int p_id;   // process id
//     int at;     // arrival time
//     int bt;     // burst time
//     int Gcom=0; // completion time (CT)
//     int tat;    // turnaround time
//     int wt;     // waiting time
//     int rt;     // response time

//     Node(int p_id,int at,int bt){
//         this.p_id=p_id;
//         this.at=at;
//         this.bt=bt;
//     }
// }



// public class SJF {

//     // Sorts processes by Burst Time (for SJF selection)
//     // NOTE: This empties the original queue q
//     public static PriorityQueue<Node> sortQueue(Queue<Node> q){
//         PriorityQueue<Node> p=new PriorityQueue<>((a,b)->a.bt-b.bt);
//         while(!q.isEmpty()){
//             p.add(q.poll()); // move reference from q to p
//         }
//         return p;
//     }

//     // Sorts final output by Process ID
//     // NOTE: This also empties the given queue
//     public static PriorityQueue<Node> sortGc(Queue<Node> q){
//         PriorityQueue<Node> p=new PriorityQueue<>((a,b)->a.p_id-b.p_id);
//         while(!q.isEmpty()){
//             p.add(q.poll());
//         }
//         return p;
//     }

//     public static void main(String[] args) {
//         Scanner sc=new Scanner(System.in);

//         System.out.println("Enter the no of process: ");
//         int n=sc.nextInt();

//         // PQ sorted by Arrival Time
//         PriorityQueue<Node> pq=new PriorityQueue<>((a,b)->a.at-b.at);

//         // Taking input
//         for(int i=1;i<=n;i++){
//             System.out.println("Enter the process, At and BT: ");
//             int p=sc.nextInt();
//             int at=sc.nextInt();
//             int bt=sc.nextInt();
//             pq.add(new Node(p,at,bt));
//         }

//         // Gantt chart queue (stores execution order)
//         Queue<Node> Gc=new LinkedList<>();

//         // -------- First process execution --------
//         // Pick earliest arrival process
//         Node first=pq.poll();

//         // CT = AT + BT (CPU starts at arrival)
//         first.Gcom=first.at+first.bt;

//         // Standard formulas
//         first.tat=first.Gcom-first.at;
//         first.wt=first.tat-first.bt;
//         first.rt=first.wt;

//         Gc.add(first);

//         int completed=first.Gcom; // current time

//         // Temp queue stores arrived processes
//         Queue<Node> temp=new LinkedList<>();

//         // -------- Main SJF loop --------
//         do{
//             // Move all processes that have arrived
//             while (!pq.isEmpty() && pq.peek().at<=completed) {
//                 temp.add(pq.poll());
//             }

//             // Sort arrived processes by BT
//             PriorityQueue<Node> t=sortQueue(temp);

//             // Select shortest job
//             Node chosen=t.poll();

//             // Advance time by its BT
//             completed+=chosen.bt;

//             // Compute times
//             chosen.Gcom=completed;
//             chosen.tat=chosen.Gcom-chosen.at;
//             chosen.wt=chosen.tat-chosen.bt;
//             chosen.rt=chosen.wt;

//             // Add to Gantt chart
//             Gc.add(chosen);

//             // Put remaining processes back to temp
//             // (because sortQueue emptied it)
//             while(!t.isEmpty()){
//                 temp.add(t.poll());
//             }

//         }while(!pq.isEmpty() || !temp.isEmpty());

//         // Sort final output by PID
//         PriorityQueue<Node> sortedGc=sortGc(Gc);

//         // Print results
//         while(!sortedGc.isEmpty()){
//             Node currNode=sortedGc.poll();
//             System.out.println(
//                 "PId: "+ currNode.p_id +
//                 " At: "+currNode.at+
//                 " BT: "+currNode.bt+
//                 " CT: "+currNode.Gcom+
//                 " TAT: "+currNode.tat+
//                 " WT: "+currNode.wt+
//                 " RT: "+currNode.rt
//             );
//         }
//     }
// }
