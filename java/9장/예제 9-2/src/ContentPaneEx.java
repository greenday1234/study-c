import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;

public class ContentPaneEx extends JFrame{
	public ContentPaneEx() {
		super("ContentPane과 JFrame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setBackground(Color.ORANGE);
		c.setLayout(new FlowLayout());
		
		c.add(new JButton("OK"));
		c.add(new JButton("Cancel"));
		c.add(new JButton("Ignore"));
		
		setSize(300,150);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ContentPaneEx();
		
	}
}
