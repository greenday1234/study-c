import java.util.Scanner;

public class CircleRadius{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int x, y;
		System.out.print("첫번째 원의 중심과 반지름 입력>");
		int x1 = scanner.nextInt();
		int y1 = scanner.nextInt();
		int r1 = scanner.nextInt();
		
		System.out.print("두번째 원의 중심과 반지름 입력>");
		int x2 = scanner.nextInt();
		int y2 = scanner.nextInt();
		int r2 = scanner.nextInt();
		
		x=x1-x2;
		y=y1-y2;
		
		if(x*x+y*y<r1+r2) {
			System.out.println("두 원은 서로 겹치지 않습니다.");
		}
		else
			System.out.println("두 원은 서로 겹칩니다.");
			
		scanner.close();
	}
}