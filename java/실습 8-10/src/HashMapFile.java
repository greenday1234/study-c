import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class HashMapFile {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		HashMap<String, String> h = new HashMap<String, String>();
		File f = new File("text.txt");
		int count = 0;
		try {
		FileReader fr = new FileReader(f);
		Scanner scanner = new Scanner(fr);
		while(scanner.hasNext()) {
			String name = scanner.next();
			String tel = scanner.next();
			h.put(name, tel);
			count++;
			}
		fr.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
		System.out.println("총 " + count + "개의 전화번호를 읽었습니다.");
		while(true) {
			System.out.print("이름>>");
			String name = s.nextLine();
			if(name.equals("그만"))
				break;
			if(h.containsKey(name)) {
			System.out.println(h.get(name));
			}
			else {
				System.out.println("찾는 이름이 없습니다.");
			}
		}
		s.close();
	}
}
