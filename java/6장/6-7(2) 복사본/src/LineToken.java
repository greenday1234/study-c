import java.util.Scanner;

public class LineToken{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while(true) {
		System.out.print(">>");
		String str = scanner.nextLine();
		if(str.equals("그만"))
		{
			System.out.println("종료합니다.");
			break;
		}
		String s[] = str.split(" ");
		System.out.println("어절 개수는 " + s.length);
		}
		scanner.close();
	}
}