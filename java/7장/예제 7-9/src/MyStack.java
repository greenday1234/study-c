class GStack<T>{
	int tos;
	Object[] stack;
	public GStack() {
		tos = 0;
		stack = new Object[10];	//제네릭 타입이 아닌 object배열을 생셩함
	}
	public void push(T item) {
		if(tos == 10) {
			return;
		}
		stack[tos++] = item;
	}
	public T pop() {
		if(tos == 0)
			return null;
		return (T)stack[--tos];	//타입 매개변수 타입으로 캐스팅
	}
}
public class MyStack {
	public static void main(String[] args) {
		GStack<String> stringStack = new GStack<String>();
		
		stringStack.push("seoul");
		stringStack.push("busan");
		stringStack.push("LA");
		
		for(int i=0;i<3;i++){
			System.out.println(stringStack.pop());
		
		}
		GStack<Integer> inStack = new GStack<Integer>();
		
		inStack.push(1);
		inStack.push(2);
		inStack.push(3);
		
		for(int i=0;i<3;i++) {
			System.out.println(inStack.pop());
		}
	}
}
