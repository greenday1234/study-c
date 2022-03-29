import java.util.Scanner;

public class ArrayLength{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("5개의 정수를 입력하세요>>>");
		
		int intArray[] = new int[5];
		
		int sum=0;
		
		for(int i=0;i<intArray.length;i++) {
			intArray[i]=scanner.nextInt();
			sum += intArray[i];
		}
		
		System.out.print("평균은 " + (double)sum/intArray.length + "입니다.");
		scanner.close();
	}
}