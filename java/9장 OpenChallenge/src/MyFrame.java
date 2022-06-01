import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

class NorthPanel extends JPanel{
	public NorthPanel() {
	setBackground(Color.LIGHT_GRAY);
	this.add(new JButton("Open"));
	this.add(new JButton("Read"));
	this.add(new JButton("Close"));
	}
}

class CenterPanel extends JPanel{
	
	public CenterPanel() {
		this.setLayout(null);
		String label[] = {"Hello", "Java", "Love"};
		int x,y;
		JLabel la;
		for(int i=0;i<3;i++) {
			x = (int)(Math.random()*250);
			y = (int)(Math.random()*250);	//글자 짤림 방지
			
			la = new JLabel(label[i]);
			la.setLocation(x,y);
			la.setSize(50,10);
			this.add(la);
			
		}
	}
}

public class MyFrame extends JFrame{
	
	public MyFrame() {
		super("Open Challenge 9");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		
		c.add(new NorthPanel(), BorderLayout.NORTH);
		c.add(new CenterPanel(), BorderLayout.CENTER);
		
		setSize(300,300);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new MyFrame();
	}
}
