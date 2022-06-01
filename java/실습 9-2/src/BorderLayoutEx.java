import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;

public class BorderLayoutEx extends JFrame{

	public BorderLayoutEx() {
		super("BorderLayout Practice");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new BorderLayout(5,7));
		
		c.add(BorderLayout.NORTH, new JButton("North"));
		c.add(BorderLayout.WEST, new JButton("West"));
		c.add(BorderLayout.EAST, new JButton("East"));
		c.add(BorderLayout.SOUTH, new JButton("South"));
		c.add(BorderLayout.CENTER, new JButton("Center"));
		
		setSize(300,300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new BorderLayoutEx();
	}
}
