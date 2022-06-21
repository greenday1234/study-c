import java.util.Scanner;

public class ChangeUsa{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("원화를 입력하세요(단위 원) >> ");
		int money = scanner.nextInt();
		
		double usa;
		usa = money/1100;
		System.out.println(money + "원은 $" + usa + "입니다.");
		
		scanner.close();
	}
}