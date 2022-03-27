import java.util.Scanner;

public class CircleA{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("원의 중심과 반지름 입력 >> ");
		double middlex = scanner.nextDouble();
		double middley = scanner.nextDouble();
		double radius = scanner.nextDouble();
		
		System.out.println("점 입력 >> ");
		double x = scanner.nextDouble();
		double y = scanner.nextDouble();
		
		if(x-middlex<=radius && y-middley<=radius)
			System.out.println("점 (" + x + "," + y + ") 는 원 안에 있다.");
		else
			System.out.println("점 (" +x + "," + y + ") 는 원 바깥에 있다.");
		
		scanner.close();
		
	}
}