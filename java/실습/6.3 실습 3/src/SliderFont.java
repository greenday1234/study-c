import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JSlider;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class SliderFont extends JFrame{
	private JSlider slider = new JSlider(1,100,50);
	private JLabel label = new JLabel("  I Love Java  ");
	public SliderFont() {
		super("Slider Font Change");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new BorderLayout());
		
		c.add(slider, BorderLayout.NORTH);
		c.add(label, BorderLayout.CENTER);
		
		slider.setMajorTickSpacing(20);
		slider.setMinorTickSpacing(5);
		slider.setPaintLabels(true);
		slider.setPaintTicks(true);
		
		label.setHorizontalAlignment(JLabel.CENTER);
		label.setOpaque(true);
		label.setFont(new Font("TimesRoman", Font.PLAIN, slider.getValue()));
		
		slider.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				JSlider s = (JSlider)e.getSource();
				label.setFont(new Font("TimeRoman", Font.PLAIN, s.getValue()));
			}
		});
		
		setSize(300,300);
		setVisible(true);
	}
	public static void main(String[] args) {
		new SliderFont();
	}
}
