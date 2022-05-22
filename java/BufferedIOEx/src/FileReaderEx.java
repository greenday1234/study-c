import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class FileReaderEx {
	public static void main(String[] args) {
		File f= new File("C:\\temp\\test.txt");
		FileReader fin = null;
		int c;
		try {
			System.out.println(f.getPath() + "를 출력합니다.");
		fin = new FileReader(f);
		while((c = fin.read()) != -1) {
			System.out.print((char)c);
		}
		fin.close();
		}catch(IOException e) {
			System.out.println("입출력 오류");
		}
	}
}
