import java.util.Scanner;

public class Median {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("정수 3개를 입력하시오>");
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int c = scanner.nextInt();
		int median = a;
		if ((a>=b && a<=c)||(a>=c && a<=b))
			median = a;
		else if ((b>=a && b<=c)||(b>=c && b<=a))
			median = b;
		else
			median = c;
		
		System.out.println("중간 값은 " + median);
	}
}