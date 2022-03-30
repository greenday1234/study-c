import java.util.Scanner;
import java.util.Random;

public class RandomGame{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Random r = new Random();
		int k = r.nextInt(100);
		int n;
		int min=0;
		int max=99;
		int count=1;
		String text;
		
		System.out.println("수를 결정하였습니다. 맞춰보세요.");
		while(true) {
		
			System.out.println(min + "~" + max);
			System.out.print(count+">>");
			n=scanner.nextInt();
			count++;
			if(n==k) {
				System.out.println("맞았습니다.");
				System.out.print("다시하시겠습니까?(y/n)>>");
				text = scanner.next();
				if(text.equals("y")) 
					continue;
				else
					break;
					
			}
			else if(n>k) {
				System.out.println("더 낮게");
				max = n;
			}
			else if(n<k) {
				System.out.println("더 높게");
				min = n;
			}
			else {
				System.out.println("범위를 벗어났습니다.");
				count--;
			}
		}
		scanner.close();
		
	}
}