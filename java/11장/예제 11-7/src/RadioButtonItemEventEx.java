import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.SwingConstants;

public class RadioButtonItemEventEx extends JFrame{
	private JRadioButton [] radio = new JRadioButton[3];
	private String[] text = {"사과", "배", "체리"};
	private ImageIcon[] image = {new ImageIcon("test.png"), new ImageIcon("test1.png"), new ImageIcon(
			"test2.png")};
	private JLabel imageLabel = new JLabel();	//새로 이미지가 들어갈 레이블
	
	public RadioButtonItemEventEx() {
		super("라디오버튼 Item Event 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JPanel radioPanel = new JPanel();
		radioPanel.setBackground(Color.GRAY);
		
		ButtonGroup g = new ButtonGroup();
		
		for(int i=0;i<radio.length;i++) {
			radio[i] = new JRadioButton(text[i]);
			g.add(radio[i]);
			radioPanel.add(radio[i]);
			radio[i].addItemListener(new MyItemListener());
		}
		
		c.add(radioPanel, BorderLayout.NORTH);
		c.add(imageLabel, BorderLayout.CENTER);
		
		setSize(300,200);
		setVisible(true);
	}
	
	class MyItemListener implements ItemListener{
		public void itemStateChanged(ItemEvent e) {
			
			if(radio[0].isSelected())
				imageLabel.setIcon(image[0]);
			else if(radio[1].isSelected())
				imageLabel.setIcon(image[1]);
			else
				imageLabel.setIcon(image[2]);
		}
	}
	public static void main(String[] args) {
		new RadioButtonItemEventEx();
	}
}
