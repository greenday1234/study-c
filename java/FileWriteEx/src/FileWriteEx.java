import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileWriteEx {
	public static void main(String[] args) {
		FileWriter fout = null;
		File f = new File("C:\\temp\\test.txt");
		try {
		fout = new FileWriter(f);
		Scanner scanner = new Scanner(System.in);
		System.out.println("��ȭ��ȣ �Է� ���α׷��Դϴ�.");
		while(true) {
			System.out.print("�̸� ��ȭ��ȣ>>");
			String tex = scanner.nextLine();
			if(tex.equals("�׸�"))
				break;
		fout.write(tex + "\r\n");
		}
		System.out.println(f.getPath() + "�� �����Ͽ����ϴ�.");
		fout.close();
		scanner.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
