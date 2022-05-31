import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class TextFileEx {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("전체 경로명이 아닌 파일 이름만 입력하는 경우, 파일은 프로젝트 폴더에 있어야 합니다.");
		System.out.print("첫번째 파일 이름을 입력하세요>>");
		String file1 = scanner.nextLine();
		System.out.print("두번쨰 파일 이름을 입력하세요>>");
		String file2 = scanner.nextLine();
		
		try {
		FileReader fr1 = new FileReader(file1);
		FileReader fr2 = new FileReader(file2);
		FileWriter fw = new FileWriter("text3.txt");
		int c;
		while((c = fr1.read()) != -1) {
			fw.write((char)c);
		}
		fw.write(" ");
		while((c = fr2.read()) != -1) {
			fw.write((char)c);
		}
		System.out.println("프로젝트 폴더 밑에 text3.txt 파일에 저장하였습니다.");
		fr1.close();
		fr2.close();
		fw.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
