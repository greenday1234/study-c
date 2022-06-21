import java.awt.Color;
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
		Color color[] = {Color.RED, Color.ORANGE, Color.YELLOW, Color.GREEN, Color.CYAN, Color.BLUE
				, Color.MAGENTA, Color.GRAY, Color.PINK, Color.LIGHT_GRAY};
		
		for(int i=0;i<10;i++) {
			JButton b = new JButton(Integer.toString(i));
			b.setOpaque(true);	//배경 불투명도
			b.setBackground(color[i]);
			c.add(b);
		}
		setSize(300,300);
		setVisible(true);
	}

	public static void main(String[] args) {
		new GridLayoutEx();
	}
}
