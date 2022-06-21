import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class JLabelReverse extends JFrame{
	private JLabel la = new JLabel("Love Java");
	public JLabelReverse() {
		super("Left키로 문자열 교체");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		c.add(la);
		
		la.addKeyListener(new MyKeyListener());
		
		la.setFocusable(true);
		la.requestFocus();
		
		setSize(300,200);
		setVisible(true);
	}
	class MyKeyListener extends KeyAdapter{
		public void keyPressed(KeyEvent e) {
			JLabel l = (JLabel)e.getSource();
			if(e.getKeyCode() == e.VK_LEFT) {
				String str = l.getText();
				StringBuffer sb = new StringBuffer(str);
				sb.reverse();
				l.setText(sb.toString());
			}
		}
	}
	public static void main(String[] args) {
		new JLabelReverse();
	}
}
