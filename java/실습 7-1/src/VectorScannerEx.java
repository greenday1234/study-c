import java.util.Collections;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Vector;

public class VectorScannerEx {
	public static void main(String[] args) {
		Vector<Integer> v = new Vector<Integer>();
		System.out.print("정수(-1이 입력될 떄 까지)>>");
		Scanner scanner = new Scanner(System.in);
	
		while(true) {
		int n = scanner.nextInt();
		if(n == -1) {
			break;
		}
		v.add(n);
		}
		
		int max = Collections.max(v);
		System.out.println("가장 큰 수는 " + max);
		
		scanner.close();
	}
}
