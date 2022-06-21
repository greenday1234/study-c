import java.util.Scanner;

class Circle{
	double x;
	double y;
	int radius;
	public Circle(double x, double y, int radius) {
		this.x = x;
		this.y = y;
		this.radius = radius;
	}
}
public class CircleManager{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Circle [] c = new Circle[3];
		for(int i=0;i<c.length;i++) {
			System.out.print("x, y, radius >>");
			double x = scanner.nextDouble();
			double y = scanner.nextDouble();
			int radius = scanner.nextInt();
			c[i]=new Circle(x,y,radius);
		}
		
		if(c[0].radius>c[1].radius&&c[0].radius>c[2].radius)
			System.out.print("가장 면적이 큰 원은 (" + c[0].x + "," + c[0].y + ")" + c[0].radius);
		else if(c[1].radius>c[0].radius && c[1].radius > c[2].radius)
			System.out.print("가장 면적이 큰 원은 (" + c[1].x + "," + c[1].y + ")" + c[1].radius);
		else
			System.out.print("가장 면적이 큰 원은 (" + c[2].x + "," + c[2].y + ")" + c[2].radius);
		
		scanner.close();


		
		
	}
}