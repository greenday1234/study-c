import java.util.Scanner;

public class MoneyUnit{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("금액을 입력하시오>>");
		int n = scanner.nextInt();
		int count;
		int unit[] = {50000, 10000, 1000, 500, 100, 50, 10, 1};
		
		for(int i=0;i<8;i++) {
			if(n>unit[i]) {
				count = n/unit[i];
				System.out.println(unit[i] +"원 짜리 : " + count + "개");
				count=0;
				n=n%unit[i];
			}
		}
		scanner.close();
	}
}