import java.util.ArrayList;
import java.util.Scanner;

public class StudentManager {
	private Scanner scanner = new Scanner(System.in);
	private ArrayList<Student> dept = new ArrayList<Student>();
	
	private void read() {
		System.out.println("�л� �̸�, �а�, ����, ��������� �Է��Ͻÿ�.");
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
