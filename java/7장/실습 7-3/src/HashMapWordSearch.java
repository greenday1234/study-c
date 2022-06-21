import java.util.HashMap;
import java.util.Scanner;

public class HashMapWordSearch {
	public static void main(String[] args) {
		HashMap<String, Integer> h = new HashMap<String, Integer>();
		Scanner scanner = new Scanner(System.in);
	
		System.out.print("나라 이름과 인구를 입력하세요.(예: korea 5000)");
		while(true) {
			System.out.print("나라 이름, 인구 >> ");
			String contry = scanner.next();
			if(contry.equals("그만"))
				break;
			int nation = scanner.nextInt();
			h.put(contry, nation);
		}
		while(true) {
			System.out.print("인구 검색 >> ");
			String contry = scanner.next();
			if(contry.equals("그만")) {
				break;
			}
			else if(h.containsKey(contry)) {
				System.out.println(contry + "의 인구는 " + h.get(contry));
			}
			else {
				System.out.println(contry + "나라는 없습니다.");
			}
		}
		scanner.close();
	}
}
