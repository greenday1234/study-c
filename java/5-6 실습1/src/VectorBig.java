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
		System.out.println("���� ū ������ " + big);
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("����(-1�� �Էµ� �� ����)>>");
		Vector<Integer> v = new Vector<Integer>();
		while(true) {
		int n = scanner.nextInt();
		if(n == -1) {
			break;
		}
		v.add(n);
		}
		if(v.isEmpty()) {
			System.out.println("������ �ƹ��͵� �����ϴ�.");
			scanner.close();
			return;
		}
			PrintBig(v);
			scanner.close();
	}
}
