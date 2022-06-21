import java.util.Scanner;

class Player{
	  String name;
	 
	public Player(String user) {
		this.name = user;
	}
	 String getWordFromUser(Scanner scanner) {

		 String text = scanner.nextLine();
		 return text;
	}
	 boolean checkSuccess(String data, String first) {
			int lastIndex =first.length()-1;
			char lastChar = first.charAt(lastIndex);
			char firstChar = data.charAt(0);
			if(lastChar == firstChar)
				return true;
			else
				return false;
	}
}

public class WorldGameApp{
	
	public WorldGameApp() {
		
	}
	public void run() {
		Scanner scanner = new Scanner(System.in);
		String user;
		String data;
		String first = "아버지";
		int count=0;
		System.out.println("끝말잇기 게임을 시작합니다..");
		System.out.print("게임에 참가하는 인원은 몇명입니까>>");
		int n = scanner.nextInt();
		scanner.nextLine();
		Player [] p;
		p = new Player[n];
		for(int i=0;i<p.length;i++) {
			System.out.print("참가자의 이름을 입력하시오>>");
			user = scanner.nextLine();
			p[i]= new Player(user);
			p[i].name=user;
			}
			System.out.println("시작하는 단어는 아버지입니다.");
			while(true) {
				if(count==3)
					count=0;
				else {
			System.out.print(p[count].name + ">>");
			
			data = p[count].getWordFromUser(scanner);
			if(p[count].checkSuccess(data, first)==false) {
				System.out.println(p[count].name + " 이 졌습니다.");
				break;
			}
			
				first = data;
				count++;
				}
			}
			scanner.close();
	}
	
	public static void main(String[] args) {
		WorldGameApp app = new WorldGameApp();
		app.run();
		

	}
}