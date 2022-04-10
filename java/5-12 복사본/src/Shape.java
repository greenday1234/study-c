import java.util.Scanner;

public abstract class Shape{
	private Shape next;
	public Shape() {
		next = null;
	}
	public void setNext(Shape obj) {
		next = obj;
	}
	public Shape getNext() {
		return next;
	}
	public abstract void draw();
}
class Line extends Shape{
	String name = "Line";
	public void draw() {
		System.out.print(name);
	}
}
class Rect extends Shape{
	
	public void draw() {
		
	}
}
class Circle extends Shape{
	
	public void draw() {
		
	}
}

class GraphicEditor{
	
	Shape start;
	Shape last;
	
	void insert(String str){
		
	}
	void delete(){
		
	}
	void show(){
		
	}
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		GraphicEditor ge = new GraphicEditor();
		System.out.println("그래픽 에디터 beauty을 실행합니다.");
		while(true) {
		System.out.print("삽입(1), 삭제(2), 모두 보기(3), 종료(4)>>");
		int n = scanner.nextInt();
		switch(n) {
		case 1:
			System.out.print("Line(1), Rect(2), Circle(3)>>");
			int c = scanner.nextInt();
			if(c==1) {
				
			}
			else if(c==2) {
				
			}
			else if(c==3) {
				
			}
			else {
				System.out.println("잘못 입력했습니다.");
			}
		case 2:
		case 3:
		case 4:
			System.out.println("beauty을 종료합니다.");
			break;
			default:
				System.out.println("잘못된 값을 입력했습니다. 다시 입력해 주세요");
			}
		}
	}
}