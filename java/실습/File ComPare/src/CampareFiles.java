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

    	  System.out.println("전체 경로명이 아닌 파일 이름만 입력하는 경우, 파일은 프로젝트 폴더에 있어야 합니다.");
         try {
            System.out.print("첫번째 파일을 입력하시오>>");
            String str1 = sc.nextLine();
            f1 = new File(str1);
            fin = new FileInputStream(f1);
            System.out.print("두번째 파일을 입력하시오>>");
            String str2 = sc.nextLine();

            f2 = new File(str2);
            fin1 = new FileInputStream(f2);
            System.out.println(f1.getPath() + "와 " + f2.getPath() + "를 비교합니다.");
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
                     System.out.println("파일이 다릅니다");
                     break;
                  }
                  break;
               }
               if ((char) c == (char) r && (c == r)) {
                  continue;
               } else {
                  count++;
                  System.out.println("파일이 다릅니다");
                  break;
               }
            }
            
            if (count == 0)
               System.out.println("파일이 같습니다.");

            fin.close();
            fin1.close();
         } catch (IOException e) {
            System.out.println("파일이 존재 하지 않습니다.");
         }
      
      sc.close();
   }
   
   public static void main(String[] args) {
        
         new CampareFiles();
      }
}