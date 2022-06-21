import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Vector;

public class WordSearchFile {
	
	private File targetFile = null;
	Vector<String> lineVector = new Vector<String>();
	public WordSearchFile() {
		
	}
	private void readFile(String fileName) {
		//scanner를 통해 라인 단위로 읽어서 벡터에 저장
		targetFile = new File(fileName);
		
		try {
			Scanner fScanner = new Scanner(new FileReader(targetFile));
			while(fScanner.hasNext()) {
				String line = fScanner.nextLine();
				lineVector.add(line);
			}
			fScanner.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
	private Vector<Integer> SearchWord(String word) {
		Vector<Integer> noVector = new Vector<Integer>();
		for(int i=0;i<lineVector.size();i++) {
			String line = lineVector.get(i);
			if(line.indexOf(word)!= -1) {
				noVector.add(i);
			}
		}
		return noVector;
	}
	private void printLine(Vector<Integer> noVector) {
		for(int i=0;i<noVector.size();i++) {
			int lineNo = noVector.get(i);
			String line = lineVector.get(lineNo);
			System.out.println(lineNo + " " + line);
		}
	}
	public void run() {
		Scanner scanner = new Scanner(System.in);
		// 1. 대상 파일명 입력 받기위한 화면 출력 System.out..
		System.out.print("대상 파일명 입력>>");
		// 2. Scanner 클래스 생성 후 사용자 입력 읽기
		String fileName = scanner.nextLine();
		// 3. 줄단위로 읽어서 Vector에 저장
		//    readFile() 함수로 구현
		readFile(fileName);
		// 4. while(true) 무한루프 돌면서 검색 단어 입력받기
		while(true) {
			System.out.println("검색할 단어나 문장>>");
			String line = scanner.nextLine();
			// 5. "그만"이면 break
			if(line.equals("그만"))
				break;
			// 6. 검색 단어를 벡터에서 검색
			//	  검색 라인번호 
			Vector<Integer> noVector = SearchWord(line);
			// 7. 출력
			printLine(noVector);
		}
		scanner.close();
		System.out.println("검색 프로그램 종료");
	}
	public static void main(String[] args) {
		WordSearchFile ws = new WordSearchFile();
		ws.run();
	}
}
