import java.util.HashMap;
import java.util.Scanner;

public class HashMapContry {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		HashMap<String, String> map = new HashMap<String, String>();
		System.out.println("���� �̸��� �α��� �Է��ϼ���.(�� : Korea 5000)");
		while(true) {
			System.out.print("���� �̸�, �α�>>");
			String contry = scanner.next();
			if(contry.equals("�׸�"))
				break;
			String people = scanner.next();
			map.put(contry, people);
		}
		while(true) {
			System.out.print("�α� �˻�>>");
			String peo = scanner.next();
			if(peo.equals("�׸�")) {
				break;
			}
			else if(map.get(peo) == null) {
				System.out.println(peo + " ����� �����ϴ�.");
				continue;
			}
			System.out.println(peo + "�� �α��� " + map.get(peo));
		}
		scanner.close();
	}
}
