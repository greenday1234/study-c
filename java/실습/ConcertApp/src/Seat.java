
public class Seat{
	private  String name;
	public Seat() {
		name = null;
	}
	public String getName() {
		return name;
	}
	public void cancel() {
		name = null;
	}
	public void reserve(String name) {
		this.name = name;
		
	}
	public boolean isOccupied() {
		if (name == null)
			return false;
		else
			return true;
	}
	
	public boolean match(String name) {
		return (name.equals(this.name));
	}
}