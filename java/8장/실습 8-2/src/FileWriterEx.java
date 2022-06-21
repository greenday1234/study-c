import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class FileWriterEx {
	public static void main(String[] args) {
		File f = new File("phone.txt");
		
		try {
			FileReader fr = new FileReader(f);
			int c;
			while((c = fr.read())!= -1) {
				System.out.print((char)c);
			}
			fr.close();
		}catch(IOException e){
			e.printStackTrace();
		}
	}
}
