package Scheduling;

import java.util.*;

public class FCFS {

    public FCFS(Source[] source) {
        Source[] new_source = new Source[source.length];
        ArrayList<Source> n_source = new ArrayList<Source>();
        ArrayList<Source> sort_source = new ArrayList<Source>();
        int run = 0;
        int total = 0;

        for(int i=0; i<source.length; i++){
            new_source[i] = new Source(source[i].getID(), source[i].getArrival(), source[i].getService(), source[i].getPriority(), 0);
            total += source[i].getService();
        }
        //도착 시간 정렬
        Arrays.sort(new_source, (a, b) -> a.getArrival() - b.getArrival());

        for(int i=0; i< new_source.length; i++){
            n_source.add(new Source(new_source[i].getID(), new_source[i].getArrival(), new_source[i].getService(),
                    new_source[i].getPriority(), 0));
        }
        System.out.println("FCFS Scheduling");
        //---------------간트 차트---------------//
        System.out.println("간트 차트");
        System.out.print("[ ");
        while(run < total){
            if(run >= n_source.get(0).getArrival()){
                for(int i=0; i<n_source.get(0).getService(); i++) {
                    System.out.print(n_source.get(0).getID() + " ");
                    run++;
                }
                sort_source.add(new Source(n_source.get(0).getID(), n_source.get(0).getArrival(), n_source.get(0).getService(),
                        n_source.get(0).getPriority(), (run-n_source.get(0).getService())));
                n_source.remove(0);
            }
        }
        System.out.println("]");

        //---------------각 프로세스별 대기 시간---------------//
        System.out.println("각 프로세스별 대기 시간");
        for(int i=0; i<sort_source.size(); i++){
            System.out.println(sort_source.get(i).getID() + " : " + (sort_source.get(i).RunTime-sort_source.get(i).getArrival()));

        }

        //---------------프로세스 평균 대기 시간---------------//
        System.out.println("프로세스 평균 대기 시간");
        double AWT = 0;
        for(int i=0; i<sort_source.size(); i++) {
            AWT += sort_source.get(i).RunTime - sort_source.get(i).getArrival();
        }
        System.out.println(AWT/source.length);

        //---------------각 프로세스별 응답 시간---------------//
        System.out.println("각 프로세스별 응답 시간");
        for(int i=0; i<sort_source.size(); i++){
            System.out.println(sort_source.get(i).getID() + " : " + (sort_source.get(i).RunTime - sort_source.get(i).getArrival() + sort_source.get(i).getAction()));
        }

        //---------------프로세스 평균 응답 시간---------------//
        System.out.println("프로세스 평균 응답 시간");
        double ART = 0;
        for(int i=0; i<sort_source.size(); i++){
            ART += sort_source.get(i).RunTime - sort_source.get(i).getArrival() + sort_source.get(i).getAction();
        }
        System.out.println(ART/ source.length);

        //---------------각 프로세스별 반환 시간---------------//
        System.out.println("각 프로세스별 반환 시간");
        for(int i=0; i<sort_source.size(); i++){
            System.out.println(sort_source.get(i).getID() + " : " + (sort_source.get(i).RunTime - sort_source.get(i).getArrival() + sort_source.get(i).getService()));
        }

        //---------------프로세스 평균 반환 시간---------------//
        System.out.println("프로세스 평균 반환 시간");
        double ATT = 0;
        for(int i=0; i<sort_source.size(); i++){
            ATT += sort_source.get(i).RunTime - sort_source.get(i).getArrival() + sort_source.get(i).getService();
        }
        System.out.println(ATT/source.length);
    }
}
