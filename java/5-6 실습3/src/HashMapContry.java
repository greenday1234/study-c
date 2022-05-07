import java.util.HashMap;
import java.util.Scanner;

public class HashMapContry {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		HashMap<String, String> map = new HashMap<String, String>();
		System.out.println("나라 이름과 인구를 입력하세요.(예 : Korea 5000)");
		while(true) {
			System.out.print("나라 이름, 인구>>");
			String contry = scanner.next();
			if(contry.equals("그만"))
				break;
			String people = scanner.next();
			map.put(contry, people);
		}
		while(true) {
			System.out.print("인구 검색>>");
			String peo = scanner.next();
			if(peo.equals("그만")) {
				break;
			}
			else if(map.get(peo) == null) {
				System.out.println(peo + " 나라는 없습니다.");
				continue;
			}
			System.out.println(peo + "의 인구는 " + map.get(peo));
		}
		scanner.close();
	}
}
