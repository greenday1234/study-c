class Point{
	protected int x;
	protected int y;
	protected int z;
	
	public Point(int x, int y, int z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getZ() {
		return z;
	}
}


public class Point3D extends Point{
	
	public Point3D(int x, int y, int z) {
		super(x,y,z);
	}
	public void move(int x, int y) {
		this.x=x;
		this.y=y;
	}
	public void moveUp() {
		z++;
	}
	public void moveDown() {
		z--;
	}
	
	public void move(int x, int y, int z) {
		this.x=x;
		this.y=y;
		this.z=z;
	}
	public String toString() {
		return "(" + getX() + "," + getY() + "," + getZ() + ")의 점";
	}
public static void main(String[] args) {
		Point3D p = new Point3D(1,2,3);
		System.out.println(p.toString() + "입니다.");
		
		p.moveUp();
		System.out.println(p.toString() + "입니다.");
		p.moveDown();
		p.move(10,10);
		System.out.println(p.toString() + "입니다.");
		
		p.move(100,200,300);
		System.out.println(p.toString() + "입니다.");
	}
}