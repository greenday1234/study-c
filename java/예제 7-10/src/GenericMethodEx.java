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

public class GenericMethodEx {
	public static <T> GStack<T> reverse(GStack<T> a){	//사용되는 자료형, 리턴값
		GStack<T> s = new GStack<T>();	//제네릭 클래스 생성(클래스 타입이므로 생성 가능함)
		while(true) {
			T tmp;
			tmp = a.pop();
			if(tmp == null)
				break;
			else
				s.push(tmp);
		}
		return s;	//클래스 반환
	}
	public static void main(String[] args) {
		GStack<Double> gs = new GStack<Double>();
		
		for(int i=0;i<5;i++) {
			gs.push((double)i);	//i가 int형이므로 double로 캐스팅한다
		}
		gs = reverse(gs);
		for(int i=0;i<5;i++) {
			System.out.println(gs.pop());
		}
	}
}
