import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileWriterEx {
	public static void main(String[] args) {
		System.out.println("전화번호 입력 프로그램입니다.");
		Scanner scanner = new Scanner(System.in);

		File f = new File("phone.txt");
		try {
		FileWriter fw = new FileWriter(f);
		while(true) {
			System.out.print("이름 전화번호 >> ");
			String str = scanner.nextLine();
			if(str.equals("그만")) {
				System.out.println(f.getPath() + "에 저장하였습니다.");
				fw.close();
				break;
				}
			fw.write(str);
			fw.write("\r\n");
			}
		}catch(IOException e) {
			e.printStackTrace();
		}
		scanner.close();
	}
}
