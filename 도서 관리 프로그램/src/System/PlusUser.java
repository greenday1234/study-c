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

public class PlusUser extends OpenFile{
	private static JFrame PlusFrame;
	private static String plusUserName;
	private static String plusUserAddress;
	private static String plusUserPhoneNumber;
	private static String plusUserNumber;
	public static void PlusUser() {
		PlusFrame = new JFrame("사용자 추가");
		PlusFrame.setBounds(560, 200, 520, 400);
		PlusFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		PlusFrame.getContentPane().setLayout(null);
		PlusFrame.setLocationRelativeTo(null);
		PlusFrame.getContentPane().setBackground(new Color(180,230,180));

		JLabel lblName = new JLabel("이름");
		PlusFrame.add(lblName);
		lblName.setBounds(50, 65, 100, 40);
		lblName.setFont(new Font("굴림", Font.BOLD, 20));
		PlusFrame.getContentPane().add(lblName);

		RoundJTextField UserName = new RoundJTextField("");
		UserName.setBounds(160, 65, 330, 40);
		PlusFrame.add(UserName);
		UserName.setColumns(10);
		// 책 저자 입력칸
		
		JLabel lblAddress = new JLabel("주소");
		PlusFrame.add(lblAddress);
		lblAddress.setBounds(50, 115, 100, 40);
		PlusFrame.getContentPane().add(lblAddress);
		lblAddress.setFont(new Font("굴림", Font.BOLD, 20));

		RoundJTextField UserAddress = new RoundJTextField("");
		UserAddress.setBounds(160, 115, 330, 40);
		PlusFrame.add(UserAddress);
		UserAddress.setColumns(10);
		// 책 청구기호 입력칸
		
		
		JLabel lblUserPhoneNumber = new JLabel("전화번호");
		PlusFrame.add(lblUserPhoneNumber);
		lblUserPhoneNumber.setBounds(50, 165, 100, 40);
		PlusFrame.getContentPane().add(lblUserPhoneNumber);
		lblUserPhoneNumber.setFont(new Font("굴림", Font.BOLD, 20));

		RoundJTextField UserPhoneNumber = new RoundJTextField("");
		UserPhoneNumber.setBounds(160, 165, 330, 40);
		PlusFrame.add(UserPhoneNumber);
		UserPhoneNumber.setColumns(10);
		
		JLabel lblUserNumber = new JLabel("고유번호");
		PlusFrame.add(lblUserNumber);
		lblUserNumber.setBounds(50, 215, 100, 40);
		PlusFrame.getContentPane().add(lblUserNumber);
		lblUserNumber.setFont(new Font("굴림", Font.BOLD, 20));

		RoundJTextField UserNumber = new RoundJTextField("");
		UserNumber.setBounds(160, 215, 330, 40);
		PlusFrame.add(UserNumber);
		UserNumber.setColumns(10);
		
		RoundedButton btn = new RoundedButton("추가");
		btn.setBounds(195, 280, 150, 50);
		btn.setFont(new Font("굴림", Font.BOLD, 20));
		PlusFrame.getContentPane().add(btn);
	
		btn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(btn.getText().equals("추가")) {
					plusUserName = UserName.getText().trim();
					plusUserAddress = UserAddress.getText().trim();
					plusUserPhoneNumber = UserPhoneNumber.getText().trim();
					plusUserNumber = UserNumber.getText().trim();
									
					if(mu.hashuser.containsKey(plusUserNumber)==true) {
						JOptionPane.showMessageDialog(null, "추가 실패!!");
						UserName.setText("");
						UserAddress.setText("");
						UserPhoneNumber.setText("");
						UserNumber.setText("");
					}
					else {
						JOptionPane.showMessageDialog(null, "추가 성공!!");
						managementUser m2u = new managementUser();
						m2u.addUser(mu.hashuser, plusUserName,plusUserAddress,plusUserPhoneNumber,plusUserNumber);
						//mu.hashuser.put(plusUserNumber, new User(plusUserName, plusUserAddress, plusUserPhoneNumber, plusUserNumber," "," "," ")); // 해쉬맵에 put 완료
						UserName.setText("");
						UserAddress.setText("");
						UserPhoneNumber.setText("");
						UserNumber.setText("");
						PlusFrame.setVisible(false);
						Select_View.Select_View();
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
