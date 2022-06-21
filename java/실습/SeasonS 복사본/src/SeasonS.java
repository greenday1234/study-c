import java.util.Scanner;

public class SeasonS{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("달을 입력하세요(1~12)>>");
		int season = scanner.nextInt();
		
		switch(season)
		{
		case 1,2,12:
			System.out.println("겨울");
		break;
		case 3,4,5 :
			System.out.println("봄");
		break;
		case 6,7,8 :
			System.out.println("여름");
		break;
		case 9,10,11 :
			System.out.println("가을");
		break;
		default :
			System.out.println("잘못입력");
			break;
				
		}
		scanner.close();
	}
}