import java.awt.Color;
import java.awt.Container;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class OpenChallenge extends JFrame{
	private JLabel la[]; 
	private JLabel tex = new JLabel("시작합니다.");
	public OpenChallenge() {
		super("OpenChallenge");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(null);
		
		tex.setSize(100,20);
		tex.setLocation(100,100);
		c.add(tex);
		
		la = new JLabel[3];
		for(int i=0;i<la.length;i++) {
			la[i] = new JLabel("0");
			la[i].setSize(30,30);
			la[i].setLocation(i*100,30);
			la[i].setForeground(Color.YELLOW);
			la[i].setOpaque(true);
			la[i].setBackground(Color.MAGENTA);
			c.add(la[i]);
		}
		c.addKeyListener(new MyKeyListener());
		
		
		setSize(300,200);
		setVisible(true);
		
		c.setFocusable(true);
		c.requestFocus();
	}
	
	class MyKeyListener extends KeyAdapter{
		public void keyPressed(KeyEvent e) {
			if(e.getKeyChar() == '\n') {
				int x = (int)(Math.random()*5);
				int y = (int)(Math.random()*5);
				int z = (int)(Math.random()*5);
				
				la[0].setText(Integer.toString(x));
				la[1].setText(Integer.toString(y));
				la[2].setText(Integer.toString(z));
				
				if(x==y && y==z) {
					tex.setText("축하합니다!!");
				}
				else {
					tex.setText("아쉽군요");
				}
				}
			}
		}

	public static void main(String[] args) {
		new OpenChallenge();
	}
}
