import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class keyPlusMinusFrame extends JFrame{
	
	public keyPlusMinusFrame() {
		super("Font Plust Minus Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JLabel label = new JLabel("Love Java");
		c.add(label);
		
		label.setFont(new Font("TimesRoman", Font.PLAIN, 10));
		
		label.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent e) {
				if(e.getKeyChar() == '+') {
					JLabel la = (JLabel) e.getSource();
					Font f = la.getFont();
					int size = f.getSize();	//현재 폰트의 사이즈를 알아야되기 때문에 가져옴
					la.setFont(new Font("TimesRoman", Font.PLAIN, size+5));
				}
				else if(e.getKeyChar() == '-') {
					JLabel la = (JLabel) e.getSource();
					Font f = la.getFont();
					int size = f.getSize();	//현재 폰트의 사이즈를 알아야되기 때문에 가져옴
					if(size < 5) {
						return ;
					}
					la.setFont(new Font("TimesRoman", Font.PLAIN, size-5));
				}
			}
		});
		
		setLocationRelativeTo(null);
		setSize(300,300);
		setVisible(true);
		label.setFocusable(true);
		label.requestFocus();
	}
	public static void main(String[] args) {
		new keyPlusMinusFrame();
	}
}
