import java.util.Scanner;

public class Math{
	
	public static void main(String args[]) {
		int num;
		
		Scanner scanner = new Scanner(System.in);
		System.out.print("������Է�>>");
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
				System.out.println("0���� ���� �� �����ϴ�.");
				scanner.close();
				return;
			}
			result=op1/op2;
			break;
			default:
				System.out.println("��Ģ���길 �����մϴ�.");
				scanner.close();
				return;
		}
		System.out.println(op1 + op + op2 + "�� ������� " + result);
		scanner.close();
		
	}
}