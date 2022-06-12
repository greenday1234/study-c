package System;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import Design.RoundJTextField;
import Design.RoundedButton;
import OpenFile.OpenFile;
import library.managementBook;

public class PlusBook extends OpenFile{
	private static JFrame PlusFrame;
	private static String plusBookISBN;
	private static String plusBookTitle;
	private static String plusBookAuthor;
	private static String plusBookRent; 
	
	public static void PlusBook() {
		PlusFrame = new JFrame("도서 추가");
		PlusFrame.setBounds(560, 200, 450, 350);
		PlusFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		PlusFrame.getContentPane().setBackground(new Color(180,230,180));
		PlusFrame.getContentPane().setLayout(null);
		PlusFrame.setLocationRelativeTo(null);

		// 책 제목 입력칸
		JLabel lblName = new JLabel("책 제목");
		PlusFrame.add(lblName);
		lblName.setBounds(50, 65, 100, 40);
		lblName.setFont(new Font("굴림", Font.BOLD, 20));
		PlusFrame.getContentPane().add(lblName);

		RoundJTextField BookTitle = new RoundJTextField("");
		BookTitle.setBounds(160, 65, 200, 40);
		PlusFrame.add(BookTitle);
		BookTitle.setColumns(10);
		
		// 책 저자 입력칸
		JLabel lblAddress = new JLabel("저자");
		PlusFrame.add(lblAddress);
		lblAddress.setBounds(50, 115, 100, 40);
		PlusFrame.getContentPane().add(lblAddress);
		lblAddress.setFont(new Font("굴림", Font.BOLD, 20));

		RoundJTextField BookAuthor = new RoundJTextField("");
		BookAuthor.setBounds(160, 115, 200, 40);
		PlusFrame.add(BookAuthor);
		BookAuthor.setColumns(10);
		
		// 책 청구기호 입력칸
		JLabel lblUserPhoneNumber = new JLabel("청구기호");
		PlusFrame.add(lblUserPhoneNumber);
		lblUserPhoneNumber.setBounds(50, 165, 100, 40);
		PlusFrame.getContentPane().add(lblUserPhoneNumber);
		lblUserPhoneNumber.setFont(new Font("굴림", Font.BOLD, 20));

		RoundJTextField BookISBN = new RoundJTextField("");
		BookISBN.setBounds(160, 165, 200, 40);
		PlusFrame.add(BookISBN);
		BookISBN.setColumns(10);
		
		RoundedButton btn = new RoundedButton("추가");
		btn.setBounds(150, 230, 150, 50);
		btn.setFont(new Font("굴림", Font.BOLD, 20));
		PlusFrame.getContentPane().add(btn);
	
		btn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(btn.getText().equals("추가")) {
					plusBookTitle = BookTitle.getText().trim();
					plusBookAuthor = BookAuthor.getText().trim();
					plusBookISBN = BookISBN.getText().trim();
					plusBookRent = "대여가능";
									
					if(mb.hashbook.containsKey(plusBookISBN)==true) {
						JOptionPane.showMessageDialog(null, "추가 실패!!");
						BookTitle.setText("");
						BookAuthor.setText("");
						BookISBN.setText("");
					}
					else {
						JOptionPane.showMessageDialog(null, "추가 성공!!");
						managementBook m2b = new managementBook();
						m2b.addBook(mb.hashbook,  plusBookTitle, plusBookAuthor,plusBookISBN);
						//mb.hashbook.put(plusBookISBN, new Book(plusBookTitle, plusBookAuthor, plusBookISBN, plusBookRent," ")); // 해쉬맵에 put 완료
						BookTitle.setText("");
						BookAuthor.setText("");
						BookISBN.setText("");					
						}
				}
			}	
		});		
		
		RoundedButton BackBtn = new RoundedButton("Back");
		BackBtn.setFont(new Font("굴림", Font.BOLD, 20));
		BackBtn.setBounds(20,10,80,45);
		PlusFrame.getContentPane().add(BackBtn);
		BackBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				PlusFrame.setVisible(false);
				Select_View.getFrame().setVisible(true);
			}
		});
		
		PlusFrame.setVisible(true);
	}
}
