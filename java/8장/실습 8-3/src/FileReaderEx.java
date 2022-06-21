import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class FileReaderEx {
	public static void main(String[] args) {
		File f = new File("text.txt");
		
		try {
			FileReader fr = new FileReader(f);
			int c;
			while((c = fr.read()) != -1) {
				c = Character.toUpperCase(c);
				System.out.print((char)c);
			}
			fr.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
