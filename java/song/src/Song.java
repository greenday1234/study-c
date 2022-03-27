

public class Song{
	private String title;
	private String artist;
	private int year;
	private String country;
	
	public Song() {
		
	}
	public Song(String title, String artist, int year, String country) {
		this.title = title;
		this.artist = artist;
		this.year = year;
		this.country=country;
		
	}
	public Song(String title, String artist) {
		this.title = title;
		this.artist = artist;
		
	}
	public void show() {
		System.out.print(year + "�� ");
		System.out.print(country + "������ ");
		System.out.print(artist + "�� �θ� ");
		System.out.println(title);
	}
	public static void main(String[] args) {
		Song mysong = new Song("Dancing Queen", "ABBA", 1978, "Sweden");
		Song yoursong = new Song("Happy birthday", "unknown", 2002, "ROK");
		mysong.show();
		yoursong.show();
	}
	
}