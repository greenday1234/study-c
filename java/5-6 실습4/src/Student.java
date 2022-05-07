import java.util.ArrayList;
import java.util.Scanner;

public class Student {
	private String name;
	private String work;
	private String num;
	private double average;
	public Student(String name, String work, String num, double average) {
		this.name = name;
		this.work = work;
		this.num = num;
		this.average = average;
	}
	public String toString() {
		return "이름: " + name + "\n학과: " + work + "\n학번: " + num + "\n학점 평균: " + average + "\n";
	}
	public void setName(String name) {
		
	}
	public String getName() {
		return name;
	}
	public void setwork(String work) {
		
	}
	public String getwork() {
		return work;
	}
	public void setnum(String num) {
		
	}
	public String getnum() {
		return num;
	}
	public void setaverage(int average) {
		
	}
	public double getaverage() {
		return average;
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		ArrayList<Student> a = new ArrayList<Student>();
		Student s[] = new Student[4];
		System.out.println("학생 이름, 학과, 학번, 학점 평균을 입력하세요.");	//스플릿이나 토크나이저사용
		for(int i=0;i<4;i++) {
			System.out.print(">>");
			String name = scanner.next();
			String work = scanner.next();
			String num = scanner.next();
			double average = scanner.nextDouble();
			s[i] =new  Student(name, work, num, average);
			a.add(s[i]);
		}
		for(int i=0;i<a.size();i++) {
			System.out.println("--------------------------------------");
			System.out.print(s[i].toString());
			System.out.println("--------------------------------------");
		}
		while(true) {
			System.out.print("학생 이름 >>");
			String name1 = scanner.next();
			if(name1.equals("그만")) {
				break;
			}
			if(a.contains(name1)) {
				int temp = a.indexOf(name1);
				System.out.println(s[temp].toString());
			}
			else {
				System.out.println("없습니다.");
			}
		}
		scanner.close();
	}
}
