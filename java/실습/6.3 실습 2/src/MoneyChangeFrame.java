import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class MoneyChangeFrame extends JFrame{

	public MoneyChangeFrame() {
		super("Money Changer");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		
		c.add(new MyPanel());
		
		
		setSize(300,300);
		setVisible(true);
	}
	
	class MyPanel extends JPanel{
		private JTextField source;	//사용자가 직접 입력할 필드
		private JTextField [] tf = new JTextField[8];	//환산된 돈의 수량을 출력할 필드
		
		private int [] unit = {50000,10000,1000,500,100,10,1};	//환산할 돈의 종류
		private String[] text = {"오만원", "만원", "천원", "오백원", "백원", "십원", "일원"};
 		
		public MyPanel() {
			this.setBackground(Color.PINK);
			this.setLayout(null);	//위치는 좌표로 직접 설정
			
			//금액 레이블
			JLabel la = new JLabel("금액");
			la.setHorizontalAlignment(JLabel.RIGHT);	//정렬
			la.setSize(50,20);
			la.setLocation(20,20);
			this.add(la);
			
			//금액을 입력하는 필드
			source = new JTextField(30);
			source.setSize(100,20);
			source.setLocation(100,20);
			this.add(source);
			
			//계산 버튼
			JButton calbtn = new JButton("계산");
			calbtn.setSize(70,20);
			calbtn.setLocation(210,20);
			this.add(calbtn);
			
			//계산 결과 필드
			for(int i=0;i<text.length;i++) {
				la = new JLabel(text[i]);
				la.setHorizontalAlignment(JLabel.RIGHT);
				la.setSize(50,20);
				la.setLocation(50,50+i*20);
				this.add(la);
				
				tf[i] = new JTextField(30);
				tf[i].setHorizontalAlignment(JTextField.CENTER);
				tf[i].setSize(70,20);
				tf[i].setLocation(120,50+i*20);
				this.add(tf[i]);
			}
			calbtn.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					String str = source.getText();
					if(str.length() == 0)
						return;
					int money = Integer.parseInt(str);
					int res;
					for(int i=0;i<unit.length;i++) {
						res = money / unit[i];
						tf[i].setText(Integer.toString(res));
						if(res > 0)
							money = money % unit[i];
					}
					
				}
			});
			
		}
	}
	public static void main(String[] args) {
		new MoneyChangeFrame();
	}
}
