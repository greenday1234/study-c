import java.util.Scanner;
import java.util.Vector;

public class VectorCollectionRain {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Vector<Integer> v = new Vector<Integer>();
		
		while(true) {
			System.out.print("강수량 입력 (0 입력시 종료)>>");
			int num = 0;
			int n = scanner.nextInt();
			if(n == 0)
				break;
			v.add(n);
			Object []arr = v.toArray();
			for(int i=0;i<arr.length;i++) {
				System.out.print((int)arr[i] + " ");
				num += (int)arr[i];
			}
			System.out.println("\n현재 평균 " + num/arr.length);
		}
		scanner.close();
	}
}
