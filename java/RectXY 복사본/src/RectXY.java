import java.util.Scanner;


public class RectXY{
	
	public static boolean inrect(int x1, int y1, int x2, int y2, int rectx1, int recty1, int rectx2, int recty2) {
	if((x1>=rectx1 && x1<=rectx2) && (y1>=recty1 && y1<=recty2)
			&& (x2>=rectx1 && x2<=rectx2) && (y2>=recty1 && y2<=recty2))
		return true;
	else
		return false;
}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("점 (x1,y1), (x2,y2) 의 좌표를 입력하시오>> ");
		int x1 = scanner.nextInt();
		int y1 = scanner.nextInt();
		int x2 = scanner.nextInt();
		int y2 = scanner.nextInt();
		
		boolean total;
		total = inrect(x1,y1,x2,y2,100,100,200,200);
		if(total==true)
			System.out.println("충돌하지 않습니다.");
		else
			System.out.println("충돌합니다.");
		
		scanner.close();
		
		
	}
}