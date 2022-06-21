import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class BufferedIOEx {
	public static void main(String[] args) {
		BufferedReader fr = null;
		File f = new File("C:\\temp\\test.txt");
		try {
			fr = new BufferedReader(new FileReader(f));
			System.out.println(f.getPath() + "를 출력합니다");
			while(true) {
				String line = fr.readLine();
				
				if(line == null)
					break;
				System.out.print(line + "\n");
			}
			fr.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
