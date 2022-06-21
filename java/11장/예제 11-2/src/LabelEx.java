import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

public class LabelEx extends JFrame{

	public LabelEx() {
		super("레이블 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		
		c.setLayout(new FlowLayout());
		
		JLabel textlabel = new JLabel("사랑합니다.");
		
		ImageIcon beauty = new ImageIcon("test.png");
		JLabel imagelabel = new JLabel(beauty);
		
		ImageIcon normalIcon = new ImageIcon("test1.png");
		JLabel label = new JLabel("보고싶으면 전화하세요", normalIcon, SwingConstants.CENTER);
		
		c.add(textlabel);
		c.add(imagelabel);
		c.add(label);
		
		setSize(300,600);
		setVisible(true);
		}
	public static void main(String[] args) {
		new LabelEx();
	}
}
