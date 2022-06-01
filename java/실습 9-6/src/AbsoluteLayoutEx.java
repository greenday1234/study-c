import java.awt.Color;
import java.awt.Container;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class AbsoluteLayoutEx extends JFrame{

	public AbsoluteLayoutEx() {
		super("Random Labels");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(null);
		
		for(int i=0;i<20;i++) {
			JLabel la = new JLabel(Integer.toString(i));
			la.setSize(10,10);
			la.setBackground(Color.BLUE);
			la.setOpaque(true);
			int x = (int)(Math.random()*200 + 50);
			int y = (int)(Math.random()*200 + 50);
			la.setLocation(x,y);
			c.add(la);
		}
		setSize(300,300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new AbsoluteLayoutEx();
	}
}
