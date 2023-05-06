package Scheduling;

import java.util.*;

public class Priority {
    public Priority(Sorce[] sorce){
        //새로운 리스트 생성
        Queue<Sorce> n_sorce = new LinkedList<Sorce>();
        Queue<Sorce> sort_sorce = new LinkedList<Sorce>();
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
        Sorce box;
        while(run <= total){
            //현재 시간에서 도착시간이 run인 프로세스가 있는 경우 우선순위 비교
            if(run == n_sorce.peek().getArrival()){
                box = n_sorce.remove();
                if(box.getPriority() < n_sorce.peek().getPriority()){

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
        AWT = AWT/ sort_sorce.size();
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
            }
            else {
                aACT[i] = num + sort_sorce.get(i).getAction() - sort_sorce.get(i).getArrival();
                num = 0;
            }
            System.out.print(sort_sorce.get(i).getID() + " : " + aACT[i] + "\n");
        }

        //평균 응답 시간
        double ACT = 0;
        for(int i=0; i<sort_sorce.size(); i++){
            ACT += aACT[i];
        }
        ACT = ACT/sort_sorce.size();
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
        ATT = ATT/sort_sorce.size();
        System.out.println("평균 반환 시간");
        System.out.println(ATT);
    }
}
