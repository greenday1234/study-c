import java.util.Scanner;
import java.util.Random;

public class RandomIntArray{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Random r = new Random();
		
		System.out.print("정수 몇개?");
		int n = scanner.nextInt();
		int count =0;
		int test;
		int intArray[] = new int[n];
		
		for(int i=0;i<n;i++) {
			test = r.nextInt(100);
			intArray[i]=test;
			for(int j=0;j<i;j++) {
			if(intArray[j]==intArray[i])
				i--;
			}
		}
		count =0;
		while(true) {
			if(count%10==0 && count!=0) {
				System.out.println();
			}
			if(count==n)
				break;
			System.out.print(intArray[count] + " ");
			count++;
		
		}
		scanner.close();
	}
}