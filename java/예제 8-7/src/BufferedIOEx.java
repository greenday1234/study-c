import java.io.BufferedOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class BufferedIOEx {
	public static void main(String[] args) {
		FileReader fin = null;
		int c;
		try {
			fin = new FileReader("text.txt");
			BufferedOutputStream out = new BufferedOutputStream(System.out, 5);
			while((c = fin.read()) != -1) {
				out.write(c);	//버퍼스트림엔 System.out 출력 스트림이 있기 떄문에 출력됨
			}
			new Scanner(System.in).nextLine();	//이게 없으면 전부 출력됨
			out.flush();
			fin.close();
			out.close();
		}catch(IOException e){
			e.printStackTrace();
		}
	}
}
