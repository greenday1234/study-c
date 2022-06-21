import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;

public class ButtonEx extends JFrame{

	public ButtonEx() {
		super("이미지 버튼 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		ImageIcon normalIcon = new ImageIcon("test.png");
		ImageIcon rolloverIcon = new ImageIcon("test1.png");
		ImageIcon pressedIcon = new ImageIcon("test.png");
		
		JButton btn = new JButton("call~~", normalIcon);
		btn.setPressedIcon(pressedIcon);
		btn.setRolloverIcon(rolloverIcon);
		
		c.add(btn);
		
		setSize(400,300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ButtonEx();
	}
}
