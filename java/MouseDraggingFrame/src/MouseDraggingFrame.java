import java.awt.Color;
import java.awt.Container;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JComponent;
import javax.swing.JFrame;

public class MouseDraggingFrame extends JFrame{
	
	public MouseDraggingFrame() {
		super("드래깅하는 동안 Yellow로 변경");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setBackground(Color.GREEN);
		
		MyMouseListener ml = new MyMouseListener();
		c.addMouseMotionListener(ml);	//drag Event receive
		c.addMouseListener(ml);			//mouse release event receive 
		
		setSize(300,300);
		setVisible(true);
	}
	class MyMouseListener extends MouseAdapter{
		public void mouseDragged(MouseEvent e) {
			JComponent c = (JComponent) e.getSource();
			c.setBackground(Color.YELLOW);
		}
		public void mouseReleased(MouseEvent e) {
			JComponent c = (JComponent) e.getSource();
			c.setBackground(Color.GREEN);
		}
	}
	public static void main(String[] args) {
		new MouseDraggingFrame();
	}
}
