import java.util.Scanner;

public class ThreeDrainage{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int intArray[] = new int[10];
		int s = 0;
		System.out.print("양의 정수 10개를 입력하시오>>");
		for(int i=0;i<10;i++) {
		int n = scanner.nextInt();
		if(n%3==0) {
			intArray[s]=n;
			s++;
			}
		}
		for(int i=0;i<intArray.length;i++) {
			if(intArray[i]!=0)
			System.out.print(intArray[i] + " ");
			
		}
		scanner.close();
	}
}