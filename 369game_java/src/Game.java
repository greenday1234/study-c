import java.util.Scanner;

public class Game {
	public static void main(String args[])
	{
		int num;
		int count=0;	//�ڼ��� ��
		Scanner scanner = new Scanner(System.in);
		System.out.print("1~99 ������ ������ �Է��Ͻÿ�>");
		num=scanner.nextInt();
		
		if(num>=1 && num<= 99) {
			int a,b;
			a=num/10;	//a�� 10���ڸ�
			b=num%10;	//b�� 1���ڸ�
			
			if(a!=0 && a%3 == 0)
				count++;
			if(b!=0 && b%3 == 0)
				count++;
			
			if (count == 2)
				System.out.println("�ڼ�¦¦");
			else if (count == 1)
				System.out.println("�ڼ�¦");
			else
				System.out.println("�ڼ�����");
		}
		else {
			System.out.println("������ ������ ������ϴ�.");
		}
		scanner.close();
	}
}