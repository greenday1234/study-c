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
	public int turn() {	//�� �÷��̾��� ����
		System.out.println(name + "���� <Enter>Ű>>");
		String key = scanner.nextLine();
		Calendar c = Calendar.getInstance();
		int startSecond = c.get(Calendar.SECOND);
		System.out.println("���� �� �ð� = " + startSecond);
		
		System.out.println("10�� ���� �� <Enter>Ű>>");
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
		player[0] = new Player("ö��");
		player[1] = new Player("����");
		System.out.println("10�ʿ� ����� ����� �̱�� �����Դϴ�.");
		int duration1 = player[0].turn();
		int duration2 = player[1].turn();
		System.out.println(player[0].getName() + "�� ��� " + duration1 + ".");
		System.out.println(player[1].getName() + "�� ��� " + duration2 + ".");
		System.out.println("���ڴ� ");
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