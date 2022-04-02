import java.util.Scanner;

class RectApp{
	int width;
	int height;
	public int getArea() {
		return width*height;
	}
}
public class Ractangle{
	public static void main(String[] args) {
		RectApp rect = new RectApp();
		Scanner scanner = new Scanner(System.in);
		System.out.print(">> ");
		rect.width = scanner.nextInt();
		rect.height = scanner.nextInt();
		System.out.println("사각형의 면적은 " + rect.getArea());
		scanner.close();
	}
}