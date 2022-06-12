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
import library.Book;

public class DeleteBook extends OpenFile{
	private static JFrame DeleteFrame;
	private static JTable DeleteTable;
	private static JScrollPane DeleteBookScroll;
	
	public static void DeleteBook(JFrame frame) {
		DeleteFrame = new JFrame("도서 목록");
		DeleteFrame.setBounds(560,200,700,550);
		DeleteFrame.getContentPane().setLayout(null);
		DeleteFrame.getContentPane().setBackground(new Color(180,230,180));
		DeleteFrame.setLocationRelativeTo(null);
		
		RoundedButton BackBtn = new RoundedButton("Back");
		BackBtn.setFont(new Font("굴림", Font.BOLD, 20));
		BackBtn.setBounds(20,10,80,45);
		DeleteFrame.getContentPane().add(BackBtn);
		BackBtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				DeleteFrame.setVisible(false);
				Select_View.getFrame().setVisible(true);
			}
		});
	
		HashMap<String, Book> hb = mb.hashbook;
		String header[]={"청구기호", "제목", "저자", "대여 상태", "삭제"};
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
		DeleteTable = new JTable(contents, header);
		DeleteTable.setPreferredScrollableViewportSize(new Dimension(500,50));
		DeleteTable.setFillsViewportHeight(true);
		 
	        TableColumnModel BookcolumnModels = DeleteTable.getColumnModel();
	        BookcolumnModels.getColumn(0).setPreferredWidth(10);
	        BookcolumnModels.getColumn(1).setPreferredWidth(60);
	        BookcolumnModels.getColumn(2).setPreferredWidth(20);
	        BookcolumnModels.getColumn(3).setPreferredWidth(5);
	        BookcolumnModels.getColumn(4).setPreferredWidth(5);
	        DeleteBookScroll = new JScrollPane(DeleteTable);
	        DeleteTable.getColumnModel().getColumn(4).setCellRenderer(new TableCell("책 삭제", DeleteTable, mu.hashuser, mb.hashbook, DeleteFrame));;
	        DeleteTable.getColumnModel().getColumn(4).setCellEditor(new TableCell("책 삭제", DeleteTable, mu.hashuser, mb.hashbook, DeleteFrame));;		      
	        DeleteBookScroll.setLocation(18,80);
	        DeleteBookScroll.setSize(650,400);
	        DeleteFrame.getContentPane().add(DeleteBookScroll);  
	       
	        DeleteFrame.setVisible(true);
	}
	public static JFrame getDeleteFrame() {
		return DeleteFrame;
	}
	
}