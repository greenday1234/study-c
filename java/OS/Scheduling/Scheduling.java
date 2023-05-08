package Scheduling;

import java.util.*;
import java.io.*;

class Sorce {
    String ID;
    int Arrival;
    int Service;
    int Priority;
    int Time;
    int Action = 1;
    public Sorce(String ID, int Arrival, int Service, int Priority){
        this.ID = ID;
        this.Arrival = Arrival;
        this.Service = Service;
        this.Priority = Priority;
    };
    public void setTime(int Time){ this.Time = Time; }
    public String getID(){ return ID; }
    public int getArrival(){ return Arrival; }
    public int getService(){ return Service; }
    public int getPriority(){ return Priority; }
    public int getAction(){ return Action; }

    public Sorce(Sorce sorce){
        this.ID = sorce.ID;
        this.Arrival = sorce.Arrival;
        this.Service = sorce.Service;
        this.Priority = sorce.Priority;
    }
}

class Priority_Sorce extends Sorce{
    public Priority_Sorce(String ID, int Arrival, int Service, int Priority){
        super(ID, Arrival, Service, Priority);
    }

    public int compareTo(Priority_Sorce priority_sorce) {
        int compareP=((Priority_Sorce)priority_sorce).getPriority();
        return this.getPriority() - compareP;
    }
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
        Sorce[] sorce = new Sorce[ProcessCount];

        for (int i = 0; i < ProcessCount; i++) {
            str = scanner.nextLine();
            String[] arr = str.split(" ");
            ID = arr[0];
            Arrival = Integer.parseInt(arr[1]);
            Service = Integer.parseInt(arr[2]);
            Priority = Integer.parseInt(arr[3]);
            sorce[i] = new Sorce(ID, Arrival, Service, Priority);
        }

        Time = Integer.parseInt(scanner.nextLine());
        for(int i=0; i<ProcessCount; i++){
            sorce[i].setTime(Time);
        }

        FCFS fcfs = new FCFS(sorce);
        //SJF sjf = new SJF(sorce);
        //Non_Priority np = new Non_Priority(sorce);
        //Priority pri = new Priority(sorce);
        //RR rr = new RR(sorce);
        //SRT srt = new SRT(sorce);
        //HRN hrn = new HRN(sorce);


    }
}
