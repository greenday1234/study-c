import java.util.Scanner;

public class RSPgame{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int r;
		while(true) {
			System.out.print("철수[가위(1), 바위(2), 보(3), 끝내기(4)]>>");
			int n = scanner.nextInt();
			r = (int)(Math.random()*3+1);
			if(n == 1) {
				System.out.print("철수(가위) : ");
				if(r == 1) {
					System.out.println("컴퓨터(가위)");
					System.out.println("비겼습니다.");
				}
				else if(r == 2) {
					System.out.println("컴퓨터(바위)");
					System.out.println("컴퓨터가 이겼습니다.");
				}
				else {
					System.out.println("컴퓨터(보)");
					System.out.println("철수가 이겼습니다.");
				}
			}
			else if(n == 2) {
				System.out.println("철수(바위) : ");
				if(r == 1) {
					System.out.println("컴퓨터(가위)");
					System.out.println("철수가 이겼습니다.");
				}
				else if(r == 2) {
					System.out.println("컴퓨터(바위)");
					System.out.println("비겼습니다.");
				}
				else {
					System.out.println("컴퓨터(보)");
					System.out.println("컴퓨터가 이겼습니다.");
				}
			}
			else if(n == 3) {
				System.out.println("철수(보) : ");
				if(r == 1) {
					System.out.println("컴퓨터(가위)");
					System.out.println("컴퓨터가 이겼습니다.");
				}
				else if(r == 2) {
					System.out.println("컴퓨터(바위)");
					System.out.println("철수가 이겼습니다.");
				}
				else {
					System.out.println("컴퓨터(보)");
					System.out.println("비겼습니다.");
				}
			}
			else if(n == 4) {
				break;
			}
		}
		scanner.close();
	}
}