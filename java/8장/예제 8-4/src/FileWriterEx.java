import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileWriterEx {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		FileWriter fout = null;
		try {
			fout = new FileWriter("text.txt");
			while(true) {
				String line = scanner.nextLine();
				if(line.length() == 0)
					break;
				fout.write(line);
				fout.write("\r\n");	//운영체제마다 줄바꿈 문자가 달라 둘 다 사용
			}
			fout.close();
		}catch(IOException e) {
			System.out.println("입출력 오류");
		}
		scanner.close();
	}
}
