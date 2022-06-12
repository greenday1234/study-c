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
import library.managementUser;

public class Edit extends OpenFile{
	private static JFrame EditFrame;
	
	public static void Edit(String EditUserNumber,String EditUserPhoneNumber, String EditUserAddress,String EditUserName) {
		EditFrame = new JFrame("사용자 수정");

		EditFrame.setBounds(560, 200, 520, 400);
		EditFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		EditFrame.getContentPane().setLayout(null);
		EditFrame.getContentPane().setBackground(new Color(180,230,180));
		EditFrame.setLocationRelativeTo(null);

		JLabel lblName = new JLabel("이름");
		EditFrame.add(lblName);
		lblName.setBounds(50, 65, 100, 40);
		lblName.setFont(new Font("굴림", Font.BOLD, 20));
		EditFrame.getContentPane().add(lblName);

		RoundJTextField UserName = new RoundJTextField(EditUserNumber);
		UserName.setBounds(160, 65, 330, 40);
		EditFrame.add(UserName);
		UserName.setColumns(10);
		// 책 저자 입력칸
		
		JLabel lblAddress = new JLabel("주소");
		EditFrame.add(lblAddress);
		lblAddress.setBounds(50, 115, 100, 40);
		EditFrame.getContentPane().add(lblAddress);
		lblAddress.setFont(new Font("굴림", Font.BOLD, 20));
		EditFrame.setLayout(null);

		RoundJTextField UserAddress = new RoundJTextField(EditUserPhoneNumber);
		UserAddress.setBounds(160, 115, 330, 40);
		EditFrame.add(UserAddress);
		UserAddress.setColumns(10);
		// 책 청구기호 입력칸
		
		
		JLabel lblUserPhoneNumber = new JLabel("전화번호");
		EditFrame.add(lblUserPhoneNumber);
		lblUserPhoneNumber.setBounds(50, 165, 100, 40);
		EditFrame.getContentPane().add(lblUserPhoneNumber);
		lblUserPhoneNumber.setFont(new Font("굴림", Font.BOLD, 20));
		EditFrame.setLayout(null);

		RoundJTextField UserPhoneNumber = new RoundJTextField(EditUserAddress);
		UserPhoneNumber.setBounds(160, 165, 330, 40);
		EditFrame.add(UserPhoneNumber);
		UserPhoneNumber.setColumns(10);
		
		JLabel lblUserNumber = new JLabel("고유번호");
		EditFrame.add(lblUserNumber);
		lblUserNumber.setBounds(50, 215, 100, 40);
		EditFrame.getContentPane().add(lblUserNumber);
		lblUserNumber.setFont(new Font("굴림", Font.BOLD, 20));
		EditFrame.setLayout(null);

		RoundJTextField UserNumber = new RoundJTextField(EditUserName);
		UserNumber.setBounds(160, 215, 330, 40);
		EditFrame.add(UserNumber);
		UserNumber.setColumns(10);
		
		RoundedButton btn = new RoundedButton("수정");
		btn.setBounds(195, 280, 150, 50);
		btn.setFont(new Font("굴림", Font.BOLD, 20));
		EditFrame.getContentPane().add(btn);
		
		btn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(btn.getText().equals("수정")) {	
					String name = UserName.getText().trim();
					String address = UserAddress.getText().trim();
					String phoneNumber = UserPhoneNumber.getText().trim();
					String number = UserNumber.getText().trim();
					
					managementUser m2u = new managementUser();
					m2u.editUser(mu.hashuser, name,address,phoneNumber,number); 
					JOptionPane.showMessageDialog(null, "수정 성공!!");
					EditFrame.setVisible(false);
					Select_View.getFrame().setVisible(true);
					
				}
			}	
		});		
		
		RoundedButton BackBtn = new RoundedButton("Back");
		BackBtn.setFont(new Font("굴림", Font.BOLD, 20));
		BackBtn.setBounds(20,10,80,45);
		EditFrame.getContentPane().add(BackBtn);
		BackBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				EditFrame.setVisible(false);
				Select_View.getFrame().setVisible(true);
			}
		});
		
		EditFrame.setVisible(true);
	}
}
