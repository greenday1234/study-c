package Scheduling;

import java.util.AbstractList;
import java.util.ArrayList;
import java.util.Arrays;

public class Priority {
    public Priority(Source[] source){
        Source[] new_source = new Source[source.length];
        ArrayList<Source> n_source = new ArrayList<Source>();
        Source[] arr_source = new Source[source.length];
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
        System.out.println("Preemptive Priority Scheduling");
        //---------------간트 차트---------------//
        System.out.println("간트 차트");
        System.out.print("[ ");
        int tmp = 0;
        Source box = new Source(n_source.get(0).getID(), n_source.get(0).getArrival(),
                n_source.get(0).getService(), n_source.get(0).getPriority(), 0);
        n_source.remove(0);
        while(run < total){
            if(!n_source.isEmpty() && n_source.get(0).getArrival() == run){
                //도착한 프로세스의 우선순위가 실행중인 프로세스의 우선순위보다 높은 경우
                if(n_source.get(0).getPriority() < box.getPriority()){
                    sort_source.add(new Source(box.getID(), box.getArrival(), (run-box.getArrival()), box.getPriority(), (run-box.getArrival())));
                    total -= box.getService() - (run-box.getArrival());
                    arr_source[tmp++] = new Source(box.getID(), box.getArrival(),
                            box.getService()-(run-box.getArrival()), box.getPriority(), 0);
                    box = new Source(n_source.get(0).getID(), n_source.get(0).getArrival(),
                            n_source.get(0).getService(), n_source.get(0).getPriority(), 0);
                    n_source.remove(0);
                }
                //도착한 프로세스의 우선순위가 실행중인 프로세스의 우선순위보다 낮은 경우
                else{
                    arr_source[tmp++] = new Source(n_source.get(0).getID(), n_source.get(0).getArrival(),
                            n_source.get(0).getService(), n_source.get(0).getPriority(), 0);
                    total -= n_source.get(0).getService();
                    n_source.remove(0);
                }
            }
            System.out.print(box.getID() + " ");
            run++;
            //실행을 마친 경우
            if(box.getService() == run-box.getArrival()){
                sort_source.add(new Source(box.getID(), box.getArrival(), (run-box.getArrival()), box.getPriority(), (run-box.getArrival())));
                box = new Source(n_source.get(0).getID(), n_source.get(0).getArrival(),
                        n_source.get(0).getService(), n_source.get(0).getPriority(), 0);
            }
        }

        if(tmp > 1) {
            Arrays.sort(arr_source, 0, tmp, (a, b) -> a.getPriority() - b.getPriority());
        }

        for(int i=0; i<tmp; i++){
            if(arr_source[i].getService() != 0){
                sort_source.add(new Source(arr_source[i].getID(), arr_source[i].getArrival(),
                    arr_source[i].getService(), arr_source[i].getPriority(), run));
            for(int k=0; k<arr_source[i].getService(); k++) {
                System.out.print(arr_source[i].getID() + " ");
                run++;
            }

            }
        }

        System.out.println("]");
        //대기시간 부터 시작할 것
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
