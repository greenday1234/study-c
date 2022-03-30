import java.util.Random;

public class RandomInt{
	public static void main(String[] args) {
		double sum = 0;
		Random r = new Random();
		int n[] = new int[10];
		System.out.print("랜덤한 정수들 : ");
		for(int i=0;i<10;i++) {
			n[i]=r.nextInt(10);
			sum+=n[i];
			System.out.print(n[i] + " ");
		}
		System.out.println();
		System.out.println("평균은 " + sum/10);
	}
}