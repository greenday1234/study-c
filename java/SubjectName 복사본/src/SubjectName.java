import java.util.Scanner;

public class SubjectName{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		String course [] = {"Java", "C++", "HTML5", "컴퓨터구조", "안드로이드"};
		int score [] = {95,88,76,62,55};
		String n;
		while(true) {
			System.out.print("과목 이름>>");
			n=scanner.next();
			if(n.equals("Java")) {
				System.out.println(course[0] + "의 점수는 " + score[0]);
			}
			else if(n.equals("C++")) {
				System.out.println(course[1] + "의 점수는 " + score[1]);
			}
			else if(n.equals("HTML5")) {
				System.out.println(course[2] + "의 점수는 " + score[2]);
			}
			else if(n.equals("컴퓨터구조")) {
				System.out.println(course[3] + "의 점수는 " + score[3]);
			}
			else if(n.equals("안드로이드")) {
				System.out.println(course[4] + "의 점수는 " + score[4]);
			}
			else if(n.equals("그만"))
				break;
			else {
				System.out.println("없는과목입니다.");
			}
		}
		scanner.close();
	}
}