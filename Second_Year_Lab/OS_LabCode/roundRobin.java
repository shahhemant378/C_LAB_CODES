
// import java.util.*;

// class Node{
//     int p_id;
//     int at;
//     int bt;
//     int tempbt;
//     int Gcom=0;
//     int Garr=0;
//     int tat;
//     int wt;
//     int rt;
    
   
//     boolean isVisFront=false;

//     Node(int p_id,int at,int bt){
//         this.p_id=p_id;
//         this.at=at;
//         this.bt=bt;
//         this.tempbt=bt;
//     }
// }

// public class roundRobin {

//      public static PriorityQueue<Node> sortGc(Queue<Node> q){
//         PriorityQueue<Node> p=new PriorityQueue<>((a,b)->a.p_id-b.p_id);
//         while(!q.isEmpty()){
//             p.add(q.poll());
//         }
//         return p;
//     }
//   public static void main(String[] args) {
//        Scanner sc=new Scanner(System.in);

//         System.out.println("Enter the no of process: ");
//         int n=sc.nextInt();

//         System.out.println("Enter the Quantam time: ");
//         int qt=sc.nextInt();

//         PriorityQueue<Node> pq=new PriorityQueue<>((a,b)->a.at-b.at);

//         // Input
//         for(int i=1;i<=n;i++){
//             System.out.println("Enter the process, At and BT: ");
//             int p=sc.nextInt();
//             int at=sc.nextInt();
//             int bt=sc.nextInt();
//             pq.add(new Node(p,at,bt));
//         }

//         Queue<Node> Gc=new LinkedList<>();
//         Queue<Node> Rq=new LinkedList<>();
//         Rq.add(pq.poll());
//         int arrival=Rq.peek().at;
//         while(!Rq.isEmpty()){
//             Node temp=Rq.poll();
//             temp.Garr=arrival;
//             if(temp.tempbt<qt){
//                 temp.Gcom=temp.Garr+temp.tempbt;
//             }else{
//             temp.Gcom=temp.Garr+qt;
//             }
//             if(temp.tempbt<qt){
//                 temp.tempbt=0;
//             }else{
//                 temp.tempbt=temp.tempbt-qt;
//             }
            
           
           

//             while(!pq.isEmpty() && temp.Gcom>=pq.peek().at){
//                 Rq.add(pq.poll());
//             }


//             if(temp.tempbt>0){
//                 Rq.add(temp);
//             }
//             arrival=temp.Gcom;
            
            
           
//              if(temp.isVisFront==false){
//             temp.rt=temp.Garr-temp.at;
//             temp.isVisFront=true;
             
//             }

         
//                 Gc.add(temp);
            

//         }
//         Queue<Node> Gctemp=new LinkedList<>();
//         while (!Gc.isEmpty()) {
            
//             Node node=Gc.poll();
//             node.tat=node.Gcom-node.at;
//             node.wt=node.tat-node.bt;
//             Gctemp.add(node);
            
//         }
//         HashSet<Node> hs=new HashSet<>();
//         while (!Gctemp.isEmpty()) {
//             Node temp=Gctemp.poll();
            
//             hs.add(temp);

//         }
//         for (Node val : hs) {
//             Gc.add(val);
//         }
        
//          PriorityQueue<Node> sortedGc=sortGc(Gc);
//           while(!sortedGc.isEmpty()){
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
//   }  
// }

import java.util.*;

class Process {
    int pid, at, bt, rtTime;
    int ct, tat, wt, rt;
    boolean started = false;

    Process(int pid, int at, int bt) {
        this.pid = pid;
        this.at = at;
        this.bt = bt;
        this.rtTime = bt;
    }
}

public class roundRobin{

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        System.out.print("Enter Quantum time: ");
        int qt = sc.nextInt();

        Process[] p = new Process[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Enter PID AT BT: ");
            p[i] = new Process(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }

        Arrays.sort(p, Comparator.comparingInt(a -> a.at));

        Queue<Process> rq = new LinkedList<>();

        int currentTime = 0;
        int i = 0, completed = 0;

        while (completed < n) {

            while (i < n && p[i].at <= currentTime) {
                rq.add(p[i]);
                i++;
            }

            if (rq.isEmpty()) {
                currentTime = p[i].at;
                continue;
            }

            Process curr = rq.poll();

            if (!curr.started) {
                curr.rt = currentTime - curr.at;
                curr.started = true;
            }

            int runTime = Math.min(qt, curr.rtTime);
            currentTime += runTime;
            curr.rtTime -= runTime;

            while (i < n && p[i].at <= currentTime) {
                rq.add(p[i]);
                i++;
            }

            if (curr.rtTime > 0) {
                rq.add(curr);
            } else {
                curr.ct = currentTime;
                curr.tat = curr.ct - curr.at;
                curr.wt = curr.tat - curr.bt;
                completed++;
            }
        }

        for (Process pr : p) {
            System.out.println("PID: " + pr.pid +
                    " AT: " + pr.at +
                    " BT: " + pr.bt +
                    " CT: " + pr.ct +
                    " TAT: " + pr.tat +
                    " WT: " + pr.wt +
                    " RT: " + pr.rt);
        }

        sc.close();
    }
}