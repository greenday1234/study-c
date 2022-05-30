import java.util.Iterator;
import java.util.Scanner;
import java.util.Vector;

abstract class Shape {
	
	public abstract void draw();
}
class Line extends Shape {
	public void draw() {
		System.out.println("Line");
	}
}
class Rect extends Shape {
	public void draw() {
		System.out.println("Rect");
	}
}
class Circle extends Shape {
	public void draw() {
		System.out.println("Circle");
	}
}

public class GraphicVector {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Vector<Shape> v = new Vector<Shape>();
		Shape shape;
		System.out.println("그래픽 에디터 beauty을 실행합니다.");
		while(true) {
			System.out.print("삽입(1), 삭제(2), 모두 보기(3), 종료(4)>>");
			int n = scanner.nextInt();
			if(n == 1) {
				System.out.print("Line(1), Rect(2), Circle(3)>>");
				int num = scanner.nextInt();
				if(num == 1) {
					shape = new Line();
					v.add(shape);
				}
				else if(num == 2) {
					shape = new Rect();
					v.add(shape);
				}
				else {
					shape = new Circle();
					v.add(shape);
				}
			}
			else if(n == 2) {
				System.out.print("삭제할 도형의 위치>>");
				int point = scanner.nextInt();
				if(v.elementAt(point) != null)
				v.remove(point);
				else
					System.out.println("삭제할 수 없습니다.");
			}
			else if(n == 3) {
				Iterator<Shape> it = v.iterator();
				while(it.hasNext()) {
					Shape sh = it.next();
					sh.draw();
				}
			}
			else if(n == 4) {
				System.out.println("beauty를 종료합니다.");
				break;
			}
			else {
				System.out.println("잘못 입력하셨습니다.");
			}
		}
		scanner.close();
	}
}
