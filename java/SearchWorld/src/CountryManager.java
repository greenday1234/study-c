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
			System.out.print("1. �Է�, 2.�˻�, 3.����>>");
			int n = scanner.nextInt();
			if(n == 1) {
				System.out.print("������ ������ �Է��Ͻÿ�.>>");
				String con = scanner.next();
				String na = scanner.next();
				for(int i=0;i<h.size();i++) {
					if(h.containsKey(con)) {
						count++;
					}
				}
				if(count == 0) {
					h.put(con, new Country(con, na));
					System.out.println("[��ϿϷ�]");
				}
				else {
					System.out.println("[�ߺ�����]");
				}
			}
			else if(n == 2) {
				System.out.print("�������� �Է��Ͻÿ�.>>");
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
						System.out.println(c.getcountry() + " ������ " + c.getnation() + "�Դϴ�.");
				}
				else {
				System.out.println("[�ڷ����]");
				}
			}
			else if(n == 3) {
				System.out.println("[����]");
				break;
			}
			else {
					System.out.println("�߸� �Է��ϼ̽��ϴ�.");
			}
		}
	}
	
}
