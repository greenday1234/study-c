import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class LeftMove extends JFrame{
	private JLabel la = new JLabel("Love Java");
	public LeftMove() {
		super("Lefy키로 문자열 이동");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		
		c.setLayout(new FlowLayout());
		c.add(la);
		
		la.addKeyListener(new MyKeyAdapter());
		
		la.setFocusable(true);
		la.requestFocus();
		
		setSize(300,200);
		setVisible(true);
	}
	
	class MyKeyAdapter extends KeyAdapter{
		public void keyPressed(KeyEvent e) {
			JLabel l = (JLabel)e.getSource();
			if(e.getKeyCode() == e.VK_LEFT) {
				String str = l.getText();
				String ns = str.substring(1, str.length());
				String bs = str.substring(0,1);
				str = ns+bs;
				l.setText(str);
			}
		}
	}
	public static void main(String[] args) {
		new LeftMove();
	}
}
