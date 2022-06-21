public class TV{
	String str;
	int year;
	int inch;
	private TV(String str, int year, int inch) {
	this.str=str;
	this.year=year;
	this.inch=inch;
	}
	private void show() {
		System.out.println(str + "에서 만든 " + year + "년형 " + inch + "인치 TV");
	}
	public static void main(String[] args) {
		TV myTV = new TV("LG", 2017, 32);
		myTV.show();
	}
}