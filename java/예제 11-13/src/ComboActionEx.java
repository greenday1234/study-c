import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class ComboActionEx extends JFrame{
	private String[] fruits = {"apple", "banana", "kiwi", "mango"};
	
	private ImageIcon[] images = { new ImageIcon("test.png"), new ImageIcon("test1.png")
			, new ImageIcon("test2.png"), new ImageIcon("test.png")};
	
	private JLabel imageLabel = new JLabel();	//새로 넣을 레이블
	private JComboBox<String> strcombo = new JComboBox<String>(fruits);
	
	public ComboActionEx() {
		super("콤보박스 활용 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		c.add(strcombo);
		c.add(imageLabel);
		
		strcombo.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JComboBox<String> cb = (JComboBox<String>)e.getSource();
				int index = cb.getSelectedIndex();
				imageLabel.setIcon(images[index]);
			}
		});
		
		setSize(300,300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ComboActionEx();
	}
}
