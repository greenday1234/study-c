import java.util.Scanner;

public class SameNumber{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("2자리수 정수 입력(10~99) >> ");
		int num = scanner.nextInt();
		int cnt;
		int count;
		
		cnt=num/10;
		count=num%10;
		if(cnt == count)
			System.out.println("yes! 10의 자리와 1의 자리가 같습니다.");
		else
			System.out.println("no! 10의 자리와 1의 자리가 같지 않습니다.");
		
		scanner.close();
	}
}