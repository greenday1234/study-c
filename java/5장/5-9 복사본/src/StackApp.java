import java.util.Scanner;

interface Stack{
	int length();
	int capacity();
	String pop();
	boolean push(String val);
}

 class StringStack implements Stack{
	int top;
	String [] arr;
	public StringStack(int n) {
		top = 0;
		arr = new String[n];
	}
	public int length() {	//현재 스택에 저장된 개수 리턴 
		return top;
	}
	public int capacity() {	//스택의 전체 저장 가능한 개수 리턴 
		return arr.length;
	}
	public String pop() {	// 스택의 탑에 실수 저장 
		if(top==0) {
			return "";
		}
		else {
			String str = arr[top-1];
			top--;
			return str;
		}
	}
	public boolean push(String val) {	//	스택의 탑에 저장된 실수 리턴
		if(top == arr.length)
			return false;
		else {
			arr[top] = val;
			top++;
			return true;
			}
		}
}

public class StackApp{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("총 스택 저장공간의 크기 입력>>");
		StringStack s = new StringStack(scanner.nextInt());		
		while(true) {
			System.out.println("문자열 입력>>");
			String name = scanner.next();
			
			if(name.equals("그만"))
				break;
			
			boolean result = s.push(name);
			if(result == false)
				System.out.println("스택이 꽉 차서 푸시 불가!");
		}
		System.out.print("스택에 저장된 모든 문자열 팝 : ");
		for(int i = 0; i<s.arr.length;i++) {
				System.out.print(s.pop() + " ");
		}
		scanner.close();
	}
}