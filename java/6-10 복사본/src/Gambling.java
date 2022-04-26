import java.util.Scanner;

class Person{
	private String name;
	public Person(String name) {
		this.name = name;
	}
	String getName() {
		return name;
	}
}
public class Gambling{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("1번째 선수 이름>>");
		String name1 = scanner.nextLine();
		System.out.print("2번째 선수 이름>>");
		String name2 = scanner.nextLine();
		Person p[] = new Person[2];
		p[0] = new Person(name1);
		p[1] = new Person(name2);
		int r1;
		int r2;
		int r3;
		while(true) {
			System.out.println("[" + p[0].getName() + "]:<Enter>");
			r1 = (int)(Math.random()*3+1);
			r2 = (int)(Math.random()*3+1);
			r3 = (int)(Math.random()*3+1);
			scanner.nextLine();
			System.out.print("\t" + r1 + " " + r2 + " " + r3 + " ");
			if(r1 == r2 && r1 == r3) {
				System.out.println(p[0].getName() + "님이 이겼습니다!");
				break;
			}
			else {
				System.out.println("아쉽군요!");
			}
			System.out.println("[" + p[1].getName() + "]:<Enter>");
			r1 = (int)(Math.random()*3+1);
			r2 = (int)(Math.random()*3+1);
			r3 = (int)(Math.random()*3+1);
			scanner.nextLine();
			System.out.print("\t" + r1 + " " + r2 + " " + r3 + " ");
			if(r1 == r2 && r1 == r3) {
				System.out.println(p[1].getName() + "님이 이겼습니다!");
				break;
			}
			else {
				System.out.println("아쉽군요!");
			}
		}
		scanner.close();
	}
}