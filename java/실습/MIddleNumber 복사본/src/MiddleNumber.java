import java.util.Scanner;

public class MiddleNumber{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("정수 3개 입력>> ");
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int c = scanner.nextInt();
		
		if(a>b&&a<c)
			System.out.println("중간 값은 " + a + "입니다.");
		else if(b>a&&b<c)
			System.out.println("중간 값은 " + b + "입니다.");
		else
			System.out.println("중간 값은 " + c + "입니다.");
		
		
		scanner.close();
		
		
	}
}