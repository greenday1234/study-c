import java.util.ArrayList;
import java.util.Scanner;

public class ArrayListAverage {
	public static void main(String[] args) {
		double sum=0;
		ArrayList<String> a = new ArrayList<String>(5);
		Scanner scanner = new Scanner(System.in);
		System.out.print("5개의 학점을 빈 칸으로 분리 입력(A/B/C/D/E/F)>>");
		for(int i=0;i<5;i++) {
			String n = scanner.next();
			a.add(n);
		}
		ArrayList<Double> ai = new ArrayList<Double>(6);
		for(int i=0;i<a.size();i++) {
			if(a.get(i).equals("A")) {
				ai.add(4.0);
			}
			else if(a.get(i).equals("B")) {
				ai.add(3.0);
			}
			else if(a.get(i).equals("C")) {
				ai.add(2.0);
			}
			else if(a.get(i).equals("D")) {
				ai.add(1.0);
			}
			else if(a.get(i).equals("F")) {
				ai.add(0.0);
			}
			else {
				System.out.println("잘못 입력했습니다.");
				scanner.close();
				return;
			}
		}
		for(int i=0;i<a.size();i++) {
			sum = sum+ai.get(i);
		}

		double average = sum/ai.size();
		System.out.println("평균 점수는 " + average);
		scanner.close();
	}
}
