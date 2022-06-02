import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseWheelEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseWheelEx extends JFrame{
	private JLabel la = new JLabel("Love Java");
	public MouseWheelEx() {
		super("마우스 휠을 굴려 폰트 크기 조절");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		
		la.setFont(new Font("Arial", Font.PLAIN, 10));
		
		c.add(la);
		c.setLayout(new FlowLayout());
		la.addMouseWheelListener(new MyMouseWheelListener());
		
		la.setFocusable(true);
		la.requestFocus();
		
		setSize(300,300);
		setVisible(true);
	}
	
	class MyMouseWheelListener extends MouseAdapter{
		public void mouseWheelMoved(MouseWheelEvent e) {
			JLabel l = (JLabel)e.getSource();
			Font f = l.getFont();
			int size = f.getSize();
			
			int n = e.getWheelRotation();
			
			if(n < 0 && size > 5) {
				l.setFont(new Font("Arial", Font.PLAIN, size-5));
			}
			else {
				l.setFont(new Font("Arial", Font.PLAIN, size+5));
			}
		}
	}
	public static void main(String[] args) {
		new MouseWheelEx();
	}
}
