import java.util.Scanner;

class Add{
	int a;
	int b;
	
	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	int calculate() {
		return a+b;
	}
}
class Sub{
	int a;
	int b;
	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	int calculate() {
		return a-b;		
	}
}
class Mul{
	int a;
	int b;
	void setValue(int a, int b) {
		this.a = a;
		this.b = b;
	}
	int calculate() {
		return a*b;
	}
}
class Div{
	int a;
	int b;
	void setValue(int a, int b) {
		this.a = a;
		this. b = b;
	}
	int calculate() {
		return a/b;
	}
}
public class calculator{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int result;
		System.out.print("두 정수와 연산자를 입력하시오>>");
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		String c = scanner.next();
		
		switch(c) {
		case "+":
			Add add = new Add();
			add.setValue(a,b);
			result = add.calculate();
			System.out.println(result);
			break;
		case "-":
			Sub sub = new Sub();
			sub.setValue(a,b);
			result = sub.calculate();
			System.out.println(result);
			break;
		case "*":
			Mul mul = new Mul();
			mul.setValue(a, b);
			result = mul.calculate();
			System.out.println(result);
			break;
		case "/":
			Div div = new Div();
			div.setValue(a,b);
			result = div.calculate();
			System.out.println(result);
			break;
		default :
			System.out.println("올바르지 않은 연산자입니다.");
			break;
		}
		scanner.close();
	}
}