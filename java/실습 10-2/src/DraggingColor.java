import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;

public class DraggingColor extends JFrame{

	public DraggingColor() {
		super("드래깅동안 YELLOW");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setBackground(Color.GREEN);
		c.addMouseListener(new MyMouseListener());	//드래그와 released는 리스너와 모션리스너로 나뉘므로 둘 다 선언해
		c.addMouseMotionListener(new MyMouseListener());
		
		setSize(300,200);
		setVisible(true);
	}
	
	class MyMouseListener extends MouseAdapter{
		public void mouseDragged(MouseEvent e) {
			Component c = (Component)e.getSource();
			c.setBackground(Color.YELLOW);
		}
		public void mouseReleased(MouseEvent e) {
			Component c = (Component)e.getSource();
			c.setBackground(Color.GREEN);
		}
	}
	public static void main(String[] args) {
		new DraggingColor();
	}
}
