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
import library.find_Book;

public class BorrowBookTable_View extends OpenFile {
	private static String BorrowBookSearchFieldtext;
	private static JTable BorrowBookTable;
	private static JScrollPane BorrowBookJScroll;
	
	public static void BorrowBookTable_View(JFrame frame, String UserNumber) {
		
		BorrowBookSearchFieldtext = BorrowSearchBook.getBorrowBookSearchField();
		HashMap<String, Book> hb = fb.findBookByTitle(BorrowBookSearchFieldtext);
		String header[]={"청구기호", "제목", "저자", "대여 상태", "대여"};
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
		 BorrowBookTable = new JTable(contents, header);
		 BorrowBookTable.setPreferredScrollableViewportSize(new Dimension(500,50));
		 BorrowBookTable.setFillsViewportHeight(true);
		 
	        TableColumnModel BookcolumnModels = BorrowBookTable.getColumnModel();
	        BookcolumnModels.getColumn(0).setPreferredWidth(10);
	        BookcolumnModels.getColumn(1).setPreferredWidth(60);
	        BookcolumnModels.getColumn(2).setPreferredWidth(20);
	        BookcolumnModels.getColumn(3).setPreferredWidth(5);
	        BookcolumnModels.getColumn(4).setPreferredWidth(5);
	        BorrowBookJScroll = new JScrollPane(BorrowBookTable);
	        BorrowBookTable.getColumnModel().getColumn(4).setCellRenderer(new TableCell("대여", BorrowBookTable, mu.hashuser, mb.hashbook, UserNumber));;
	        BorrowBookTable.getColumnModel().getColumn(4).setCellEditor(new TableCell("대여", BorrowBookTable, mu.hashuser, mb.hashbook, UserNumber));;		      
	        BorrowBookJScroll.setLocation(70,130);
	        BorrowBookJScroll.setSize(650,400);
	        frame.getContentPane().add(BorrowBookJScroll);
	}
	
	
}

