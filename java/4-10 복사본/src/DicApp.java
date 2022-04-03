import java.util.Scanner;

class Dictionary{
	private static String [] kor = {"사랑", "아기", "돈", "미래", "희망"};
	private static String [] eng = {"love", "baby" , "money", "futrue", "hope"};
	public static String kor2Eng(String word) {
		for(int i=0;i<eng.length;i++) {
			if(kor[i].equals(word)) {
				return eng[i];
			}
		}
		return null;
	}
}
public class DicApp{
	Scanner scanner = new Scanner(System.in);
	public DicApp() {
	}
	void run() {
		System.out.println("한영 단어 검색 프로그램입니다.");
		while(true) {
		System.out.print("한글 단어?");
		String word = scanner.nextLine();
		if(word.equals("그만"))
			break;
		if(!Dictionary.kor2Eng(word).equals(null)) {
			System.out.println(word + "는 " + Dictionary.kor2Eng(word));
		}
		else
		System.out.println(word + "는 저의 사전에 없습니다.");
		}
	}
	public static void main(String[] args) {
		DicApp app = new DicApp();
		app.run();
	}
}