import java.io.File;

public class FileEx {
	public static void listDirectory(File dir) {
		System.out.println("-----" + dir.getPath() + "�� ���� ����Ʈ �Դϴ�.------");
		
		File[] subFiles = dir.listFiles();
		
		for(int i=0;i<subFiles.length;i++) {
			File f = subFiles[i];
			long t = f.lastModified();
			System.out.println(f.getName());
			System.out.println("\t���� ũ��: " + f.length());
			System.out.printf("\t������ �ð�: %tb %td %ta %tT\n", t, t, t, t);
		}
	}
	
	public static void main(String[] args) {
		
	}
}
