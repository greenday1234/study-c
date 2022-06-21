import java.util.Scanner;

public class SeasonI{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("달을 입력하세요(1~12)>>");
		int season = scanner.nextInt();
		
		if(season>=3 && season<=5)
			System.out.println("봄");
		else if(season >=6 && season<=8)
			System.out.println("여름");
		else if(season >=9 && season <=11)
			System.out.println("가을");
		else if(season<=2 || season == 12)
			System.out.println("겨울");
		else
			System.out.println("잘못입력");
		
		scanner.close();
	}
}