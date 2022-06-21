import java.util.HashMap;
import java.util.Scanner;

class Country{
	private String country;
	private String nation;
	public Country(String country, String nation){
		this.country = country;
		this.nation = nation;
	}
	
	public String getcountry() {
		return country;
	}
	public String getnation() {
		return nation;
	}
}

public class CountryManager {
	
	public static void main(String[] args) {
		HashMap<String, Country> h = new HashMap<String, Country>();
		Scanner scanner = new Scanner(System.in);
		
		while(true) {
			int count = 0;
			int tmp = 0;
			System.out.print("1. 입력, 2.검색, 3.종료>>");
			int n = scanner.nextInt();
			if(n == 1) {
				System.out.print("국가와 수도를 입력하시오.>>");
				String con = scanner.next();
				String na = scanner.next();
				for(int i=0;i<h.size();i++) {
					if(h.containsKey(con)) {
						count++;
					}
				}
				if(count == 0) {
					h.put(con, new Country(con, na));
					System.out.println("[등록완료]");
				}
				else {
					System.out.println("[중복국가]");
				}
			}
			else if(n == 2) {
				System.out.print("국가명을 입력하시오.>>");
				scanner.nextLine();
				String searchcon = scanner.nextLine();
				for(int i=0;i<h.size();i++) {
					if(h.containsKey(searchcon)) {
					tmp++;
					break;
				}
			}
				if(tmp == 1) {
				Country c = h.get(searchcon);
						System.out.println(c.getcountry() + " 수도는 " + c.getnation() + "입니다.");
				}
				else {
				System.out.println("[자료없음]");
				}
			}
			else if(n == 3) {
				System.out.println("[종료]");
				break;
			}
			else {
					System.out.println("잘못 입력하셨습니다.");
			}
		}
	}
	
}
