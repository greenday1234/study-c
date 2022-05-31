import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class FileReaderEx {
	public static void main(String[] args) {
		File f = new File("text.txt");
		int count = 1;
		try {
			FileReader fr = new FileReader(f);
			Scanner scanner = new Scanner(fr);	//FileReader를 스캐너와 연결
			while(scanner.hasNext()) {	//파일에 읽을 내용이 있는 동안
				String line = scanner.nextLine();	//파일에서 한 라인 읽기
				System.out.printf("%4d : ", count++);
				System.out.println(line);
			}
			fr.close();
			
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
