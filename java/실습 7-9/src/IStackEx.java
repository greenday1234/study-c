import java.util.Vector;

interface IStack<T>{
	T pop();
	boolean push(T ob);
}

public class IStackEx {
	public static void main(String[] args) {
		IStack<Integer> stack = new MyStack<Integer>();
		for(int i=0;i<10;i++) {
			stack.push(i);
		}
		while(true) {
			Integer n = stack.pop();
			if(n == null)
				break;
			System.out.print(n + " ");
			}
		}
	}

class MyStack<T> implements IStack<T>{	//제네릭 클래스는 아래에 코드를 생성해야함.
	Vector<T> v = new Vector<T>();
	
	public T pop() {
		if(v.size() == 0) {
			return null;
		}
		else {
			return v.remove(0);
		}
	}
	public boolean push(T ob) {
		v.add(0, ob);
		return true;
	}
}