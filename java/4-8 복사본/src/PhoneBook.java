import java.util.Scanner;

class Phone{
	String name;
	String tel;
}
public class PhoneBook{
	int n;
	Scanner scanner = new Scanner(System.in);
	Phone p[];
	public PhoneBook() {
				System.out.print("인원수>>");
		int n = scanner.nextInt();
		p= new Phone[n];
		for(int i=0;i<p.length;i++) {
			p[i]=new Phone();
		}
	}
	void run() {
		int count=0;
		for(int i=0;i<p.length;i++) {
			System.out.print("이름과 전화번호(이름과 번호는 빈 칸없이 입력)>>");
			String total = scanner.next();
			String num = scanner.next();
			scanner.nextLine();
			p[i].name = total;
			p[i].tel = num;
		}
		System.out.println("저장되었습니다..");
		while(true) {
			count = 0;
			System.out.print("검색할 이름>>");
			String who = scanner.nextLine();
			if(who.equals("그만"))
				break;
			else {
			for(int i=0;i<p.length;i++) {
			if(who.equals(p[i].name)) {
				System.out.println(who + "의 번호는 " + p[i].tel + "입니다.");
			count++;
				}
			}
			if(count==0)
			System.out.println(who + "이 없습니다.");
			}
		}
	}
	public static void main(String[] args) {
		PhoneBook book = new PhoneBook();
		book.run();
	}
}