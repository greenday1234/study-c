class clacEx{
	public static int abs(int a) { return a>0?a:-a;}
	public static int max(int a, int b) {return (a>b)?a:b;}
	public static int min(int a, int b) {return (a>b)?b:a;}
	}
public class Clac{
	public static void main(String[] args) {
		System.out.println(clacEx.abs(-5));
		System.out.println(clacEx.max(10,8));
		System.out.println(clacEx.min(-3, -8));
	}
}