import java.util.Scanner;

public class ChangeMoney {
	final static int 오만원 = 50000;
	final static int 만원 = 10000;
	final static int 천원 = 1000;
	final static int 오백원 = 500;
	final static int 백원  = 100;
	final static int 오십원  = 50;
	final static int 십원  = 10;
	final static int 일원  = 1;
	public static void main(String args[]) {
		int money;
		int result;
		Scanner scanner = new Scanner(System.in);
		System.out.print("금액을 입력하세요 >");
		money=scanner.nextInt();
		
		//money�� �������� ����� ���� ���
		result = money/오만원;
		money=money%오만원;
		if(result > 0) {
			System.out.println("오만원권 : " + result + "장");
		}
		result = money/만원;
		money=money%만원;
		if(result > 0) {
			System.out.println("만원권 : " + result + "장");
		}
		result = money/천원;
		money=money%천원;
		if(result > 0) {
			System.out.println("천원권 : " + result + "장");
		}
		result = money/오백원;
		money=money%오백원;
		if(result > 0) {
			System.out.println("오백원 : " + result + "장");
		}
		result = money/백원;
		money=money%백원;
		if(result > 0) {
			System.out.println("백원 : " + result + "장");
		}
		result = money/오십원;
		money=money%오십원;
		if(result > 0) {
			System.out.println("오십원 : " + result + "장");
		}
		result = money/십원;
		money=money%십원;
		if(result > 0) {
			System.out.println("십원 : " + result + "장");
		}
		result = money/일원;
		money=money%일원;
		if(result > 0) {
			System.out.println("일원 : " + result + "장");
		}
		
		scanner.close();
	}
}