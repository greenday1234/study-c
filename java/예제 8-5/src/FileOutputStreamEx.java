import java.io.FileOutputStream;
import java.io.IOException;

public class FileOutputStreamEx {
	public static void main(String[] args) {
		byte b[] = {7,51,3,4,-1,24};
		
		try {
			FileOutputStream fout = new FileOutputStream("text.out");
			fout.write(b);
			fout.close();
		}catch(IOException e) {
			System.out.println("입출력 오류");
			return;
		}
		System.out.println("text.out을 저장하였습니다.");
	}
}
