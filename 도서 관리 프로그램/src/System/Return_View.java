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

public class Return_View {
		private static JFrame ReturnFrame;
		private static RoundJTextField ReturnBookSearchField;
	
	public static void Return_View() {
		ReturnFrame = new JFrame("¹Ý³³ ½Ã½ºÅÛ");
		ReturnFrame.setBounds(560,200,800,640);
		ReturnFrame.getContentPane().setLayout(null);
		ReturnFrame.setVisible(true);
		ReturnFrame.getContentPane().setBackground(new Color(180,230,180));
		
		JLabel ReturnBookSearchlabel = new JLabel("µµ¼­ ÀÌ¸§");
		ReturnBookSearchlabel.setBounds(40,65,115,45);
		ReturnBookSearchlabel.setFont(new Font("±¼¸²", Font.BOLD, 20));
		ReturnFrame.getContentPane().add(ReturnBookSearchlabel);
		
		ReturnBookSearchField = new RoundJTextField("");
		ReturnBookSearchField.setBounds(185,65,415,45);
		ReturnBookSearchField.setFont(new Font("±¼¸²", Font.BOLD, 20));
		ReturnFrame.getContentPane().add(ReturnBookSearchField);
		ReturnBookSearchField.setColumns(10);
		
		RoundedButton BookSearchBtn = new RoundedButton("°Ë»ö");
		BookSearchBtn.setFont(new Font("±¼¸²", Font.BOLD, 20));
		BookSearchBtn.setBounds(650,65,100,45);
		ReturnFrame.getContentPane().add(BookSearchBtn);
		BookSearchBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ReturnBookTable_View.ReturnBookTable_View();
			}
		});
		
		RoundedButton ReturnBackBtn = new RoundedButton("Back");
		ReturnBackBtn.setFont(new Font("±¼¸²", Font.BOLD, 20));
		ReturnBackBtn.setBounds(20,10,80,45);
		ReturnFrame.getContentPane().add(ReturnBackBtn);
		ReturnBackBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ReturnFrame.setVisible(false);
				Select_View.getFrame().setVisible(true);
			}
		});
	}
	public static String getReturnBookSearchField() {
		return ReturnBookSearchField.getText();
	}
	public static JFrame getReturn_ViewFrame() {
		return ReturnFrame;
	}
	}
