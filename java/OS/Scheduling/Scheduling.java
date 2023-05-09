package Scheduling;

import java.util.*;
import java.io.*;

class Source {
    String ID;
    int Arrival;
    int Service;
    int Priority;
    int Time;
    int Action = 1;
    int RunTime;    //실행된 시간
    int Temp = 0;   //프로세스가 도착했는지 확인
    int RT;
    public Source(String ID, int Arrival, int Service, int Priority, int RunTime, int RT){
        this.ID = ID;
        this.Arrival = Arrival;
        this.Service = Service;
        this.Priority = Priority;
        this.RunTime = RunTime;
        this.RT = RT;
    };
    public void setTime(int Time){ this.Time = Time; }
    public String getID(){ return ID; }
    public int getArrival(){ return Arrival; }
    public int getService(){ return Service; }
    public int getPriority(){ return Priority; }
    public int getAction(){ return Action; }
}

public class Scheduling {
    public static void main(String args[]) throws IOException {
        //데이터 값 변수
        int ProcessCount;
        String str;
        String ID;
        int Arrival;
        int Service;
        int Priority;
        int Time;
        Scanner scanner = new Scanner(new File("./Input.txt"));
        //파일에서 데이터 읽어서 객체 배열에 값 넣기
        ProcessCount = Integer.parseInt(scanner.nextLine());
        Source[] source = new Source[ProcessCount];

        for (int i = 0; i < ProcessCount; i++) {
            str = scanner.nextLine();
            String[] arr = str.split(" ");
            ID = arr[0];
            Arrival = Integer.parseInt(arr[1]);
            Service = Integer.parseInt(arr[2]);
            Priority = Integer.parseInt(arr[3]);
            source[i] = new Source(ID, Arrival, Service, Priority, 0, 0);
        }

        Time = Integer.parseInt(scanner.nextLine());
        for(int i=0; i<ProcessCount; i++){
            source[i].setTime(Time);
        }

        //FCFS fcfs = new FCFS(source);
        //SJF sjf = new SJF(source);
        //Non_Priority np = new Non_Priority(source);
        Priority pri = new Priority(source);
        //RR rr = new RR(source);
        //SRT srt = new SRT(source);
        //HRN hrn = new HRN(source);


    }
}
