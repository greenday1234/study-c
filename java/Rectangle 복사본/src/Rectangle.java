public class Rectangle {
	int x, y, width, height;
	
	private Rectangle(int x, int y, int width, int height) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}
	private void show() {
		System.out.println("(" + x + "," + y + ") 에서 크기가 " + width + "x" + height + "인 사각형");
	}
	private int square() {
		int area;
		area = width*height;
		return area;
	}
	private boolean contains(Rectangle r) {
		if(r.x>=x && r.y>=y && (r.x+r.width <= width && r.y+r.height <= height)) {
			return true;
		}
		else
			return false;
	}
	
	public static void main(String[] args) {
		Rectangle r = new Rectangle(2,2,8,7);
		Rectangle s = new Rectangle(5,5,6,6);
		Rectangle t = new Rectangle(1,1,10,10);
		
		r.show();
		System.out.println("s의 면적은 " + s.square());
		if(t.contains(r))
			System.out.println("t는 r을 포함합니다.");
		if(t.contains(s))
			System.out.println("t는 s를 포함합니다.");
	}
}