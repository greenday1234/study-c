package Scheduling;

import java.util.*;

public class FCFS {

    public FCFS(Sorce[] sorce){
        //새로운 객체 배열에 도착시간 정렬
        Sorce[] new_sorce = new Sorce[sorce.length];
        for(int i=0; i<sorce.length; i++){
            new_sorce[i] = new Sorce(sorce[i].getID(), sorce[i].getArrival(), sorce[i].getService(), sorce[i].getPriority());
        }
        Arrays.sort(new_sorce, (a, b) -> a.getArrival() - b.getArrival());

        System.out.println("FCFS Scheduling");

        //간트 차트
        System.out.println("간트 차트");
        System.out.print("[ ");
        for(int k=0; k<new_sorce.length; k++) {
            for (int i = 0; i < new_sorce[k].getService(); i++) {
                System.out.print(new_sorce[k].getID() + " ");
            }
        }
        System.out.print(" ]\n");

        //각 프로세스별 평균 대기 시간
        int[] aAWT = new int[new_sorce.length];
        int num = 0;

        for(int i=0; i<new_sorce.length; i++){
            for(int k=0; k< i; k++){
                num += new_sorce[k].getService();
            }
            aAWT[i] = num-new_sorce[i].getArrival();
            num = 0;
        }
        double AWT = 0;
        for(int i=0; i< new_sorce.length; i++){
            AWT += aAWT[i];
        }
        AWT = AWT/ new_sorce.length;
        System.out.println("각  프로세스별 평균 대기 시간");
        System.out.println(AWT);

        //각 프로세스별 응답시간
        System.out.println("각 프로세스별 응답시간");
        int[] aACT = new int[new_sorce.length];

        for(int i=0; i<new_sorce.length; i++){
            for(int k=0; k<i; k++){
                num += new_sorce[k].getService();
            }
            if(i == 0){
                aACT[i] = new_sorce[i].getAction();
                num = 0;
            }
            else {
                aACT[i] = num + new_sorce[i].getAction() - new_sorce[i].getArrival();
                num = 0;
            }
            System.out.print(new_sorce[i].getID() + " : " + aACT[i] + "\n");
        }

        //평균 응답 시간
        double ACT = 0;
        for(int i=0; i<new_sorce.length; i++){
            ACT += aACT[i];
        }
        ACT = ACT/new_sorce.length;
        System.out.println("평균 응답 시간");
        System.out.println(ACT);

        //각 프로세스별 반환 시간
        System.out.println("각 프로세스별 반환 시간");
        int[] aATT = new int[new_sorce.length];

        for(int i=0; i<new_sorce.length; i++){
            for(int k=0; k<=i; k++){
                num += new_sorce[k].getService();
            }
            if(i == 0){
                aATT[i] = new_sorce[i].getService() - new_sorce[i].getArrival();
                num = 0;
            }
            else {
                aATT[i] = num - new_sorce[i].getArrival();
                num = 0;
            }
            System.out.print(new_sorce[i].getID() + " : " + aATT[i] + "\n");
        }

        //평균 반환 시간
        double ATT = 0;
        for(int i=0; i<new_sorce.length; i++){
            ATT += aATT[i];
        }
        ATT = ATT/new_sorce.length;
        System.out.println("평균 반환 시간");
        System.out.println(ATT);
    }
}
