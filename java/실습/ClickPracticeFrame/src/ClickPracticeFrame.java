import java.awt.Container;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class ClickPracticeFrame extends JFrame{
	
	public ClickPracticeFrame() {
		super("ClickPracticeFrame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(null);
		
		JLabel label = new JLabel("c");
		c.add(label);
		
		label.setLocation(100,100);
		label.setSize(20,20);
		
		label.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				JLabel la = (JLabel) e.getSource();
				Container c = la.getParent();
				
				int panelwidth = c.getWidth();
				int panelheight = c.getHeight();
				int x = (int) (Math.random() * panelwidth);
				int y = (int) (Math.random() * panelheight);
				la.setLocation(x,y);
			}
		});
		
		setLocationRelativeTo(null);
		setSize(500,500);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ClickPracticeFrame();
	}
}
