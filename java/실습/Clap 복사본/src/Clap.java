public class Clap{
	public static void main(String[] args) {
		for(int i=0;i<10;i++) {
			for(int j=1;j<10;j++) {
				if(i%3==0 && j%3==0 && j!=0 && i!=0) {
					System.out.print(i);
					System.out.println(j + " 박수 짝짝");
					}
				else if(i%3 == 0 && i!=0) {
					System.out.print(i);
					System.out.println( j + " 박수 짝");
					}
				else if(j%3 == 0 && j!=0) {
					System.out.print(i);
					System.out.println( j + " 박수 짝");
				}
			}
			
		}
		
	}
}