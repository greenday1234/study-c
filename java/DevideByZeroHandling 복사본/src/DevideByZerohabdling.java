import java.util.Scanner;

public class DevideByZerohabdling{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		while(true) {
			System.out.print("나뉨수를 입력하시오:");
			int devidend = scanner.nextInt();
			
			System.out.print("나눗수를 입력하시오:");
			int divisor = scanner.nextInt();
			
			try {
				System.out.println(devidend + "를 " + divisor + "로 나누면 몫은 " + devidend/divisor + "입니다.");
				break;
			}
			catch(ArithmeticException e) {
				System.out.println("0으로 나눌 수 없습니다. 다시 입력하세요.");
			}
		}
		scanner.close();
	}
}