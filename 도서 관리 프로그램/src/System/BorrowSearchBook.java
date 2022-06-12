package System;
import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

import Design.RoundJTextField;
import Design.RoundedButton;
import OpenFile.OpenFile;
public class BorrowSearchBook extends OpenFile {
	private static JFrame BorrowBookFrame;
	public static RoundJTextField BorrowBookSearchField;
	public static void BorrowSearchBook(String UserNumber) {
		BorrowBookFrame = new JFrame("µµ¼­ °Ë»ö");
		BorrowBookFrame.setVisible(true);
		BorrowBookFrame.setBounds(560,200,800,640);
		BorrowBookFrame.getContentPane().setLayout(null);
		BorrowBookFrame.getContentPane().setBackground(new Color(180,230,180));
		BorrowBookFrame.setLocationRelativeTo(null);
		
		JLabel BookSearchlabel = new JLabel("µµ¼­ ÀÌ¸§");
		BookSearchlabel.setBounds(40,65,115,45);
		BookSearchlabel.setFont(new Font("±¼¸²", Font.BOLD, 20));
		BorrowBookFrame.getContentPane().add(BookSearchlabel);
		
		BorrowBookSearchField = new RoundJTextField("");
		BorrowBookSearchField.setBounds(185,65,415,45);
		BorrowBookSearchField.setFont(new Font("±¼¸²", Font.BOLD, 20));
		BorrowBookFrame.getContentPane().add(BorrowBookSearchField);
		BorrowBookSearchField.setColumns(10);
		
		RoundedButton BackBookBtn = new RoundedButton("Back");
		BackBookBtn.setFont(new Font("±¼¸²", Font.BOLD, 20));
		BackBookBtn.setBounds(20,10,80,45);
		BorrowBookFrame.getContentPane().add(BackBookBtn);
		BackBookBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BorrowBookFrame.setVisible(false);
				Select_View.getFrame().setVisible(true);
			}
		});
		
		RoundedButton BookSearchBtn = new RoundedButton("´ë¿©");
		BookSearchBtn.setFont(new Font("±¼¸²", Font.BOLD, 20));
		BookSearchBtn.setBounds(650,65,100,45);
		BorrowBookFrame.getContentPane().add(BookSearchBtn);
		BookSearchBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BorrowBookTable_View.BorrowBookTable_View(BorrowBookFrame, UserNumber);
			}
		});
	}
	public static String getBorrowBookSearchField() {
		return BorrowBookSearchField.getText();
	}
	
	public static JFrame getBorrowBookFrame() {
		return BorrowBookFrame;
	}
}
