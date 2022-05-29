import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseEventFrame extends JFrame {
	
	public MouseEventFrame(){
		super("마우스 올리기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		JLabel label = new JLabel("Love Java");
		c.add(label);
		
		label.addMouseListener(new MouseAdapter(){
			public void mouseEntered(MouseEvent e) {
				JLabel la = (JLabel) e.getSource();
				la.setText("사랑해");
			}
			public void mouseExited(MouseEvent e) {
				JLabel la = (JLabel) e.getSource();
				la.setText("Love Java");
			}
		});
		
		setSize(250,250);
		setVisible(true);
	}
	public static void main(String[] args) {
		new MouseEventFrame();
	}
}
