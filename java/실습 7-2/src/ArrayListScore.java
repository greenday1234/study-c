import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class ArrayListScore {
	public static void main(String[] args) {
		ArrayList<Character> al = new ArrayList<Character>();
		System.out.print("6개의 학점을 빈 칸으로 분리 입력(A/B/C/D/F)>>");
		Scanner scanner = new Scanner(System.in); 
		for(int i=0;i<6;i++) {
			char str = scanner.next().charAt(0);
			al.add(str);
		}
		Iterator<Character> it = al.iterator();
		double num = 0;
		while(it.hasNext()) {
			switch(it.next()) {
			case 'A':
				num += 4.0;
				break;
			case 'B':
				num += 3.0;
				break;
			case 'C':
				num += 2.0;
				break;
			case 'D':
				num += 1.0;
				break;
			case 'F':
				num += 0;
				break;
				default:
					System.out.println("잘못 입력했습니다.");
					break;
			}
		}
		System.out.println(num/6);
		scanner.close();
	}
}
