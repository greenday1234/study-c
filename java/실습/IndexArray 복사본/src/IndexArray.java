import java.util.Random;

public class IndexArray{
	public static void main(String[] args) {
		Random r = new Random();
		
		int n[][] = new int[4][4];
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				n[i][j] = r.nextInt(10);
				System.out.print(n[i][j] + " ");
			}
			System.out.println();
		}
	}
}