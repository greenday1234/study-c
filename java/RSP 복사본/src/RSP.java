import java.util.Scanner;

public class RSP{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("가위바위보 게임입니다. 가위, 바위, 보 중에서 입력하세요.");
		System.out.println("철수 >> ");
		String a = scanner.next();
		System.out.println("영희 >> ");
		String b = scanner.next();
		
		String R = "바위";
		String S = "가위";
		String P = "보";
		if(a.equals(R)) {
			if(b.equals(S))
				System.out.println("철수가 이겼습니다.");
			else if(b.equals(P))
				System.out.println("영희가 이겼습니다.");
			else
				System.out.println("비겼습니다.");
		}
		else if(a.equals(S)) {
			if(b.equals(P))
				System.out.println("철수가 이겼습니다.");
			else if(b.equals(R))
				System.out.println("영희가 이겼습니다.");
			else
				System.out.println("비겼습니다.");
			
		}
		else if(a.equals(P)) {
			if(b.equals(S))
			System.out.println("영희가 이겼습니다.");
			else if(b.equals(R))
			System.out.println("철수가 이겼습니다.");
			else
				System.out.println("비겼습니다.");
		}
		scanner.close();
			
	}
}