import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

public class CampareFiles {
   public CampareFiles() {
      FileInputStream fin = null;
      FileInputStream fin1 = null;
      File f1;
      File f2;
      Scanner sc = new Scanner(System.in);

    	  System.out.println("��ü ��θ��� �ƴ� ���� �̸��� �Է��ϴ� ���, ������ ������Ʈ ������ �־�� �մϴ�.");
         try {
            System.out.print("ù��° ������ �Է��Ͻÿ�>>");
            String str1 = sc.nextLine();
            f1 = new File(str1);
            fin = new FileInputStream(f1);
            System.out.print("�ι�° ������ �Է��Ͻÿ�>>");
            String str2 = sc.nextLine();

            f2 = new File(str2);
            fin1 = new FileInputStream(f2);
            System.out.println(f1.getPath() + "�� " + f2.getPath() + "�� ���մϴ�.");
            int c;
            int r;
            int count = 0;
            while (true) {
               c = fin.read();
               r = fin1.read();
               if(c==-1||r==-1)
               {   
                  if(c!=r)
                  {
                     count++;
                     System.out.println("������ �ٸ��ϴ�");
                     break;
                  }
                  break;
               }
               if ((char) c == (char) r && (c == r)) {
                  continue;
               } else {
                  count++;
                  System.out.println("������ �ٸ��ϴ�");
                  break;
               }
            }
            
            if (count == 0)
               System.out.println("������ �����ϴ�.");

            fin.close();
            fin1.close();
         } catch (IOException e) {
            System.out.println("������ ���� ���� �ʽ��ϴ�.");
         }
      
      sc.close();
   }
   
   public static void main(String[] args) {
        
         new CampareFiles();
      }
}