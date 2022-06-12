package System;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;

import Design.RoundJTextField;
import Design.RoundedButton;
import OpenFile.OpenFile;

public class Borrow_View extends OpenFile {
		public static JFrame BorrowFrame;
		public static RoundJTextField BorrowUserSearchField;
		
	public static void Borrow_View() {
		BorrowFrame = new JFrame("´ë¿© ½Ã½ºÅÛ");
		BorrowFrame.setBounds(560,200,800,640);
		BorrowFrame.getContentPane().setLayout(null);
		BorrowFrame.getContentPane().setBackground(new Color(180,230,180));
		BorrowFrame.setLocationRelativeTo(null);
		
		JLabel UserSearchlabel = new JLabel("»ç¿ëÀÚ ÀÌ¸§");
		UserSearchlabel.setBounds(40,65,115,45);
		UserSearchlabel.setFont(new Font("±¼¸²", Font.BOLD, 20));
		BorrowFrame.getContentPane().add(UserSearchlabel);
		
		BorrowUserSearchField = new RoundJTextField("");
		BorrowUserSearchField.setBounds(185,65,415,45);
		BorrowUserSearchField.setFont(new Font("±¼¸²", Font.BOLD, 20));
		BorrowFrame.getContentPane().add(BorrowUserSearchField);
		BorrowUserSearchField.setColumns(10);
		BorrowUserSearchField.setFocusable(true);
		BorrowUserSearchField.requestFocus();
		
		RoundedButton UserSearchBtn = new RoundedButton("°Ë»ö");
		UserSearchBtn.setFont(new Font("±¼¸²", Font.BOLD, 20));
		UserSearchBtn.setBounds(650,65,100,45);
		BorrowFrame.getContentPane().add(UserSearchBtn);
		UserSearchBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BorrowUserTable_View.BorrowUserTable_View(BorrowFrame);
			}
		});
		
		RoundedButton UserBackBtn = new RoundedButton("Back");
		UserBackBtn.setFont(new Font("±¼¸²", Font.BOLD, 20));
		UserBackBtn.setBounds(20,10,80,45);
		BorrowFrame.getContentPane().add(UserBackBtn);
		UserBackBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BorrowFrame.setVisible(false);
				Select_View.getFrame().setVisible(true);
			}
		});
		BorrowFrame.setVisible(true);
	}
	public static String getBorrowUserSearchField() {
		return	BorrowUserSearchField.getText();
	}
	
}
