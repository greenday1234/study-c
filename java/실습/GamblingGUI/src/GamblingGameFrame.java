import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

public class GamblingGameFrame extends JFrame{
   JLabel f, s, t, txt;
   public GamblingGameFrame() {
      super("Open Chanllenge");
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      
      Container c = getContentPane();
      c.setLayout(null);
      
      c.addKeyListener(new MyKeyAdapter());
      
      f = new JLabel((int)(Math.random()*5)+"",SwingConstants.CENTER);
      s = new JLabel((int)(Math.random()*5)+"",SwingConstants.CENTER);
      t = new JLabel((int)(Math.random()*5)+"",SwingConstants.CENTER);
      txt = new JLabel("시작합니다.",SwingConstants.CENTER);
      
      f.setBackground(Color.MAGENTA);
      f.setForeground(Color.yellow);
      f.setSize(100,50);
      f.setLocation(40,80);
      f.setFont(new Font("Tahoma",Font.ITALIC,30));
      f.setOpaque(true);
      
      s.setBackground(Color.MAGENTA);
      s.setForeground(Color.yellow);
      s.setSize(100,50);
      s.setLocation(180,80);
      s.setFont(new Font("Tahoma",Font.ITALIC,30));
      s.setOpaque(true);
      
      t.setBackground(Color.MAGENTA);
      t.setForeground(Color.yellow);
      t.setSize(100,50);
      t.setLocation(320,80);
      t.setFont(new Font("Tahoma",Font.ITALIC,30));
      t.setOpaque(true);
      
      txt.setSize(300,50);
      txt.setLocation(80,150);
      
      c.add(f);
      c.add(s);
      c.add(t);
      c.add(txt);
      
      c.setFocusable(true);
      c.requestFocus();
      
      setSize(500,300);
      setVisible(true);
   }
   class MyKeyAdapter extends KeyAdapter{
      public void keyPressed(KeyEvent e) {
         if(e.getKeyChar() == '\n') {
            f.setText((int)(Math.random()*5)+"");
            s.setText((int)(Math.random()*5)+"");
            t.setText((int)(Math.random()*5)+"");
            if(f.getText().equals(s.getText())) {
               if(s.getText().equals(t.getText())) {
                  txt.setText("축하합니다!");
               }
               else
                  txt.setText("아쉽네요");
            }
            else
               txt.setText("아쉽네요");         
         }
      }
   }
   public static void main(String[] args) {
      // TODO Auto-generated method stub
      new GamblingGameFrame();
   }
}