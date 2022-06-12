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
		PlusFrame = new JFrame("����� �߰�");
		PlusFrame.setBounds(560, 200, 520, 400);
		PlusFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		PlusFrame.getContentPane().setLayout(null);
		PlusFrame.setLocationRelativeTo(null);
		PlusFrame.getContentPane().setBackground(new Color(180,230,180));

		JLabel lblName = new JLabel("�̸�");
		PlusFrame.add(lblName);
		lblName.setBounds(50, 65, 100, 40);
		lblName.setFont(new Font("����", Font.BOLD, 20));
		PlusFrame.getContentPane().add(lblName);

		RoundJTextField UserName = new RoundJTextField("");
		UserName.setBounds(160, 65, 330, 40);
		PlusFrame.add(UserName);
		UserName.setColumns(10);
		// å ���� �Է�ĭ
		
		JLabel lblAddress = new JLabel("�ּ�");
		PlusFrame.add(lblAddress);
		lblAddress.setBounds(50, 115, 100, 40);
		PlusFrame.getContentPane().add(lblAddress);
		lblAddress.setFont(new Font("����", Font.BOLD, 20));

		RoundJTextField UserAddress = new RoundJTextField("");
		UserAddress.setBounds(160, 115, 330, 40);
		PlusFrame.add(UserAddress);
		UserAddress.setColumns(10);
		// å û����ȣ �Է�ĭ
		
		
		JLabel lblUserPhoneNumber = new JLabel("��ȭ��ȣ");
		PlusFrame.add(lblUserPhoneNumber);
		lblUserPhoneNumber.setBounds(50, 165, 100, 40);
		PlusFrame.getContentPane().add(lblUserPhoneNumber);
		lblUserPhoneNumber.setFont(new Font("����", Font.BOLD, 20));

		RoundJTextField UserPhoneNumber = new RoundJTextField("");
		UserPhoneNumber.setBounds(160, 165, 330, 40);
		PlusFrame.add(UserPhoneNumber);
		UserPhoneNumber.setColumns(10);
		
		JLabel lblUserNumber = new JLabel("������ȣ");
		PlusFrame.add(lblUserNumber);
		lblUserNumber.setBounds(50, 215, 100, 40);
		PlusFrame.getContentPane().add(lblUserNumber);
		lblUserNumber.setFont(new Font("����", Font.BOLD, 20));

		RoundJTextField UserNumber = new RoundJTextField("");
		UserNumber.setBounds(160, 215, 330, 40);
		PlusFrame.add(UserNumber);
		UserNumber.setColumns(10);
		
		RoundedButton btn = new RoundedButton("�߰�");
		btn.setBounds(195, 280, 150, 50);
		btn.setFont(new Font("����", Font.BOLD, 20));
		PlusFrame.getContentPane().add(btn);
	
		btn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(btn.getText().equals("�߰�")) {
					plusUserName = UserName.getText().trim();
					plusUserAddress = UserAddress.getText().trim();
					plusUserPhoneNumber = UserPhoneNumber.getText().trim();
					plusUserNumber = UserNumber.getText().trim();
									
					if(mu.hashuser.containsKey(plusUserNumber)==true) {
						JOptionPane.showMessageDialog(null, "�߰� ����!!");
						UserName.setText("");
						UserAddress.setText("");
						UserPhoneNumber.setText("");
						UserNumber.setText("");
					}
					else {
						JOptionPane.showMessageDialog(null, "�߰� ����!!");
						managementUser m2u = new managementUser();
						m2u.addUser(mu.hashuser, plusUserName,plusUserAddress,plusUserPhoneNumber,plusUserNumber);
						//mu.hashuser.put(plusUserNumber, new User(plusUserName, plusUserAddress, plusUserPhoneNumber, plusUserNumber," "," "," ")); // �ؽ��ʿ� put �Ϸ�
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
		BackBtn.setFont(new Font("����", Font.BOLD, 20));
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
