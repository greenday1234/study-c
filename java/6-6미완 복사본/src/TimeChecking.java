import java.util.Calendar;

public class TimeChecking{
	public static void main(String[] args) {
		System.out.println("10�ʿ� ����� ����� �̱�� �����Դϴ�.");
		System.out.print("Ȳ���� ���� <Enter>Ű>>");
		Calendar c= Calendar.getInstance();
		int second = c.get(Calendar.SECOND);
		System.out.println("���� �� �ð� = " + second);
		
		
		
	}
}