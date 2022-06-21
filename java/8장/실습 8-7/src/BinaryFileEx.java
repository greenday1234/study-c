import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class BinaryFileEx {
	public static void main(String[] args) {
		File f1 = new File("test.png");
		File f2 = new File("test1.png");
		try {
		FileInputStream fi = new FileInputStream(f1);
		FileOutputStream fo = new FileOutputStream(f2);
		
		System.out.println("text.png를 text1.png로 복사합니다.");
		System.out.println("10%마다 *를 출력합니다.");
		
		long l1 = f1.length() / 10;
		int c, count = 0;
		while((c = fi.read()) != -1) {
			fo.write((byte) c);
			count++;
			if(count == l1) {
				System.out.print("*");
				count = 0;
			}
		}
		fi.close();
		fo.close();
		
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
