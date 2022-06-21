import java.util.*;

public class Spin{
	public static void main(String[] args) {
		System.out.println("문자열을 입력하세요. 빈 칸이나 있어도 되고 영어 한글 모두 됩니다.");
		Scanner scanner = new Scanner(System.in);
		String s = scanner.nextLine();
		int len = s.length();
		
		for(int i=0;i<len;i++) {
			String first = s.substring(0, 1);	//first = i
			String last = s.substring(1);	//last = love you
			s = last + first;
			System.out.println(s);
		}
		scanner.close();
	}
}