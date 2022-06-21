import java.awt.Container;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseClickPosition extends JFrame{
	private JLabel la = new JLabel("c");
	public MouseClickPosition() {
		super("클릭 연습 용 응용프로그램");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		
		c.setLayout(null);
		
		la.setSize(10,10);
		la.setLocation(100,100);
		la.addMouseListener(new MyMouseAdapter());
		c.add(la);
		
		setSize(300,300);
		setVisible(true);
	}

	class MyMouseAdapter extends MouseAdapter{
		public void mouseClicked(MouseEvent e) {
			JLabel l = (JLabel)e.getSource();
			int x = (int)(Math.random()*250);
			int y = (int)(Math.random()*250);
			
			l.setLocation(x,y);
		}
	}
	public static void main(String[] args) {
		new MouseClickPosition();
	}
}
