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
		//scanner�� ���� ���� ������ �о ���Ϳ� ����
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
		// 1. ��� ���ϸ� �Է� �ޱ����� ȭ�� ��� System.out..
		System.out.print("��� ���ϸ� �Է�>>");
		// 2. Scanner Ŭ���� ���� �� ����� �Է� �б�
		String fileName = scanner.nextLine();
		// 3. �ٴ����� �о Vector�� ����
		//    readFile() �Լ��� ����
		readFile(fileName);
		// 4. while(true) ���ѷ��� ���鼭 �˻� �ܾ� �Է¹ޱ�
		while(true) {
			System.out.println("�˻��� �ܾ ����>>");
			String line = scanner.nextLine();
			// 5. "�׸�"�̸� break
			if(line.equals("�׸�"))
				break;
			// 6. �˻� �ܾ ���Ϳ��� �˻�
			//	  �˻� ���ι�ȣ 
			Vector<Integer> noVector = SearchWord(line);
			// 7. ���
			printLine(noVector);
		}
		scanner.close();
		System.out.println("�˻� ���α׷� ����");
	}
	public static void main(String[] args) {
		WordSearchFile ws = new WordSearchFile();
		ws.run();
	}
}
