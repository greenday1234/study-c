import java.util.Scanner;

public class ChangeWon{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("금액을 입력하시오>> ");
		int money = scanner.nextInt();
		
		int five = money/50000;
		int mil = money%50000/10000;
		int th = money%50000%10000/1000;
		int hu = money%50000%10000%1000/100;
		int fif = money%50000%10000%1000%100/50;
		int ten = money%50000%10000%1000%100%50/10;
		int one = money%50000%10000%1000%100%50%10/1;
		
		System.out.println("오만원권" + five + "매");
		System.out.println("만원권" +mil + "매");
		System.out.println("천원권" + th + "매");
		System.out.println("백원" + hu + "개");
		System.out.println("오십원" + fif + "개");
		System.out.println("십원" + ten + "개");
		System.out.println("일원" + one + "개");

		scanner.close();


		
		}
}