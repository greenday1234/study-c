import java.util.Scanner;

public class ACalculator{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("연산>>");
		double x = scanner.nextDouble();
		String operator = scanner.next();
		double y = scanner.nextDouble();
		
		double num=0;
		
		if(operator.equals("+"))
			num= x+y;
		else if(operator.equals("-"))
			num=x-y;
		else if(operator.equals("*"))
			num=x*y;
		else if(operator.equals("/"))
		{
			if(x!=0&&y!=0)
			num=x/y;
			else
				System.out.println("0으로 나눌 수 없습니다.");
		}
		else
			System.out.println("연산자가 아닙니다.");
		
		
		System.out.println(x + operator + y + "의 계산 결과는 " + num);
		
		scanner.close();
		
		
	}
}