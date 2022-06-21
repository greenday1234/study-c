class Point{
	private int x,y;
	
	public Point(int x, int y) {
		this.x = x;
		this.y= y;
	}
	public String toString() {
		return "Point(" + x + "," + y + ")";
	}
}

public class ToStringEx {
	public static void main(String[] args) {
		Point p = new Point(2,3);
		System.out.println(p.toString());
		System.out.println(p);	//객체가 toString으로 자동 변환됨.
		System.out.println(p + "입니다.");
	}
}
