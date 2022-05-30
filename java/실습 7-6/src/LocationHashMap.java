import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;
class Location{
	private String city;
	private String Hardness;
	private String Latitude;
	
	public Location(String city, String Hardness, String Latitude) {
		this.city = city;
		this.Hardness = Hardness;
		this.Latitude = Latitude;
	}
	public String getCity() {
		return city;
	}
	public String getHardness() {
		return Hardness;
	}
	public String getLatitude() {
		return Latitude;
	}
}


public class LocationHashMap {
	Scanner scanner = new Scanner(System.in);
	HashMap<String, Location> h = new HashMap<String, Location>();
	
	private void read() {
		System.out.println("도시, 경도, 위도를 입력하시오.");
		for(int i=0;i<4;i++) {
			System.out.print(">>");
			String str = scanner.nextLine();
			StringTokenizer st = new StringTokenizer(str, ", ");
			String city = st.nextToken();
			String Hardness = st.nextToken();
			String Latitude = st.nextToken();
			h.put(city, new Location(city, Hardness, Latitude));
		}
	}
	
	private void printAll() {
		Set<String> keys = h.keySet();
		Iterator<String> it = keys.iterator();
		System.out.println("------------------------");
		while(it.hasNext()) {
			String st = it.next();
			Location lo = h.get(st);
			System.out.println(lo.getCity() + " " + lo.getHardness() + " " + lo.getLatitude());
		}
		System.out.println("------------------------");
	}
	private void searchcity() {
		while(true) {
			System.out.print("도시 이름>>");
			String city = scanner.nextLine();
			if(city.equals("그만")) {
				break;
			}
			Location location = h.get(city);
			if(location != null) {
				System.out.println(location.getCity() + " " + location.getHardness() + " "
				+ location.getLatitude());
			}
			else {
				System.out.println(city + "는 없습니다.");
			}
		}
	}
	
	public void run() {
		read();
		printAll();
		searchcity();
		scanner.close();
	}
	
	public static void main(String[] args) {
		LocationHashMap lh = new LocationHashMap();
		lh.run();
	}
}
