public class BookStr{
	String title;
	String author;
	public BookStr(String t) {
		title = t;
		author = "작자 미상";
	}
	public BookStr(String t, String a) {
		title = t;
		author = a;
	}
	public static void main(String[] args) {
		BookStr littlePrince = new BookStr("어린왕자", "생텍쥐페리");
		BookStr loveStory = new BookStr("춘향전");
		System.out.println(littlePrince.title + " " + littlePrince.author);
		System.out.println(loveStory.title + " " + loveStory.author);
	}
}