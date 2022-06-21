import java.util.Scanner;
import java.util.Calendar;

class Player{
	private Scanner scanner = new Scanner(System.in);
	private String name;
	public Player(String name) {
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public int turn() {	//각 플레이어의 게임
		System.out.println(name + "시작 <Enter>키>>");
		String key = scanner.nextLine();
		Calendar c = Calendar.getInstance();
		int startSecond = c.get(Calendar.SECOND);
		System.out.println("현재 초 시간 = " + startSecond);
		
		System.out.println("10초 예상 후 <Enter>키>>");
		key = scanner.nextLine();
		c = Calendar.getInstance();
		int endSecond = c.get(Calendar.SECOND);
		if(endSecond < startSecond)
			endSecond += 60;
		scanner.close();
		return Math.abs(startSecond - endSecond);
	}
}

public class GuessSecondGame{
	
	public GuessSecondGame() {
		
	}
	
	public void run() {
		Player player[] = new Player[2];
		player[0] = new Player("철이");
		player[1] = new Player("순이");
		System.out.println("10초에 가까운 사람이 이기는 게임입니다.");
		int duration1 = player[0].turn();
		int duration2 = player[1].turn();
		System.out.println(player[0].getName() + "의 결과 " + duration1 + ".");
		System.out.println(player[1].getName() + "의 결과 " + duration2 + ".");
		System.out.println("승자는 ");
		if(Math.abs(10 - duration1) < Math.abs(10 - duration2)) {
			System.out.println(player[0].getName());
		}
		else
			System.out.println(player[1].getName());
		
	}
	public static void main(String[] args) {
		GuessSecondGame game = new GuessSecondGame();
		game.run();
	}
}