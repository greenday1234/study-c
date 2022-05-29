import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;
class Student{
	private String name;
	private String work;
	private String num;
	private String average;
	
	public Student(String name, String work, String num, String average) {
		this.name = name;
		this.work = work;
		this.num = num;
		this.average = average;
	}
	public String getName() {
		return name;
	}
	public String getwork() {
		return work;
	}
	public String getnum() {
		return num;
	}
	public String getaverage() {
		return average;
	}
}
public class ArrayListStudent {
	Scanner scanner = new Scanner(System.in);
	ArrayList<Student> al = new ArrayList<Student>();
	
	private void read() {
		System.out.println("학생 이름, 학과, 학번, 학점평균 입력하세요.");
		for(int i=0;i<4;i++) {
		System.out.print(">>");
		String str = scanner.nextLine();
		StringTokenizer s = new StringTokenizer(str, ", ");
		String name = s.nextToken();
		String work = s.nextToken();
		String num = s.nextToken();
		String average = s.nextToken();
		Student stu = new Student(name, work, num, average);
		al.add(stu);
		}
	}
	private void printAll() {
		for(int i=0;i<al.size();i++) {
			System.out.println("----------------------------");
			System.out.println("이름 : " + al.get(i).getName());
			System.out.println("학과 : " + al.get(i).getwork());
			System.out.println("학번 : " + al.get(i).getnum());
			System.out.println("학점 평균 : " + al.get(i).getaverage());
			System.out.println("----------------------------");
		}
	}
	private void processQuery() {
		while(true) {
			int count=0;
			System.out.print("학생 이름>>");
			String name = scanner.nextLine();
			if(name.equals("그만"))
				break;
			for(int i=0;i<al.size();i++) {
				if(al.get(i).getName().equals(name)) {
					System.out.println(al.get(i).getName() +", " +  al.get(i).getwork()
							+ ", " + al.get(i).getnum() + ", " + al.get(i).getaverage());
					count++;
				}
			}
			if(count==0) {
				System.out.println("학생이 없습니다.");
			}
		}
	}
	
	public void run() {
		read();
		printAll();
		processQuery();
		scanner.close();
	}
	public static void main(String[] args) {
		ArrayListStudent student = new ArrayListStudent();
		student.run();
		
	}
}
