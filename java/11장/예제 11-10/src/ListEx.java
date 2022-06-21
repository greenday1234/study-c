import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JScrollPane;

public class ListEx extends JFrame{
	private String[] fruits = {"apple", "banana", "kiwi", "mango", "pear", "peach", "berry", "strawberry",
			"blackberry"};
	
	private ImageIcon[] images = {new ImageIcon("test.png"), new ImageIcon("test1.png"),
			new ImageIcon("test2.png"), new ImageIcon("test1.png")};
	
	public ListEx() {
		super("리스트 만들기 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JList<String> strList = new JList<String>(fruits);
		c.add(strList);
		
		JList<ImageIcon> imageList = new JList<ImageIcon>();
		imageList.setListData(images);
		c.add(imageList);
		
		JList<String> scrollList = new JList<String>(fruits);
		c.add(new JScrollPane(scrollList));
		
		setSize(1000,1000);
		setVisible(true);
	}
	public static void main(String[] args) {
		new ListEx();
	}
}
