import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class FontSize extends JFrame{
	private JLabel la = new JLabel("Love Java");
	public FontSize() {
		super("+,-키로 폰트 조절");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		
		c.setLayout(new FlowLayout());
		
		la.addKeyListener(new MyKeyAdapter());
		c.add(la);
		la.setFont(new Font("Arial", Font.PLAIN, 10));
		la.setFocusable(true);
		la.requestFocus();
		
		setSize(300,200);
		setVisible(true);		
	}
	
	class MyKeyAdapter extends KeyAdapter{
		public void keyPressed(KeyEvent e) {
			JLabel l = (JLabel)e.getSource();
			Font f = l.getFont();
			int size = f.getSize();
			if(e.getKeyChar() == '+') {
				l.setFont(new Font("Arial", Font.PLAIN, size+5));
			}
			else if(e.getKeyChar() == '-' && f.getSize() > 5) {
				l.setFont(new Font("Arial", Font.PLAIN, size-5));
			}
		}
	}

	public static void main(String[] args) {
		new FontSize();
	}
}
