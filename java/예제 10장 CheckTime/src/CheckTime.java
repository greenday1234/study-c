import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;

public class CheckTime extends JFrame{
	public CheckTime() {
		super("CheckTime");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.addMouseListener(new MyMouseListener());
		
		setSize(300,200);
		setVisible(true);
	}
	
	class MyMouseListener extends MouseAdapter{
		public void mouseClicked(MouseEvent e) {
			if(e.getButton() == MouseEvent.BUTTON1) {
				Component c = (Component)e.getSource();
				c.setBackground(Color.RED);
			}
			else if(e.getButton() == MouseEvent.BUTTON3) {
				Component c = (Component)e.getSource();
				c.setBackground(Color.BLUE);
			}
		}
	}
	public static void main(String[] args) {
		new CheckTime();
	}
}
