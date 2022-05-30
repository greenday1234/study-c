import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

class Point{
	private String name;
	private int point;
	
	public Point(String name, int point) {
		this.name = name;
		this.point = point;
	}
	
	public String getName() {
		return name;
	}
	public int getPoint() {
		return point;
	}
}

public class PointHashMap {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		HashMap<String, Point> h = new HashMap<String, Point>();
		System.out.println("포인트 관리 프로그램입니다.");
		while(true) {
			
			
			System.out.print("이름과 포인트 입력>>");
			String name = scanner.next();
			if(name.equals("그만"))
				break;
			int point = scanner.nextInt();
			if(h.get(name) == null) {
			h.put(name, new Point(name, point));
			}
			else {
				h.put(name, new Point(name, h.get(name).getPoint()+point));
			}
			
			Set<String> keys = h.keySet();
			Iterator<String> it = keys.iterator();
			while(it.hasNext()) {
				String str = it.next();
				Point po = h.get(str);
				System.out.print("(" + po.getName() + ", " + po.getPoint() + ")");
			}
			System.out.println();
		}
	}
}
