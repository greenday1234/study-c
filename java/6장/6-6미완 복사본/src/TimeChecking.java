import java.util.Calendar;

public class TimeChecking{
	public static void main(String[] args) {
		System.out.println("10초에 가까운 사람이 이기는 게임입니다.");
		System.out.print("황기태 시작 <Enter>키>>");
		Calendar c= Calendar.getInstance();
		int second = c.get(Calendar.SECOND);
		System.out.println("현재 초 시간 = " + second);
		
		
		
	}
}