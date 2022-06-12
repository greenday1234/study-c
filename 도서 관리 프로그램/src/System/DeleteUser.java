package System;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.TableColumnModel;

import Design.RoundedButton;
import OpenFile.OpenFile;
import TableCell.TableCell;
import library.User;

public class DeleteUser extends OpenFile {
		private static JTable DeleteUserTable;
		private static JScrollPane DeleteUserJScroll;
		private static JFrame DeleteUserFrame;
		
	public static void DeleteUser(JFrame Frame) {
		
		DeleteUserFrame = new JFrame("사용자 목록");
		DeleteUserFrame.setBounds(560,200,700,550);
		DeleteUserFrame.getContentPane().setLayout(null);
		DeleteUserFrame.getContentPane().setBackground(new Color(180,230,180));
		DeleteUserFrame.setLocationRelativeTo(null);
		
		RoundedButton BackBtn = new RoundedButton("Back");
		BackBtn.setFont(new Font("굴림", Font.BOLD, 20));
		BackBtn.setBounds(20,10,80,45);
		DeleteUserFrame.getContentPane().add(BackBtn);
		BackBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				DeleteUserFrame.setVisible(false);
				Select_View.getFrame().setVisible(true);
			}
		});
		
		HashMap<String, User> hu = mu.hashuser;
		String header[]={"회원번호", "이름", "전화번호", "주소", "선택"};
		String contents[][]=new String[hu.size()][5];
		Set<String> keys = hu.keySet();
		Iterator<String> it = keys.iterator();
		int findN=0;
		while (it.hasNext()) {
			String number = it.next();
			User us = hu.get(number);
				contents[findN][0]=us.getUserNumber();	
				contents[findN][1]=us.getName();
				contents[findN][2]=us.getPhoneNumber();
				contents[findN][3]=us.getAddress();
				findN++;
		}
		DeleteUserTable = new JTable(contents, header);
		DeleteUserTable.setPreferredScrollableViewportSize(new Dimension(500,50));
		DeleteUserTable.setFillsViewportHeight(true);
		 
	        TableColumnModel columnModels = DeleteUserTable.getColumnModel();
	        columnModels.getColumn(0).setPreferredWidth(5);
	        columnModels.getColumn(1).setPreferredWidth(5);
	        columnModels.getColumn(2).setPreferredWidth(20);
	        columnModels.getColumn(3).setPreferredWidth(200);
	        columnModels.getColumn(4).setPreferredWidth(5);
	        DeleteUserJScroll = new JScrollPane(DeleteUserTable);
	        DeleteUserTable.getColumnModel().getColumn(4).setCellRenderer(new TableCell("삭제", DeleteUserTable, mu.hashuser, mb.hashbook, DeleteUserFrame));;
	        DeleteUserTable.getColumnModel().getColumn(4).setCellEditor(new TableCell("삭제", DeleteUserTable, mu.hashuser, mb.hashbook, DeleteUserFrame));;		      
	        DeleteUserJScroll.setLocation(18,80);
	        DeleteUserJScroll.setSize(650,400);
	        DeleteUserFrame.getContentPane().add(DeleteUserJScroll);
	        
	        DeleteUserFrame.setVisible(true);
		}
	}

