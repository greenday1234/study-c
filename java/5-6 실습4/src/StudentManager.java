import java.util.ArrayList;
import java.util.Scanner;

public class StudentManager {
	private Scanner scanner = new Scanner(System.in);
	private ArrayList<Student> dept = new ArrayList<Student>();
	
	private void read() {
		System.out.println("학생 이름, 학과, 학점, 학점평균을 입력하시오.");
	}
	private void printAll() {
		
	}
	private void processQuery() {
		
	}
	
	public void run() {
		read();
		printAll();
		processQuery();
	}
	public static void main(String[] args) {
		StudentManager manager = new StudentManager();
	}
}
