import java.util.Scanner;

public class LineToken{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while(true) {
		System.out.print(">>");
		String str = scanner.nextLine();
		if(str.equals("�׸�"))
		{
			System.out.println("�����մϴ�.");
			break;
		}
		String s[] = str.split(" ");
		System.out.println("���� ������ " + s.length);
		}
		scanner.close();
	}
}