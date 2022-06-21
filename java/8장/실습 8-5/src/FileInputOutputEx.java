import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class FileInputOutputEx {
	public static void main(String[] args) {
		System.out.println("전체 경로명이 아닌 파일 이름만 입력하는 경우, 파일은 프로젝트 폴더에 있어야 합니다.");
		Scanner scanner = new Scanner(System.in);
		System.out.print("첫번째 파일 이름을 입력하세요>>");
		String file1 = scanner.nextLine();
		System.out.print("두번쨰 파일 이름을 입력하세요>>");
		String file2 = scanner.nextLine();
		System.out.println(file1 + "와 " + file2 + "를 비교합니다.");
		int count = 0;
	try {
		FileInputStream f1 = new FileInputStream(file1);
		FileInputStream f2 = new FileInputStream(file2);
		
			Scanner scanner1 = new Scanner(f1);
			Scanner scanner2 = new Scanner(f2);
			while(scanner1.hasNext() && scanner2.hasNext()) {
				String line1 = scanner1.nextLine();
				String line2 = scanner2.nextLine();
				if(!line1.equals(line2)) {
					count++;
				}
			}
			if(count != 0) {
				System.out.println("파일이 같지 않습니다.");
			}
			else {
				System.out.println("파일이 같습니다.");
			}
		
		f1.close();
		f2.close();
	}catch(IOException e) {
		e.printStackTrace();
	}
		
	}
}
