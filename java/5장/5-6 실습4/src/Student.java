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
		return "�̸�: " + name + "\n�а�: " + work + "\n�й�: " + num + "\n���� ���: " + average + "\n";
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
		System.out.println("�л� �̸�, �а�, �й�, ���� ����� �Է��ϼ���.");	//���ø��̳� ��ũ���������
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
			System.out.print("�л� �̸� >>");
			String name1 = scanner.next();
			if(name1.equals("�׸�")) {
				break;
			}
			if(a.contains(name1)) {
				int temp = a.indexOf(name1);
				System.out.println(s[temp].toString());
			}
			else {
				System.out.println("�����ϴ�.");
			}
		}
		scanner.close();
	}
}
