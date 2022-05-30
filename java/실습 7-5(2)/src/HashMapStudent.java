import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;
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
public class HashMapStudent {
	Scanner scanner = new Scanner(System.in);
	HashMap<String, Student> h = new HashMap<String, Student>();
	
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
		
		h.put(name, new Student(name, work, num, average));
		}
	}
	private void printAll() {
			Set<String> keys = h.keySet();
			Iterator<String> it = keys.iterator();	//순차정렬이므로 순서가 바뀔 수 있음.
			while(it.hasNext()) {
				String st = it.next();
				Student std = h.get(st);
			System.out.println("----------------------------");
			System.out.println("이름 : " + std.getName());
			System.out.println("학과 : " + std.getwork());
			System.out.println("학번 : " + std.getnum());
			System.out.println("학점 평균 : " + std.getaverage());
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
			Student st = h.get(name);
			if(st != null) {
				System.out.println(st.getName() + ", " + st.getwork() + ", " 
						+ st.getnum() + ", " + st.getaverage());
			}
			else {
				System.out.println("찾는 학생이 없습니다.");
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
		HashMapStudent student = new HashMapStudent();
		student.run();
		
	}
}
