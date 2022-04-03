import java.util.Scanner;

class Day{
	public String work;

	public void set(String work) {
		this.work = work;
	}
	public String get() {
		return work;
	}
	public void show() {
		if(work==null)
			System.out.println("없습니다.");
		else
			System.out.println(work + "입니다.");
	}
}
public class MonthSchedule{
	private Scanner scanner = new Scanner(System.in);
	int n;
	Day [] d;
	
	public MonthSchedule(int n) {
		this.n = n;
		d = new Day[n];
		for(int i=0;i<d.length;i++)
			d[i]= new Day();
	}
	void input() {
		System.out.print("날짜(1~30)?");
		int day = scanner.nextInt();
		scanner.nextLine();
		System.out.print("할일(빈칸없이입력)?");
		String w = scanner.nextLine();
		d[day-1].set(w);
	}
	void view() {
		System.out.print("날짜(1~30)?");
		int viewday = scanner.nextInt();
		System.out.print(viewday + "일의 할 일은 ");
		d[viewday-1].show();
	}
	void finish() {
		System.out.println("프로그램을 종료합니다.");
	}
	void run() {
		System.out.println("이번달 스케쥴 관리 프로그램");
		
		
		while(true) {
			System.out.print("할일 (입력:1, 보기:2, 끝내기:3) >>");
			int num = scanner.nextInt();
		if(num==1)
			input();
		else if(num==2)
			view();
		else if(num==3) {
			finish();
			break;
		}
		else
			System.out.println("1~3 사이의 값을 입력해주세요.");
		}
	}
	public static void main(String[] args) {
		MonthSchedule april = new MonthSchedule(30);
		april.run();
	}
}