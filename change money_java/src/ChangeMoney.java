import java.util.Scanner;

public class ChangeMoney {
	final static int ������ = 50000;
	final static int ���� = 10000;
	final static int õ�� = 1000;
	final static int ����� = 500;
	final static int ��� = 100;
	final static int ���ʿ� = 50;
	final static int �ʿ� = 10;
	final static int �Ͽ� = 1;
	public static void main(String args[]) {
		int money;
		int result;
		Scanner scanner = new Scanner(System.in);
		System.out.print("�ݾ��� �Է��Ͻÿ�>");
		money=scanner.nextInt();
		
		//money�� �������� ����� ���� ���
		result = money/������;
		money=money%������;
		if(result > 0) {
			System.out.println("�������� : " + result + "��");
		}
		result = money/����;
		money=money%����;
		if(result > 0) {
			System.out.println("������ : " + result + "��");
		}
		result = money/õ��;
		money=money%õ��;
		if(result > 0) {
			System.out.println("õ���� : " + result + "��");
		}
		result = money/�����;
		money=money%�����;
		if(result > 0) {
			System.out.println("����� : " + result + "��");
		}
		result = money/���;
		money=money%���;
		if(result > 0) {
			System.out.println("��� : " + result + "��");
		}
		result = money/���ʿ�;
		money=money%���ʿ�;
		if(result > 0) {
			System.out.println("���ʿ� : " + result + "��");
		}
		result = money/�ʿ�;
		money=money%�ʿ�;
		if(result > 0) {
			System.out.println("�ʿ� : " + result + "��");
		}
		result = money/�Ͽ�;
		money=money%�Ͽ�;
		if(result > 0) {
			System.out.println("�Ͽ� : " + result + "��");
		}
		
		scanner.close();
	}
}