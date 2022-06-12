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
import library.Book;
import library.User;

public class ReturnBookTable_View extends OpenFile {
		private static String ReturnBookSearchFieldtext;
		private static JTable ReturnBookTable;
		private static JScrollPane ReturnBookJScroll;
	
	public static void ReturnBookTable_View() {
		
		ReturnBookSearchFieldtext = Return_View.getReturnBookSearchField();
		HashMap<String, Book> hb = fb.findBookByTitle(ReturnBookSearchFieldtext);
		String header[]={"청구기호", "제목", "저자", "대여 상태", "반납"};
		String contents[][]=new String[hb.size()][5];
		Set<String> keys = hb.keySet();
		Iterator<String> it = keys.iterator();
		int findN=0;
		while (it.hasNext()) {
			String number = it.next();
			Book bo = hb.get(number);
				contents[findN][0]=bo.getISBN();
				contents[findN][1]=bo.getTitle();
				contents[findN][2]=bo.getAuthor();
				contents[findN][3]=bo.getRent();
				findN++;
		}
		ReturnBookTable = new JTable(contents, header);
		ReturnBookTable.setPreferredScrollableViewportSize(new Dimension(500,50));
		ReturnBookTable.setFillsViewportHeight(true);
		 
	        TableColumnModel columnModels = ReturnBookTable.getColumnModel();
	        columnModels.getColumn(0).setPreferredWidth(10);
	        columnModels.getColumn(1).setPreferredWidth(35);
	        columnModels.getColumn(2).setPreferredWidth(20);
	        columnModels.getColumn(3).setPreferredWidth(5);
	        columnModels.getColumn(4).setPreferredWidth(5);
	        ReturnBookJScroll = new JScrollPane(ReturnBookTable);
	        ReturnBookTable.getColumnModel().getColumn(4).setCellRenderer(new TableCell("반납", ReturnBookTable, mu.hashuser, mb.hashbook));;
	        ReturnBookTable.getColumnModel().getColumn(4).setCellEditor(new TableCell("반납", ReturnBookTable, mu.hashuser, mb.hashbook));;
	        ReturnBookJScroll.setLocation(70,130);
	        ReturnBookJScroll.setSize(650,400);
	        Return_View.getReturn_ViewFrame().getContentPane().add(ReturnBookJScroll);
	}
	}
