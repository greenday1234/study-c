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

import Design.RoundedButton;
import OpenFile.OpenFile;
import library.save_Book;
import library.save_User;


public class Select_View extends OpenFile {   
   private static JFrame SelectFrame;
   static ImageIcon borrowImage = new ImageIcon("image/BorrowBook5.png");
   static ImageIcon returnImage = new ImageIcon("image/Return_Book3.png");
   static ImageIcon UserImage = new ImageIcon("image/User2.png");
   static ImageIcon BookImage = new ImageIcon("image/Book2.png");
   static ImageIcon SaveImage = new ImageIcon("image/save2.png");
   public static void Select_View() {
      
      SelectFrame = new JFrame("도서 관리 시스템(관리자)");
      SelectFrame.getContentPane().setLayout(new FlowLayout(FlowLayout.CENTER, 10 ,50));
      SelectFrame.setBounds(560,200,450,350);
      SelectFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      SelectFrame.getContentPane().setBackground(new Color(180,230,180));
      SelectFrame.setLocationRelativeTo(null);
      
      JLabel BorrowLabel = new JLabel(borrowImage);
      SelectFrame.add(BorrowLabel);
      
      RoundedButton BorrowBtn = new RoundedButton("도서 대여");
      BorrowBtn.setFont(new Font("굴림", Font.BOLD, 20));
      SelectFrame.add(BorrowBtn);
      BorrowBtn.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            SelectFrame.setVisible(false);
            Borrow_View.Borrow_View();
         }
      });
      JLabel ReturnLabel = new JLabel(returnImage);
      SelectFrame.add(ReturnLabel);
      
      RoundedButton ReturnBtn = new RoundedButton("도서 반납");
      BorrowBtn.add(ReturnBtn);
      SelectFrame.add(ReturnBtn);
      ReturnBtn.setFont(new Font("굴림", Font.BOLD, 20));
      ReturnBtn.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            SelectFrame.setVisible(false);
            Return_View.Return_View();
         }
      });
      JLabel UserLabel = new JLabel(UserImage);
      SelectFrame.add(UserLabel);
      RoundedButton UserBtn = new RoundedButton("사용자 관리");
      
      SelectFrame.add(UserBtn);
      UserBtn.setFont(new Font("굴림", Font.BOLD, 20));
      UserBtn.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            SelectFrame.setVisible(false);
            UserManagementMenu.UserManagementMenu();
         }
      });
      
      JLabel BookLabel = new JLabel(BookImage);
      SelectFrame.add(BookLabel);
      RoundedButton BookBtn = new RoundedButton("도서 관리");
      
      SelectFrame.add(BookBtn);
      BookBtn.setFont(new Font("굴림", Font.BOLD, 20));
      BookBtn.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            SelectFrame.setVisible(false);
            BookManagementMenu.BookManagementView();
         }
      });
      JLabel SaveLabel = new JLabel(SaveImage);
      SelectFrame.add(SaveLabel);
      RoundedButton ExitBtn = new RoundedButton("SAVE");
      
      SelectFrame.add(ExitBtn);
      ExitBtn.setFont(new Font("굴림", Font.BOLD, 20));
      ExitBtn.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            save_Book sb = new save_Book(f2,mb.hashbook);
            save_User su = new save_User(f,mu.hashuser);
            JOptionPane.showMessageDialog(null,"저장이 완료되었습니다.");
         }
      });
      SelectFrame.setVisible(true);
   }
   
   public static JFrame getFrame() {
      return SelectFrame;
   }
}