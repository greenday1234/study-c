import java.util.Scanner;

public class ThreeSixNine{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("1~99사이의 정수를 입력하시오>> ");
		
		int num = scanner.nextInt();
		int a=num/10;	//10의 자리
		int b=num%10;	//1의 자리
		int count=0;
		if(num>99&&num<1)
			System.out.println("숫자의 범위를 벗어났습니다.");
		else
		{
			if(b!=0 && b%3==0)
				count++;
			if(a!=0 && b%3==0)
				count++;
			
			if(count==2)
				System.out.println("박수짝짝");
			else if(count==1)
				System.out.println("박수짝");
			else
				System.out.println("박수없음");
		}
		
		scanner.close();
			
	}
}