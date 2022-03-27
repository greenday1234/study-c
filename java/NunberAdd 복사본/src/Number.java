public class Number{
	public static void main(String[] args) {
		int num[] = new int[100];
		int add=0;
		int arr=1;
		int ind=0;
		for(int i=0;i<100;i++)	//배열안에 1~100까지의 숫자를 넣음.
		{
			num[i]=arr;
			arr++;
		}
		
		for(int j=0;j<100;j++)	//배열안의 숫자들을 계속 더하기
		{
			ind=0;
			for(int k=0;k<=j;k++) //각 항들을 더하기
			{
				add += num[ind];
				ind++;
			}
		}
		System.out.println(add);
	}
}