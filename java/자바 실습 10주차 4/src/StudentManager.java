import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class StudentManager {
	private Scanner scanner = new Scanner(System.in);
	private ArrayList<Student> dept = new ArrayList<Student>();

	private void read() {
		System.out.println("학생 이름, 학과, 학번, 학점평균을 입력하시오.");
		for(int i=0;i<4;i++) {
		System.out.print(">>");
		String str = scanner.nextLine();
		StringTokenizer s = new StringTokenizer(str, ", ");
		String name = s.nextToken();
		String work = s.nextToken();
		String num = s.nextToken();
		String average = s.nextToken();
		Student stu = new Student(name, work, num, average);
		dept.add(stu);
		}
	}
	
	private void printAll() {
		for(int i=0;i<dept.size();i++) {
		System.out.println("-----------------");
		System.out.print("이름 : " + dept.get(i).getName() + "\n");
		System.out.print("학과 : " + dept.get(i).getwork() + "\n");
		System.out.print("학번 : " + dept.get(i).getnum() + "\n");
		System.out.print("학점평균 : " + dept.get(i).getaverage() + "\n");
		System.out.println("-----------------");
		}
	}
	
	private void processQuery() {
		while(true) {
			int count=0;
			System.out.print("학생 이름>>");
			String st = scanner.nextLine();
			if(st.equals("그만")) {
				break;
			}
			for(int i=0;i<dept.size();i++) {
				if(st.equals(dept.get(i).getName())) {
					System.out.println(dept.get(i).getName() + ", " + dept.get(i).getwork() + ", "
				+ dept.get(i).getnum() + ", " + dept.get(i).getaverage());
					count++;
				}
			}
			if(count == 0) {
				System.out.println("찾을 수 없습니다.");
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
		StudentManager manager = new StudentManager();
		manager.run();
	}
}
