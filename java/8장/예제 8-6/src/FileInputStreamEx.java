import java.io.FileInputStream;
import java.io.IOException;

public class FileInputStreamEx {
	public static void main(String[] args) {
		byte b[] = new byte[6];
		
		try {
			FileInputStream fin = new FileInputStream("text.out");
			
			fin.read(b);
			
			System.out.println("text.out에서 읽은 배열을 출력합니다.");
			for(int i=0;i<b.length; i++) {
				System.out.print(b[i] + " ");
			}
			System.out.println();
			fin.close();
		}catch(IOException e) {
			System.out.println("입출력 오류");
		}
	}
}
