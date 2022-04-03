public class Song{
	private int year;
	private String country;
	private String artist;
	private String title;
	
	private Song(int year, String country, String artist, String title){
		this.year = year;
		this.country = country;
		this.artist = artist;
		this.title = title;
	}
	void show() {
		System.out.println(year + "년 " + country + "국적의 " + artist + "가 부른 " + title);
	}
	public static void main(String[] args) {
		Song song = new Song(1987, "스웨덴", "ABBA", "Dancing Queen");
		song.show();
	}
	
}