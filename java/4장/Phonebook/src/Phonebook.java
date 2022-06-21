import java.util.Scanner;

class Phone{
	private String name;
	private String tel;
	
	public Phone(String name, String tel) {
		this.name = name;
		this.tel = tel;
		
	}
	public String getName() {
		return name;
	}
	public String getTel() {
		return tel;
	}
	
}

public class Phonebook{
	private Phone[] pArray;
	private Scanner scanner;
	
	public Phonebook() {
		scanner=new Scanner(System.in);
	}
	
	void read() {
		System.out.print("인원수 >> ");
		int n=scanner.nextInt();
		pArray = new Phone[n];
		for(int i= 0;i<n;i++) {
			System.out.print("이름과 전화번호 입력 >> ");
			String name = scanner.next();
			String tel = scanner.next();
			pArray[i]=new Phone(name, tel);
		}
		System.out.println("저장완료");
	}
	String search(String name) {
		for(int i=0;i<pArray.length;i++)
		{
			if(pArray[i].getName().equals(name))
				return pArray[i].getTel();
		}
		return null;
	}
	
	void run() {  
		
		read();
		
		while(true) {
			System.out.println("검색할 이름 >> ");
			String name = scanner.next();
			
			if(name.equals("그만"))
				break;
			
			String tel = search(name);
			
			if(tel==null)
				System.out.println(name + "이 없습니다.");
			else
				System.out.println(name + "의 번호는 " + tel + "입니다.");
		}
		scanner.close();
	}
	
	public static void main(String[] args) {
		new Phonebook().run();
	}
}
