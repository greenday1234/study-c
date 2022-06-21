import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
class NorthPanel extends JPanel{
	
	public NorthPanel() {
		this.setBackground(Color.LIGHT_GRAY);
		this.add(new JLabel("수식 입력"));
		this.add(new JTextField(18));
		this.setOpaque(true);
	}
}

class CenterPanel extends JPanel{
	
	public CenterPanel() {
		this.setLayout(new GridLayout(4,4));
		String text[] = {"0","1","2","3","4","5","6","7","8","9", "CE", "계산"};
		for(int i=0;i<12;i++) {
			this.add(new JButton(text[i]));
		}
		String str[] = {"+","-","x","/"};
		for(int i=0;i<4;i++) {
			JButton b = new JButton(str[i]);
			b.setBackground(Color.CYAN);
			b.setOpaque(true);
			this.add(b);
		}
	}
}

class SouthPanel extends JPanel{
	
	public SouthPanel() {
		this.setOpaque(true);
		this.setBackground(Color.YELLOW);
		JLabel la = new JLabel("계산 결과");
		this.add(la);
		this.add(new JTextField(18));
	}
}

public class CalcFrame extends JFrame{

	public CalcFrame() {
		super("계산기 프레임");
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
		new CalcFrame();
	}
}
