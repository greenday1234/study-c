import java.util.Scanner;
import java.util.StringTokenizer;
public class LineToken{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while(true) {
		System.out.print(">>");
		String str = scanner.nextLine();
		if(str.equals("그만")) {
			System.out.println("종료합니다.");
			break;
		}
		StringTokenizer st = new StringTokenizer(str, " ");
		int n = st.countTokens();
		System.out.println("어절 개수는 " + n);
		}
		scanner.close();
	}
}