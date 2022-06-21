import java.util.Scanner;

class Alpha{
	private char alphabet;
	private int count = 0;
	public Alpha(char a) {
		this.alphabet = a;
	}
	char getalphabet() {
		return alphabet;
	}
	void setcount(int count) {
		this.count = count;
	}
	int getcount() {
		return count;
	}
}
public class Histogram{
	Scanner scanner = new Scanner(System.in);
	Alpha alpha [];
	char a = 'A';
	public void setalpha() {
		alpha = new Alpha[26];
		for(int i=0;i<26;i++) {
			alpha[i] = new Alpha(a);
			a++;
		}
	}
	String readString() {
		StringBuffer sb = new StringBuffer();
		while(true) {
			String line = scanner.nextLine();
			if(line.equals(";"))
				break;
			sb.append(line);
		}
		scanner.close();
		return sb.toString();
	}
	void count(String alp) {
		int cnt = 0;
		char a = 'a';
		int count;
		while(cnt<26) {
			count = 0;
			for(int i=0;i<alp.length();i++) {
				if(alp.charAt(i) == a) {
					count++;
				}
			}
			alpha[cnt].setcount(count);
			cnt++;
			a++;
		}
	}
	void draw() {
		char a= 'a';
		int num = 0;
		System.out.println("히스토그램을 그립니다.");
		while(a<'z') {
		System.out.print(alpha[num].getalphabet());
		for(int i=0;i<alpha[num].getcount();i++) {
			System.out.print("-");
			}
		a++;
		num++;
		System.out.println();
		}
	}
	public static void main(String[] args) {
		Histogram h = new Histogram();
		h.setalpha();
		System.out.println("영문 텍스트를 입력하고 세미 콜론을 입력하세요.");
		h.count(h.readString());
		h.draw();
	}
}
