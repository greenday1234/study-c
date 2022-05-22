import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileWriteEx {
	public static void main(String[] args) {
		FileWriter fout = null;
		File f = new File("C:\\temp\\test.txt");
		try {
		fout = new FileWriter(f);
		Scanner scanner = new Scanner(System.in);
		System.out.println("전화번호 입력 프로그램입니다.");
		while(true) {
			System.out.print("이름 전화번호>>");
			String tex = scanner.nextLine();
			if(tex.equals("그만"))
				break;
		fout.write(tex + "\r\n");
		}
		System.out.println(f.getPath() + "에 저장하였습니다.");
		fout.close();
		scanner.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
