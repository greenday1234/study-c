package Scheduling;

import java.util.ArrayList;
import java.util.Arrays;

public class HRN {

    public HRN(Source[] source){
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
        System.out.println("HRN Scheduling");
        //---------------간트 차트---------------//
        System.out.println("간트 차트");
        System.out.print("[ ");
        double x;
        int tmp;
        while(run < total){
            x = 0;
            tmp = 0;
            if(n_source.get(0).getArrival() == 0){
                for(int i=0; i<n_source.get(0).getService(); i++) {
                    System.out.print(n_source.get(0).getID() + " ");
                    run++;
                }
                sort_source.add(new Source(n_source.get(0).getID(), n_source.get(0).getArrival(), n_source.get(0).getService(),
                        n_source.get(0).getPriority(), (run-n_source.get(0).getService())));
                n_source.remove(0);
            }
            else {
                for(int i=0; i<n_source.size(); i++) {
                    if(run < n_source.get(i).getArrival()){
                        n_source.get(i).Temp = 1;
                    }
                    else{
                        n_source.get(i).Temp = 0;
                    }
                }
                for(int i=0; i< n_source.size(); i++){
                    if(x < ((run - n_source.get(i).getArrival()) + n_source.get(i).getService())/n_source.get(i).getService() && n_source.get(i).Temp == 0){
                        x = ((run - n_source.get(i).getArrival()) + n_source.get(i).getService())/n_source.get(i).getService();
                        tmp = i;
                    }
                }
                for(int i=0; i<n_source.get(tmp).getService(); i++){
                    System.out.print(n_source.get(tmp).getID() + " ");
                    run++;
                }
                sort_source.add(new Source(n_source.get(tmp).getID(), n_source.get(tmp).getArrival(), n_source.get(tmp).getService(),
                        n_source.get(tmp).getPriority(), (run-n_source.get(tmp).getService())));
                n_source.remove(tmp);
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