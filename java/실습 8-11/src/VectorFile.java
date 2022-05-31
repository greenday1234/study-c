import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Vector;

public class VectorFile {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		Vector<String> v = new Vector<String>();
		System.out.println("프로젝트 폴더 밑의 text.txt 파일을 읽었습니다.");
		File f = new File("text.txt");
		
		try {
			FileReader fr = new FileReader(f);
			
			Scanner scanner = new Scanner(fr);
			while(scanner.hasNext()) {
				String str = scanner.nextLine();
				
				v.add(str);
			}
			fr.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
		
		while(true) {
			int count = 0;
			System.out.print("단어>>");
			String searchWord = s.nextLine(); // 검색할 단어 입력
			if(searchWord.equals("그만")) {
				System.out.println("종료합니다...");
				break;
				}
		for(int i=0; i<v.size(); i++) {
			String word = v.get(i); // 벡터 내의 문자열
			if(word.length() < searchWord.length()) // 벡터의 문자열이 검색 문자열보다 짧은 경우 
				continue;	
			// 벡터문자열의 앞부분을 검색 문자열 크기만큼 잘라내기
			String frontPart = word.substring(0, searchWord.length());
			
			if(searchWord.equals(frontPart)) { // 검색 문자열과 잘라낸 앞 부분 비교
				System.out.println(word); // 벡터에서 발견한 단어 출력
				count++;
					}
				}
		if(count == 0) {
			System.out.println("발견할 수 없음");
			}
		}
	}
}
