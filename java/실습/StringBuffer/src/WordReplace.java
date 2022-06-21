import java.util.*;

public class WordReplace{
	public static void main(String[] args) {
		System.out.print(">>");
		Scanner scanner = new Scanner(System.in);
		String text = scanner.nextLine();
		
		StringBuffer sb = new StringBuffer(text);
		while(true) {
		System.out.print("명령 : ");
		String cmd = scanner.nextLine(); //그만, love!LOVE
		if(cmd.equals("그만"))
		{
			System.out.println("종료합니다.");
			break;
		}
		String [] tokens = cmd.split("!");
		if(tokens.length != 2) {
			System.out.println("잘못된 명령입니다.");
		}
		else {
			if((tokens[0].length() == 0)|| (tokens[1].length() == 0)) {
				System.out.println("잘못된 명령입니다.");
				continue;
			}
			int index = sb.indexOf(tokens[0]);
			if(index == -1) {
				System.out.println("subsring not about");
				continue;
			}
			System.out.println(tokens[0] + " " + tokens[1]);
			sb.replace(index,index+tokens[0].length(),tokens[1]);
			System.out.println(sb.toString());
			}
		
		}
		scanner.close();
	}
}