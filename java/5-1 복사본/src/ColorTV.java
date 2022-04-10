class TV{
	private int size;
	public TV(int size) {
		this.size = size;
	}
	protected int getSize() {
		return size;
	}
}
class IPTV extends ColorTV{
	String arr;
	public IPTV(String arr, int size, int color) {
		super(size, color);
		this.arr = arr;
	}
	String getArr(){
		return arr;
	}
	void printProperty() {
		System.out.println("나의 IPTV는 " + getArr() + " 주소의 " + getSize() + "인치 " + getColor() + "컬러");
	}
}
public class ColorTV extends TV{
	
	private int color;
	public ColorTV(int size, int color) {
		super(size);
		this.color = color;
	}
	int getColor() {
		return color;
	}
	
	public static void main(String[] args) {
		IPTV myTV = new IPTV("192.1.1.2",32,1024);
		myTV.printProperty();
	}
}