import java.awt.Component;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseListenerEx extends JFrame{
	private JLabel la = new JLabel("Love Java");
	public MouseListenerEx() {
		super("마우스 올리기 내리기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		
		c.add(la);
		la.addMouseListener(new MyMouseListener());	//레이블에 마우스 리스너 달기
		
		
		setSize(300,200);
		setVisible(true);
		
	}
	
	class MyMouseListener extends MouseAdapter{
		public void mouseEntered(MouseEvent e) {
			JLabel l = (JLabel)e.getSource();
			l.setText("사랑해");
		}
		public void mouseExited(MouseEvent e) {
			JLabel l = (JLabel)e.getSource();
			l.setText("Love Java");
		}
	}
	
	public static void main(String[] args) {
		new MouseListenerEx();
	}
}
