import java.util.*;

public class Spin{
	public static void main(String[] args) {
		System.out.println("���ڿ��� �Է��ϼ���. �� ĭ�̳� �־ �ǰ� ���� �ѱ� ��� �˴ϴ�.");
		Scanner scanner = new Scanner(System.in);
		String s = scanner.nextLine();
		int len = s.length();
		
		for(int i=0;i<len;i++) {
			String first = s.substring(0, 1);	//first = i
			String last = s.substring(1);	//last = love you
			s = last + first;
			System.out.println(s);
		}
		scanner.close();
	}
}