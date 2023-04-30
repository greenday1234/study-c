import java.util.Scanner;

public class Math{

	public static void main(String args[]) {

		Scanner scanner = new Scanner(System.in);
		System.out.print("연산 입력>>");
		int op1 = scanner.nextInt();
		String op = scanner.next();
		int op2 = scanner.nextInt();
		int result = 0;

		switch(op) {
		case "+":
			result=op1+op2;
			break;
		case "-":
			result=op1-op2;
			break;
		case "*":
			result=op1*op2;
			break;
		case "/":
			if(op2 == 0) {
				System.out.println("0으로 나눌 수 없습니다.");
				scanner.close();
				return;
			}
			result=op1/op2;
			break;
			default:
				System.out.println("연산자만 입력가능합니다.");
				scanner.close();
				return;
		}
		System.out.println(op1 + op + op2 + "의 계산 결과는 " + result);
		scanner.close();

	}
}