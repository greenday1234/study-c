package System;
import java.awt.Dimension;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.TableColumnModel;

import OpenFile.OpenFile;
import TableCell.TableCell;
import library.User;

public class BorrowUserTable_View extends OpenFile {
		private static JTable BorrowUserTable;
		private static JScrollPane BorrowUserJScroll;
		private static String BorrowUserSearchFieldtext;
		
	public static void BorrowUserTable_View(JFrame BorrowFrame) {

		BorrowUserSearchFieldtext = Borrow_View.getBorrowUserSearchField();
		HashMap<String, User> hu = fu.findUserByName(BorrowUserSearchFieldtext);
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
		 BorrowUserTable = new JTable(contents, header);
		 BorrowUserTable.setPreferredScrollableViewportSize(new Dimension(500,50));
		 BorrowUserTable.setFillsViewportHeight(true);
		 
	        TableColumnModel columnModels = BorrowUserTable.getColumnModel();
	        columnModels.getColumn(0).setPreferredWidth(5);
	        columnModels.getColumn(1).setPreferredWidth(5);
	        columnModels.getColumn(2).setPreferredWidth(20);
	        columnModels.getColumn(3).setPreferredWidth(200);
	        columnModels.getColumn(4).setPreferredWidth(5);
	        BorrowUserJScroll = new JScrollPane(BorrowUserTable);
	        BorrowUserTable.getColumnModel().getColumn(4).setCellRenderer(new TableCell("선택", BorrowUserTable, mu.hashuser, mb.hashbook, BorrowFrame, BorrowFrame));;
	        BorrowUserTable.getColumnModel().getColumn(4).setCellEditor(new TableCell("선택", BorrowUserTable, mu.hashuser, mb.hashbook, BorrowFrame, BorrowFrame));;		      
	        BorrowUserJScroll.setLocation(70,130);
	        BorrowUserJScroll.setSize(650,400);
	        BorrowFrame.getContentPane().add(BorrowUserJScroll);
	}
	
	
	}

