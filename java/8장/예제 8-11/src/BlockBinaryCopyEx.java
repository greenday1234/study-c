import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class BlockBinaryCopyEx {
	public static void main(String[] args) {
		File src = new File("test.png");
		File dest = new File("copy.png");
		try {
			FileInputStream fi = new FileInputStream(src);
			FileOutputStream fo = new FileOutputStream(dest);
			byte [] buf = new byte[1024*10];
			while(true) {
				int n = fi.read(buf);	//버퍼만큼의 데이터를 읽어서 변수에 넣는다.(n은 파일의 크기가 몇 바이트인지)
				fo.write(buf, 0, n);	//읽은 데이터를 쓴다.(0부터 n까지)
				if(n<buf.length)	//버퍼 크기보다 작게 읽으면 종료(오류문)
					break;
			}
			fi.close();
			fo.close();
			System.out.println(src.getPath() + "를 " + dest.getPath() + "로 복사했습니다.");
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
