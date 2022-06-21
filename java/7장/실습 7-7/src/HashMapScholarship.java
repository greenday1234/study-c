import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

class Student{
	private String name;
	private double score;
	
	public Student(String name, double score) {
		this.name = name;
		this.score = score;
	}
	
	public String getName() {
		return name;
	}
	
	public double getscore() {
		return score;
	}
}

public class HashMapScholarship {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		HashMap<String, Student> h = new HashMap<String, Student>();
		System.out.println("미래장학금관리시스템입니다.");
		for(int i=0;i<5;i++) {
			System.out.print("이름과 학점>>");
			String name = scanner.next();
			double score = scanner.nextDouble();
			
			h.put(name, new Student(name, score));
		}
		
		Set<String> keys = h.keySet();
		Iterator<String> it = keys.iterator();
		
		System.out.print("장학생 선발 학점 기준 입력>>");
		double line = scanner.nextDouble();
		
		System.out.print("장학생 명단 : ");
		
		while(it.hasNext()) {
			String name = it.next();
			Student st = h.get(name);
			if(st.getscore() >= line) {
				System.out.print(st.getName() + " ");
			}
		}
		
	}
}
