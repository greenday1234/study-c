import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Vector;

public class VectorFileEx {
	
	private File targetFile = null;
	Vector<String> lineVector = new Vector<String>();
	
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
			if(line.indexOf(word)!= -1) {	//특정 문자나 문자열이 앞에서부터 처음 발견되는 인덱스 반환
				noVector.add(i);	//해당 문자가 있는 문자열의 번호 삽입
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
		System.out.print("대상 파일명 입력>>");
		String fileName = scanner.nextLine();
		readFile(fileName);
		while(true) {
			System.out.println("검색할 단어나 문장>>");
			String line = scanner.nextLine();
			if(line.equals("그만"))
				break;
			Vector<Integer> noVector = SearchWord(line);
			printLine(noVector);
		}
		scanner.close();
		System.out.println("검색 프로그램 종료");
	}
	
	public static void main(String[] args) {
		VectorFileEx ws = new VectorFileEx();
		ws.run();
	}
}
