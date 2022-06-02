import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JComboBox;
import javax.swing.JFrame;

public class ComboBoxEx extends JFrame{
	private String [] fruits = {"apple", "banana", "kiwi", "mango", "pear", "peach" ,"berry", 
			"strawberry", "nlackberry"};
	
	private String[] names = {"kitea", "jaemoon", "hyosoo", "namyun"};
	
	public ComboBoxEx() {
		super("콤보박스 만들기 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JComboBox<String> strCombo = new JComboBox<String>(fruits);
		c.add(strCombo);
		
		JComboBox<String> nameCombo = new JComboBox<String>(names);
		c.add(nameCombo);
		
		setSize(300,200);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ComboBoxEx();
	}
}
