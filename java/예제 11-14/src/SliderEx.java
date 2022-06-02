import java.awt.Container;
import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JSlider;

public class SliderEx extends JFrame{
	
	public SliderEx() {
		super("슬라이더 만들기 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		
		JSlider slider = new JSlider(JSlider.HORIZONTAL, 0, 200, 100);
		slider.setPaintLabels(true);	//바 아래의 레이블 표시
		slider.setPaintTicks(true);	//바 아래의 선 표시
		slider.setPaintTrack(true);
		slider.setMajorTickSpacing(50);	//선 표시 (길게)
		slider.setMinorTickSpacing(10);	//선 표시 (짧게)
		c.add(slider);
		
		setSize(300,300);
		setVisible(true);
	}

	public static void main(String[] args) {
		new SliderEx();
	}
}
