import java.util.Scanner;
import java.util.InputMismatchException;

public class InputException{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("정수 3개를 입력하세요.");
		
		int a = 0;
		int sum = 0;
		for(int i=0;i<3;i++) {
			System.out.print(i + ">>");
			try {
		 a = scanner.nextInt();
		} catch(InputMismatchException e) {
			System.out.println("정수가 아닙니다. 다시 입력하세요.");
			scanner.nextLine();
			i--;
			continue;
		}
			sum+=a;
			}
		System.out.println("합은 " + sum);
		scanner.close();
		
	}
}