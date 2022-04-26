import java.util.Scanner;
import java.lang.Math;

class Player {
	private Scanner scanner = new Scanner(System.in);
	private String name;
	public Player(String name) {
		this.name = name;
	}
	String getName() {
		return name;
	}
	public boolean turn() {
		System.out.println("[" + name + "] : <Enter>");
		scanner.nextLine();
		int num[] = new int[3];
		for(int i=0;i<num.length;i++) {
			num[i] = (int)(Math.random()*3+1);
		}
		System.out.print("\t\t");
		for(int i=0;i<num.length;i++) {
			System.out.print(num[i] + "\t");
		}
		boolean result = true;
		for(int i=0;i<num.length;i++) {
			if(num[i] != num[0]) {
				result = false;
				break;
			}
		}
		return result;
	}
}
public class gambling{
	Scanner scanner = new Scanner(System.in);
	private Player [] p;
	
	public gambling() {
		System.out.println("�׺� ���ӿ� ���� �� ��������");
		
		int nPlayers = scanner.nextInt();
		scanner.nextLine();
		p = new Player[nPlayers];
		
		for(int i=0;i<p.length;i++) {
			System.out.print(i+1 + "��° ���� �̸�>>");
			p[i] = new Player(scanner.nextLine());
		}
	}
	void run() {
		int i=0;
		while(true) {
			if(p[i].turn()) {
				System.out.println(p[i].getName() + "���� �̰���ϴ�.");
				break;
			}
			else {
				System.out.println("�ƽ�����!");
				i++;
				i=i%p.length;
			}
		}
	}
	public static void main(String[] args) {
		gambling game = new gambling();
		game.run();
	}
}