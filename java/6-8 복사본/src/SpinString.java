import java.util.Scanner;

public class SpinString{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("���ڿ��� �Է��ϼ���. ��ĭ�̳� �־ �ǰ� ���� �ѱ� ��� �˴ϴ�.");
		String str = scanner.nextLine();
		for(int i=0;i<str.length();i++) {
			System.out.print(str.substring(i+1,str.length()));
			System.out.println(str.substring(0,i+1));
		}
		scanner.close();
	}
}