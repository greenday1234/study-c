import java.util.Scanner;

public class Game {
	public static void main(String args[])
	{
		int num;
		int count=0;	//박수의 수
		Scanner scanner = new Scanner(System.in);
		System.out.print("1~99 사이의 정수를 입력하시오>");
		num=scanner.nextInt();
		
		if(num>=1 && num<= 99) {
			int a,b;
			a=num/10;	//a는 10의자리
			b=num%10;	//b는 1의자리
			
			if(a!=0 && a%3 == 0)
				count++;
			if(b!=0 && b%3 == 0)
				count++;
			
			if (count == 2)
				System.out.println("박수짝짝");
			else if (count == 1)
				System.out.println("박수짝");
			else
				System.out.println("박수없음");
		}
		else {
			System.out.println("숫자의 범위를 벗어났습니다.");
		}
		scanner.close();
	}
}