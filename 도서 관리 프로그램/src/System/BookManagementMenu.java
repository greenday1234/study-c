package System;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

import Design.RoundedButton;

public class BookManagementMenu {
	private static JFrame BookManagementFrame;
	public static void BookManagementView() {	
		BookManagementFrame = new JFrame("도서 관리");
		BookManagementFrame.setBounds(560,200,300,300);
		BookManagementFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		BookManagementFrame.getContentPane().setLayout(null);
		BookManagementFrame.setVisible(true);
		BookManagementFrame.setLocationRelativeTo(null);
		BookManagementFrame.getContentPane().setBackground(new Color(180,230,180));
		
		RoundedButton plusBtn = new RoundedButton("추가");
		plusBtn.setBounds(40,100,80,80);
		plusBtn.setFont(new Font("굴림", Font.BOLD, 20));
		BookManagementFrame.getContentPane().add(plusBtn);
		
		plusBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BookManagementFrame.setVisible(false);
				PlusBook.PlusBook();
			}
		});
		
		RoundedButton deleteBtn = new RoundedButton("삭제");
		deleteBtn.setBounds(160,100,80,80);
		deleteBtn.setFont(new Font("굴림", Font.BOLD, 20));
		BookManagementFrame.getContentPane().add(deleteBtn);
		
		deleteBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BookManagementFrame.setVisible(false);
				DeleteBook.DeleteBook(BookManagementFrame); // 삭제
			}
		});
		
		RoundedButton UserBackBtn = new RoundedButton("Back");
		UserBackBtn.setFont(new Font("굴림", Font.BOLD, 20));
		UserBackBtn.setBounds(20,10,80,45);
		BookManagementFrame.getContentPane().add(UserBackBtn);
		UserBackBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				BookManagementFrame.setVisible(false);
				Select_View.getFrame().setVisible(true);
			}
		});
	}	
}
