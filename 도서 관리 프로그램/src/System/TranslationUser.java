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

public class TranslationUser extends OpenFile {
		private static JTable TranlataionUserTable;
		private static JScrollPane TranlationUserJScroll;
		private static JFrame TranlataionUserFrame;
		
	public static void TranslationUser(JFrame Frame) {
		
		TranlataionUserFrame = new JFrame("사용자 목록");
		TranlataionUserFrame.setVisible(true);
		TranlataionUserFrame.setBounds(560,200,700,550);
		TranlataionUserFrame.getContentPane().setLayout(null);
		TranlataionUserFrame.setLocationRelativeTo(null);
		TranlataionUserFrame.getContentPane().setBackground(new Color(180,230,180));
		
		RoundedButton BackBtn = new RoundedButton("Back");
		BackBtn.setFont(new Font("굴림", Font.BOLD, 20));
		BackBtn.setBounds(20,10,80,45);
		TranlataionUserFrame.getContentPane().add(BackBtn);
		BackBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				TranlataionUserFrame.setVisible(false);
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
		 TranlataionUserTable = new JTable(contents, header);
		 TranlataionUserTable.setPreferredScrollableViewportSize(new Dimension(500,50));
		 TranlataionUserTable.setFillsViewportHeight(true);
		 
	        TableColumnModel columnModels = TranlataionUserTable.getColumnModel();
	        columnModels.getColumn(0).setPreferredWidth(5);
	        columnModels.getColumn(1).setPreferredWidth(5);
	        columnModels.getColumn(2).setPreferredWidth(20);
	        columnModels.getColumn(3).setPreferredWidth(200);
	        columnModels.getColumn(4).setPreferredWidth(5);
	        TranlationUserJScroll = new JScrollPane(TranlataionUserTable);
	        TranlataionUserTable.getColumnModel().getColumn(4).setCellRenderer(new TableCell("수정", TranlataionUserTable, mu.hashuser, mb.hashbook, TranlataionUserFrame));;
	        TranlataionUserTable.getColumnModel().getColumn(4).setCellEditor(new TableCell("수정", TranlataionUserTable, mu.hashuser, mb.hashbook, TranlataionUserFrame));;		      
	        TranlationUserJScroll.setLocation(18,80);
	        TranlationUserJScroll.setSize(650,400);
	        TranlataionUserFrame.getContentPane().add(TranlationUserJScroll);
	}
	
	
	}

