import java.util.Scanner;

public class Concert{
	private String hallName;
	private Scanner scanner;
	private Group[] group = new Group[3];	//S,A,B
	
	
	public Concert(String hallName) {
		this.hallName = hallName;
		scanner = new Scanner(System.in);
		group[0] = new Group('S', 10);	//�¼��׷�, �¼���
		group[1] = new Group('A', 10);
		group[2] = new Group('B', 10);
	}
	
	private void reserve() {
		System.out.print("�¼����� S(1), A(2), B(3)>>");
		int type = scanner.nextInt();
		if(type <1 || type >3) {
			System.out.println("�߸��� �¼� Ÿ���Դϴ�.");
			return;
		}
		
		group[type-1].reserve(); 
	}
	
	private void search() {
		for(int i=0;i<group.length;i++)
			group[i].Show();
		System.out.println("<<<��ȸ�� �Ϸ��Ͽ����ϴ�.>>>");
	}
	
	private void cancel() {
		System.out.println("�¼� S:1, A:2, B:3>>>");
		int type = scanner.nextInt();
		if(type <1 || type >3) {
			System.out.println("�߸��� �¼� Ÿ���Դϴ�.");
			return;
		}
		group[type-1].cancel();
	}
	
	public void run() {
		System.out.println(hallName + "���� �ý����Դϴ�.");
		int choice = 0;	//����ڰ� ������ ��� 1: ���� 2: ��ȸ 3: ��� 4: ������
		while (choice != 4) {
			System.out.print("����: 1, ��ȸ: 2, ���: 3, ������: 4>>");
			choice = scanner.nextInt();
			
			
			switch(choice) {
			case 1:	//����
				reserve();
				break;
			case 2:	//��ȸ
				search();
				break;
			case 3: //���
				cancel();
				break;
			case 4:	//������
				break;
			default :
				System.out.println("�߸� �Է��߽��ϴ�.");
			}
		}
	}
}