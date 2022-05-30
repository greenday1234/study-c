import java.util.Iterator;
import java.util.Scanner;
import java.util.Vector;

class Nation{
	private String country;
	private String capital;
	
	public Nation(String country, String capital) {
		this.country = country;
		this.capital = capital;
	}
	public String getcountry() {
		return country;
	}
	public String getcapital() {
		return capital;
	}
}

public class CollectionEx {
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		System.out.println("수도 맞추기 게임을 시작합니다.");
		int num;
		while(true) {
			
			System.out.print("입력: 1, 퀴즈: 2, 종료: 3>>");
			int n = scanner.nextInt();
			if(n==1) {
				Vector<Nation> v = new Vector<Nation>();
				Iterator<Nation> it = v.iterator();
				num = 1;
			System.out.println("현재 " + v.size() + "개 나라와 수도가 입력되어 있습니다.");
			while(true) {
				
			System.out.print("나라와 수도 입력 " + (v.size()+num++) + ">>");
			String country = scanner.next();
			if(country.equals("그만"))
				break;
			String capital = scanner.next();
			while(it.hasNext()) {
				Nation na = it.next();
				if(na.getcountry().equals(country)) {
					System.out.println(country + "는 이미 있습니다.");
				}
				else {
					v.add(new Nation(country, capital));
						}
					}
				}
			}
			else if(n == 2) {
				
			}
			else if(n == 3) {
				System.out.println("프로그램을 종료합니다.");
				break;
			}
		}
	}
}
