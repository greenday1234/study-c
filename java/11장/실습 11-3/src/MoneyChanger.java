import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class MoneyChanger extends JFrame{

	public MoneyChanger() {
		super("Money Changer");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JLabel la = new JLabel("금액 ");
		c.add(la);
		JTextField text = new JTextField(10);
		c.add(text);
		JButton btn = new JButton("계산");
		c.add(btn);
		btn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
			}
		});
		JLabel la50000 = new JLabel("오만원 ");
		c.add(la50000, FlowLayout.CENTER);
		JTextField text50000 = new JTextField(10);
		c.add(text50000, FlowLayout.CENTER);
		JLabel la10000 = new JLabel("만원 ");
		c.add(la10000, FlowLayout.CENTER);
		JTextField text10000 = new JTextField(10);
		c.add(text10000, FlowLayout.CENTER);
		JLabel la1000 = new JLabel("천원 ");
		c.add(la1000, FlowLayout.CENTER);
		JTextField text1000 = new JTextField(10);
		c.add(text1000, FlowLayout.CENTER);
		JLabel la500 = new JLabel("오백원 ");
		c.add(la500, FlowLayout.CENTER);
		JTextField text500 = new JTextField(10);
		c.add(text500, FlowLayout.CENTER);
		JLabel la100 = new JLabel("백원 ");
		c.add(la100, FlowLayout.CENTER);
		JTextField text100 = new JTextField(10);
		c.add(text100, FlowLayout.CENTER);
		JLabel la50 = new JLabel("오십원 ");
		c.add(la50, FlowLayout.CENTER);
		JTextField text50 = new JTextField(10);
		c.add(text50, FlowLayout.CENTER);
		JLabel la10 = new JLabel("십원 ");
		c.add(la10, FlowLayout.CENTER);
		JTextField text10 = new JTextField(10);
		c.add(text10, FlowLayout.CENTER);
		JLabel la1 = new JLabel("일원 ");
		c.add(la1, FlowLayout.CENTER);
		JTextField text1 = new JTextField(10);
		c.add(text1, FlowLayout.CENTER);
		
		setSize(250,350);
		setVisible(true);
	}
	public static void main(String[] args) {
		new MoneyChanger();
	}
}
