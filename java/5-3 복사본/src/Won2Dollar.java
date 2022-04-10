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

public class Won2Dollar extends Converter{
	int won;
	public Won2Dollar(int won) {
		this.won = won;
	}
	protected double convert(double src) {
		ratio = 1200;
		return src/1200;
	}
	protected String getSrcString() {
		return "원";
	}
	protected String getDestString() {
		return "달러";
		}
	public static void main(String[] args) {
		Won2Dollar toDollar = new Won2Dollar(1200);
		toDollar.run();
	}
}