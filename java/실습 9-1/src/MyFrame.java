import javax.swing.JFrame;

public class MyFrame extends JFrame{

	public MyFrame() {
		super("Let's study Java");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		setSize(400,200);
		setVisible(true);
	}
	public static void main(String[] args) {
		new MyFrame();
	}
}
