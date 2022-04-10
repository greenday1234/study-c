import java.util.Scanner;

abstract class Converter{
	abstract protected double convert(double src);
	abstract protected String getSrcString();
	abstract protected String getDestString();
	protected double ratio;
	
	public void run() {
		Scanner scanner = new Scanner(System.in);
		System.out.println(getSrcString() + "을 " + getDestString() + "로 바꿉니다. ");
		System.out.println(getSrcString() + "을 입력하세요>>");
		double val = scanner.nextDouble();
		double res = convert(val);
		System.out.println("변환 결과: " + res + getDestString() + "입니다.");
		scanner.close();
	}
}

public class Km2Mile extends Converter{
	int km;
	public Km2Mile(int km) {
		this.km = km;
	}
	protected double convert(double src) {
		ratio = 1.6;
		return src/1.6;
	}
	protected String getSrcString() {
		return "Km";
	}
	protected String getDestString() {
		return "Mile";
		}
	public static void main(String[] args) {
		Km2Mile toMile = new Km2Mile(1200);
		toMile.run();
	}
}