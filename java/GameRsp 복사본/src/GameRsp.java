import java.util.Scanner;

public class GameRsp{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		String str[] = {"가위", "바위", "보"};
		int n;
		String choice;
		System.out.println("가위바위보 게임을 컴퓨터와 합니다.");
		while(true) {
			System.out.print("가위 바위 보!>>");
			choice = scanner.next();
			n = (int)(Math.random()*3);
			if(choice.equals("바위")) {
				System.out.print("사용자 = 바위 , ");
				if(str[n].equals("바위")) 
					System.out.println("컴퓨터 = 바위, 비겼습니다." );
				else if(str[n].equals("가위")) 
					System.out.println("컴퓨터 = 가위, 사용자가 이겼습니다.");
				else
					System.out.println("컴퓨터 = 보, 사용자가 졌습니다.");
			}
			else if(choice.equals("가위")) {
				System.out.print("사용자 = 가위 , ");
				if(str[n].equals("가위"))
					System.out.println("컴퓨터 = 가위 , 비겼습니다.");
				else if(str[n].equals("바위"))
					System.out.println("컴퓨터 = 바위 , 사용자가 졌습니다.");
				else
					System.out.println("컴퓨터 = 보, 사용자가 이겼습니다.");
			}
			else if(choice.equals("보")) {
				System.out.print("사용자 = 보 , ");
				if(str[n].equals("보"))
					System.out.println("컴퓨터 = 보 , 비겼습니다.");
				else if(str[n].equals("가위"))
					System.out.println("컴퓨터 = 가위 , 사용자가 졌습니다.");
				else
					System.out.println("컴퓨터 = 바위 , 사용자가 이겼습니다.");
			}
			else if(choice.equals("그만"))
				break;
		}
		scanner.close();
		
		
	}
}