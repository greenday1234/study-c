import java.util.Random;

public class RandomArray{
	public static void main(String[] args) {
		Random r = new Random();
		
		int n[][] = new int [4][4];
		int a;
		int b;
		int count=0;
		while(true) {
			a = r.nextInt(4);
			b = r.nextInt(4);
			
			if(n[a][b]==0) {
		n[a][b] = r.nextInt(10)+1;
		count++;
		}
			if(count==10)
				break;
		}	
		
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) 
				System.out.print(n[i][j] + " ");
			
			System.out.println();
		}
	
		}
}