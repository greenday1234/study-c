import java.util.Scanner;
import java.util.Vector;

public class VectorBig {
	
	public static void PrintBig(Vector<Integer> v) {
		int big = v.get(0);
		for(int i=0;i<v.size();i++) {
			if(big < v.get(i)) {
				big = v.get(i);
			}
		}
		System.out.println("가장 큰 정수는 " + big);
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("정수(-1이 입력될 때 까지)>>");
		Vector<Integer> v = new Vector<Integer>();
		while(true) {
		int n = scanner.nextInt();
		if(n == -1) {
			break;
		}
		v.add(n);
		}
		if(v.isEmpty()) {
			System.out.println("정수가 아무것도 없습니다.");
			scanner.close();
			return;
		}
			PrintBig(v);
			scanner.close();
	}
}
