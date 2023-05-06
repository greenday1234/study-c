package Scheduling;

import java.util.ArrayList;

public class Non_Priority {
    public Non_Priority(Sorce[] sorce){
        //새로운 리스트 생성
        ArrayList<Sorce> new_sorce = new ArrayList<Sorce>();
        ArrayList<Sorce> sort_sorce = new ArrayList<Sorce>();
        int count = 0;
        for(int i=0; i<sorce.length; i++){
            new_sorce.add(i, new Sorce(sorce[i].getID(), sorce[i].getArrival(), sorce[i].getService(), sorce[i].getPriority()));
        }

        System.out.println("Non-Preemptive Scheduling");

        //간트 차트
        System.out.println("간트 차트");
        System.out.print("[ ");
        //가장 먼저 도착한 프로세스 찾고 출력
        for(int k=0; k<new_sorce.size(); k++){
            if(new_sorce.get(k).getArrival() == 0){
                for(int i = 0; i< new_sorce.get(k).getService(); i++){
                    System.out.print(new_sorce.get(k).getID() + " ");
                }
                sort_sorce.add(count++, new Sorce(new_sorce.get(k).getID(), new_sorce.get(k).getArrival(), new_sorce.get(k).getService(), new_sorce.get(k).getPriority()));
                new_sorce.remove(k);
                break;
            }
        }
        int temp;
        int min;
        int size = new_sorce.size();
        for(int i=0; i<size; i++) {
            min = new_sorce.get(0).getService();
            temp = 0;
            for (int k = 0; k < new_sorce.size(); k++) {
                if (min > new_sorce.get(k).getPriority()) {
                    min = new_sorce.get(k).getPriority();
                    temp = k;
                }
            }
            for (int k = 0; k < new_sorce.get(temp).getService(); k++) {
                System.out.print(new_sorce.get(temp).getID() + " ");
            }
            sort_sorce.add(count++, new Sorce(new_sorce.get(temp).getID(), new_sorce.get(temp).getArrival(), new_sorce.get(temp).getService(), new_sorce.get(temp).getPriority()));
            new_sorce.remove(temp);
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
