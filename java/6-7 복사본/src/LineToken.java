import java.util.Scanner;
import java.util.StringTokenizer;
public class LineToken{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while(true) {
		System.out.print(">>");
		String str = scanner.nextLine();
		if(str.equals("�׸�")) {
			System.out.println("�����մϴ�.");
			break;
		}
		StringTokenizer st = new StringTokenizer(str, " ");
		int n = st.countTokens();
		System.out.println("���� ������ " + n);
		}
		scanner.close();
	}
}