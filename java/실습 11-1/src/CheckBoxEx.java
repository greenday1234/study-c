import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;

public class CheckBoxEx extends JFrame{
	private JCheckBox [] cb = new JCheckBox [2];
	
	public CheckBoxEx() {
		super("ChecoBox Practice Frame");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		cb[0] = new JCheckBox("버튼 비활성화");
		cb[1] = new JCheckBox("버튼 감추기");
		
		JButton btn = new JButton("test button");
		c.add(cb[0]);
		c.add(cb[1]);
		c.add(btn);
		
		cb[0].addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				if(e.getStateChange() == e.SELECTED)
				btn.setEnabled(false);
				else
					btn.setEnabled(true);
			}
		});
		
		cb[1].addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent e) {
				if(e.getStateChange() == e.SELECTED)
				btn.setVisible(false);
				else
					btn.setVisible(true);
			}
		});
		
		setSize(300,300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new CheckBoxEx();
	}
}
