package System;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.SwingConstants;

import Design.RoundJPasswordField;
import Design.RoundJTextField;
import Design.RoundedButton;

public class Login_View {
   private static JFrame LoginFrame;
   private static RoundJTextField IDField;
   private static RoundJPasswordField PasswordField;

   public Login_View() {
   LoginFrame = new JFrame("도서 관리 시스템(관리자)");
   LoginFrame.setBounds(560,200,400,300);
   LoginFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   LoginFrame.getContentPane().setLayout(new FlowLayout(FlowLayout.CENTER, 30, 10));
   LoginFrame.getContentPane().setBackground(new Color(180,230,180));
   LoginFrame.setLocationRelativeTo(null);
   
   ImageIcon LoginIcon = new ImageIcon("image/id.png");
   JLabel IDlabel = new JLabel(LoginIcon,SwingConstants.RIGHT);
   //IDlabel.setBounds(400,400,115,40);
   LoginFrame.getContentPane().add(IDlabel);
   
   IDField = new RoundJTextField("");
   //IDField.setBounds(530,400,190,40);
   IDField.setFont(new Font("굴림", Font.BOLD, 20));
   LoginFrame.getContentPane().add(IDField);
   IDField.setColumns(10);
   
   ImageIcon PassIcon = new ImageIcon("image/password.png");
   JLabel PWlabel = new JLabel(PassIcon,SwingConstants.RIGHT);
   //PWlabel.setBounds(400,460,115,40);
   LoginFrame.getContentPane().add(PWlabel);
   
   PasswordField = new RoundJPasswordField(0);
   //PasswordField.setBounds(530,460,190,40);
   PasswordField.setFont(new Font("굴림", Font.BOLD, 20));
   LoginFrame.getContentPane().add(PasswordField);
   PasswordField.setColumns(10);
   
   
   RoundedButton LoginBtn = new RoundedButton("Log in");
   //LoginBtn.setBounds(530,530,190,40);
   LoginBtn.setFont(new Font("굴림", Font.BOLD, 20));
   LoginFrame.getContentPane().add(LoginBtn);
     
   LoginBtn.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
         if(IDField.getText().equals("test") && PasswordField.getText().equals("1234")) {
        	 LoginFrame.setVisible(false);
        	 Select_View.Select_View();
         }
         else {
            JOptionPane.showMessageDialog(LoginFrame,"ID, 비밀번호를 다시 입력해주세요.");
         }
      }
   	});
   LoginFrame.setVisible(true);
   }
   
   public static void Login_View() {
      // TODO Auto-generated method stub
      new Login_View();
      
   }
}