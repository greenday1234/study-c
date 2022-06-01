import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class GridLayoutEx extends JFrame{
	
	public GridLayoutEx() {
		super("4x4 color Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		
		c.setLayout(new GridLayout(4,4));
		Color color[] = {Color.RED, Color.ORANGE, Color.YELLOW, Color.GREEN, Color.CYAN
				, Color.BLUE, Color.MAGENTA, Color.GRAY, Color.BLACK, Color.DARK_GRAY,
				Color.LIGHT_GRAY, Color.PINK, Color.WHITE, Color.MAGENTA, Color.BLACK,
				Color.CYAN};
		for(int i=0;i<16;i++) {
			JLabel la = new JLabel(Integer.toString(i));
			la.setOpaque(true);
			la.setBackground(color[i]);
			c.add(la);
		}
		setSize(300,300);
		setVisible(true);
	}

	public static void main(String[] args) {
		new GridLayoutEx();
	}
}
