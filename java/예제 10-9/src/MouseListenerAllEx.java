import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseListenerAllEx extends JFrame{
	private JLabel la = new JLabel("No Mouse Event");
	
	public MouseListenerAllEx() {
		super("MouseListener와 MouseMotionListener 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		MyMouseListener listener = new MyMouseListener();
		c.addMouseListener(listener);
		c.addMouseMotionListener(listener);
		
		c.add(la);
		setSize(300,200);
		setVisible(true);
	}
	
	class MyMouseListener extends MouseAdapter{
		public void mousePressed(MouseEvent e) {
			la.setText("MousePressed (" + e.getX() + ", " + e.getY() + ")");
		}
		public void mouseReleased(MouseEvent e) {
			la.setText("MouseReleased (" + e.getX() + ", " + e.getY() + ")");
		}
		public void mouseEntered(MouseEvent e) {
			Component c = (Component)e.getSource();
			c.setBackground(Color.CYAN);
		}
		public void mouseExited(MouseEvent e) {
			Component c = (Component)e.getSource();
			c.setBackground(Color.YELLOW);
		}
		public void mouseDragged(MouseEvent e) {
			la.setText("MouseDragged (" + e.getX() + ", " + e.getY() + ")");
		}
		public void mouseMoved(MouseEvent e) {
			la.setText("MouseMoved (" + e.getX() + ", " + e.getY() + ")");
		}
	}
	
	
	public static void main(String[] args) {
		new MouseListenerAllEx();
	}
}
