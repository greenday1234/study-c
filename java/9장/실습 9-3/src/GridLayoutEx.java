import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class GridLayoutEx extends JFrame{
	
	public GridLayoutEx() {
		super("Ten Color Buttons Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new GridLayout(1,10));
		
		for(int i=0;i<10;i++) {
			c.add(new JButton(Integer.toString(i)));
		}
		setSize(300,300);
		setVisible(true);
	}

	public static void main(String[] args) {
		new GridLayoutEx();
	}
}
