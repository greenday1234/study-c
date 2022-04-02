import java.util.Scanner;

public class Group{
	private char type;
	private Seat[] seats;
	private Scanner scanner = new Scanner(System.in);
	public Group(char type, int num) {
		this.type = type;
		seats = new Seat[num];
		for(int i=0;i<seats.length;i++) 
			seats[i] = new Seat();
	}
	
	public boolean reserve() {
		String name;
		int no;
		
		Show();
		System.out.print("이름>>");
		name = scanner.next();
		System.out.print("번호>>");
		no = scanner.nextInt();
		
		if (no < 1 || no>=seats.length) {
			System.out.println("잘못된 좌석번호입니다.");
			return false;
		}
		
		if(seats[no - 1]. isOccupied()) {
			System.out.println("이미 예약된 좌석입니다.");
			return false;
		}
		
		seats[no-1].reserve(name);
		return true;
	}
	public boolean cancel() {
		Show();
		System.out.println("이름>>");
		String name = scanner.next();
		if(name!=null) {
			for(int i=0;i<seats.length;i++) {
				if(seats[i].match(name)) {
					seats[i].cancel();
					return true;
				}
			}
			System.out.println("예약자 이름을 찾을 수 없습니다.");
		}
		return false;
	}
	
	public void Show() {
		System.out.print(type + ">>");
		for(int i=0;i<seats.length;i++) {
			if(seats[i].isOccupied())
		System.out.print(seats[i].getName());
			else
				System.out.print("---");
			System.out.print(" ");
		}
		System.out.println();
	}
}