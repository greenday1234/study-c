package Scheduling;

import java.lang.reflect.Array;
import java.util.*;

public class Priority {
    public Priority(Sorce[] sorce){
        //새로운 리스트 생성
        Queue<Sorce> n_sorce = new LinkedList<Sorce>();
        ArrayList<Sorce> sort_sorce = new ArrayList<Sorce>();
        Sorce[] new_sorce = new Sorce[sorce.length];

        //도착시간 정렬
        for(int i=0; i<sorce.length; i++){
            new_sorce[i] = new Sorce(sorce[i].getID(), sorce[i].getArrival(), sorce[i].getService(), sorce[i].getPriority());
        }
        Arrays.sort(new_sorce, (a, b) -> a.getArrival() - b.getArrival());

        //정렬된 배열 큐로 옮기기
        for(int i=0; i<sorce.length; i++){
            n_sorce.add(new Sorce(new_sorce[i].getID(), new_sorce[i].getArrival(), new_sorce[i].getService(), new_sorce[i].getPriority()));
        }

        System.out.println("Preemptive Scheduling");

        //간트 차트
        System.out.println("간트 차트");
        System.out.print("[ ");

        int total = 0;
        for(int k=0; k<new_sorce.length; k++){
            total += new_sorce[k].getService();
        }

        int run = 0;
        Sorce box = n_sorce.remove();
        int pcount = 0;
        Sorce[] p_sorce = new Sorce[sorce.length];
        int service_count = 0;
        Sorce copy;
        while(run < total){
           if(!n_sorce.isEmpty() && n_sorce.peek().getArrival() == run){
               //도착한 프로세스의 우선순위가 실행중인 프로세스의 우선순위보다 높은 경우
               if(n_sorce.peek().getPriority() < box.getPriority()){
                   if(box.Service <= 0){
                       copy = new Sorce(box);
                       copy.Service = service_count;
                       sort_sorce.add(copy);
                       service_count = 0;
                       box = n_sorce.remove();
                   }
                   else {
                       copy = new Sorce(box);
                       total = total - copy.Service;
                       box.tmp = 1;
                       p_sorce[pcount++] = box;
                       copy.Service = service_count;
                       box.Arrival = run;
                       sort_sorce.add(copy);
                       service_count = 0;
                       box = n_sorce.remove();
                   }
               }
               //도착한 프로세스의 우선순위가 실행중인 프로세스의 우선순위보다 낮은 경우
               else if(n_sorce.peek().getPriority() > box.getPriority()){
                   total = total - n_sorce.peek().getService();
                   copy = new Sorce(n_sorce.remove());
                   p_sorce[pcount++] = copy;
               }
           }
           System.out.print(box.getID() + " ");
           box.Service--;
           service_count++;
           run++;
           if(run == total){
               copy = new Sorce(box);
               copy.Service = service_count;
               sort_sorce.add(copy);
           }
        }

        if(pcount > 1) {
            Arrays.sort(p_sorce, 0, pcount, (a, b) -> a.getPriority() - b.getPriority());
        }

        Queue<Sorce> P_sorce = new LinkedList<Sorce>();
        for(int i=0; i<pcount; i++){
            P_sorce.add(p_sorce[i]);
        }

        if(!P_sorce.isEmpty()){
            for(int i=0; i<=P_sorce.size(); i++){
                copy = new Sorce(P_sorce.peek());
                sort_sorce.add(P_sorce.remove());
                for(int k=0; k<copy.getService(); k++){
                    System.out.print(copy.getID() + " ");
                }
            }
        }

        System.out.print("]\n");

        //각 프로세스별 평균 대기 시간
        int[] aAWT = new int[sort_sorce.size()];
        int num = 0;

        for(int i=0; i<sort_sorce.size(); i++){
            for(int k=0; k< i; k++){
                num += sort_sorce.get(k).getService();
            }
            aAWT[i] = num-sort_sorce.get(i).getArrival();
            num = 0;
        }
        double AWT = 0;
        for(int i=0; i< sort_sorce.size(); i++){
            AWT += aAWT[i];
        }
        AWT = AWT/ sorce.length;
        System.out.println("각  프로세스별 평균 대기 시간");
        System.out.println(AWT);

        //각 프로세스별 응답시간
        System.out.println("각 프로세스별 응답시간");
        int[] aACT = new int[sort_sorce.size()];

        for(int i=0; i< sort_sorce.size(); i++){
            for(int k=0; k<i; k++){
                num += sort_sorce.get(k).getService();
            }
            if(i == 0){
                aACT[i] = sort_sorce.get(i).getAction();
                num = 0;
                System.out.print(sort_sorce.get(i).getID() + " : " + aACT[i] + "\n");

            }
            else if(sort_sorce.get(i).tmp == 1){
                num=0;
                continue;
            }
            else {
                    aACT[i] = num + sort_sorce.get(i).getAction() - sort_sorce.get(i).getArrival();
                    num = 0;
                System.out.print(sort_sorce.get(i).getID() + " : " + aACT[i] + "\n");

            }
        }

        //평균 응답 시간
        double ACT = 0;
        for(int i=0; i<sort_sorce.size(); i++){
            ACT += aACT[i];
        }
        ACT = ACT/sorce.length;
        System.out.println("평균 응답 시간");
        System.out.println(ACT);

        //각 프로세스별 반환 시간
        System.out.println("각 프로세스별 반환 시간");
        int[] aATT = new int[sort_sorce.size()];

        for(int i=0; i<sort_sorce.size(); i++){
            for(int k=0; k<=i; k++){
                num += sort_sorce.get(k).getService();
            }
            if(i == 0){
                aATT[i] = sort_sorce.get(i).getService() - sort_sorce.get(i).getArrival();
                num = 0;
            }
            else {
                aATT[i] = num - sort_sorce.get(i).getArrival();
                num = 0;
            }
            System.out.print(sort_sorce.get(i).getID() + " : " + aATT[i] + "\n");
        }

        //평균 반환 시간
        double ATT = 0;
        for(int i=0; i<sort_sorce.size(); i++){
            ATT += aATT[i];
        }
        ATT = ATT/sorce.length;
        System.out.println("평균 반환 시간");
        System.out.println(ATT);
    }
}
