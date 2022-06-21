import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

class NorthPanel extends JPanel{
	
	public NorthPanel() {
		this.setBackground(Color.LIGHT_GRAY);
		this.add(new JButton("열기"));
		this.add(new JButton("닫기"));
		this.add(new JButton("나가기"));
		this.setOpaque(true);
	}
}

class CenterPanel extends JPanel{
	
	public CenterPanel() {
		this.setLayout(null);
		
		for(int i=0;i<10;i++) {
			int x = (int)(Math.random()*290);
			int y = (int)(Math.random()*290);
			JLabel la = new JLabel("*");
			la.setSize(20,20);
			la.setLocation(x,y);
			la.setForeground(Color.ORANGE);
			la.setOpaque(true);
			this.add(la);
		}
	}
}

class SouthPanel extends JPanel{
	
	public SouthPanel() {
		this.setBackground(Color.YELLOW);
		this.add(new JButton("Word Input"));
		this.add(new JTextField(12));
		this.setOpaque(true);
	}
}

public class RandomLabelPanel extends JFrame{
	
	public RandomLabelPanel() {
		super("여러 개의 패널을 가진 프레임");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		
		c.add(new NorthPanel(), BorderLayout.NORTH);
		c.add(new CenterPanel(), BorderLayout.CENTER);
		c.add(new SouthPanel(), BorderLayout.SOUTH);
		
		setSize(300,300);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		new RandomLabelPanel();
	}
}
