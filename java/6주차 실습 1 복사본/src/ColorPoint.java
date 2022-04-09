class Point{
	private int x,y;
	public Point(int x,int y) {
		this.x = x;
		this.y = y;
	}
	public int getx() {
		return x;
	}
	public int gety() {
		return y;
	}
	protected void move(int x, int y)
	{
		this.x = x;
		this.y = y;
	}
}

public class ColorPoint extends Point {
	String color;
	
	public ColorPoint() {
		this (0,0);
	}
	public ColorPoint(int x, int y) {
		super(x,y);
		color = "BLACK";
	}
	
	public void setXY(int x, int y) {
		move(x,y);
	}
	public void setColor(String color) {
		this.color = color;
	}
	public String toString() {
		return color + "색의 (" + getx() + "," + gety() + ") 의 점";
	}
	public static void main(String[] args) {
		ColorPoint zeropoint = new ColorPoint();
		
		System.out.println(zeropoint.toString() + "입니다.");
		ColorPoint cp = new ColorPoint(10,10);
		cp.setXY(5, 5);
		cp.setColor("RED");
		System.out.println(cp.toString() + "입니다.");

	}
	
}


