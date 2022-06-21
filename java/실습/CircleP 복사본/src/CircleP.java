public class CircleP{
	int radius;
	String name;
	
	public CircleP() {
		radius = 1;
		name = "";
	}
	
	public CircleP(int r, String n) {
		radius = r;
		name = n;
	}
	public double getArea() {
		return 3.14*radius*radius;
	}
	public static void main(String[] args) {
		CircleP pizza = new CircleP(10, "자바피자");
		
		double area = pizza.getArea();
		System.out.println(pizza.name + "의 면적은 " + area);
		
		CircleP dount = new CircleP();
		dount.name = "도넛피자";
		area = dount.getArea();
		System.out.println(dount.name + "의 면적은 " + area);
	}
}