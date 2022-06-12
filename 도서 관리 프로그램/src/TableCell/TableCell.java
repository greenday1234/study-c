package TableCell;

import java.awt.Component;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;

import javax.swing.AbstractCellEditor;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTable;
import javax.swing.table.TableCellEditor;
import javax.swing.table.TableCellRenderer;

import System.BorrowBookTable_View;
import System.BorrowSearchBook;
import System.Edit;
import System.ReturnBookTable_View;
import System.Return_View;
import System.Select_View;
import library.Book;
import library.User;
import library.borrow_Book;
import library.find_Book;
import library.find_User;
import library.managementBook;
import library.managementUser;
import library.return_Book;
public class TableCell extends AbstractCellEditor implements TableCellEditor, TableCellRenderer{

	private JButton jb;
	String UserNumber;
	
	//BorrowUserTable
	public TableCell(String name, JTable BorrowUserTable, HashMap<String,User> HU, HashMap<String, Book> HB, JFrame frame1, JFrame frame2) {
		jb = new JButton(name);
		jb.addActionListener(e -> {
			this.UserNumber = (String) (BorrowUserTable.getValueAt(BorrowUserTable.getSelectedRow(), 0));
			frame1.setVisible(false);
			frame2.setVisible(false);
			BorrowSearchBook.BorrowSearchBook(UserNumber);
		});
	}
	//BorrowBookTable
	public TableCell(String name, JTable BorrowBookTable, HashMap<String,User> HU, HashMap<String, Book> HB, String UserNumber) {
		jb = new JButton(name);
			jb.addActionListener(e -> {
				String Rent = (String) (BorrowBookTable.getValueAt(BorrowBookTable.getSelectedRow(), 3));
				System.out.println(Rent);
				String ISBN = (String) (BorrowBookTable.getValueAt(BorrowBookTable.getSelectedRow(), 0));
				System.out.println(ISBN);
				if(Rent.equals("�뿩��")) {
					JOptionPane.showMessageDialog(null,"�� ������ ���� �뿩 ���Դϴ�.");
				}
				else {
					borrow_Book bB = new borrow_Book(HU,HB);
					bB.borrow(ISBN, UserNumber);
					JOptionPane.showMessageDialog(null,"������ ����Ǿ����ϴ�.");
					
					BorrowSearchBook.getBorrowBookFrame().setVisible(false);
					Select_View.getFrame().setVisible(true);
					
				}
			});
		}
	//ReturnTable
	public TableCell(String name, JTable BorrowUserTable, HashMap<String,User> HU, HashMap<String, Book> HB) {
		jb = new JButton(name);
		jb.addActionListener(e -> {
			String ISBN = (String) (BorrowUserTable.getValueAt(BorrowUserTable.getSelectedRow(), 0));
			return_Book rB = new return_Book(HU,HB);
			JOptionPane.showMessageDialog(null,"������ �ݳ��Ǿ����ϴ�." + "\n" + rB.returnBook(ISBN));
			Return_View.getReturn_ViewFrame().setVisible(false);
			Select_View.getFrame().setVisible(true);
		});
	}
	public TableCell(String name, JTable BorrowBookTable, HashMap<String,User> HU, HashMap<String, Book> HB, JFrame frame1) { //å ���� �޼ҵ�
		jb = new JButton(name);
		jb.addActionListener(e -> {
			if(name.equals("å ����")) {
			String ISBN = (String) (BorrowBookTable.getValueAt(BorrowBookTable.getSelectedRow(), 0));
			frame1.setVisible(false);	
			managementBook m2b = new managementBook();
			find_Book fB = new find_Book(HB);
			m2b.removeBook(fB.hashbook, ISBN);
			JOptionPane.showMessageDialog(null, "������ å�� �����Ǿ����ϴ�.");
			Select_View.Select_View();
			}
			if(name.equals("����")){
				String userNumber = (String) (BorrowBookTable.getValueAt(BorrowBookTable.getSelectedRow(), 0));

				frame1.setVisible(false);	
				find_User fU = new find_User(HU);
				managementUser m2u = new managementUser();
				m2u.removeUser(fU.hashuser, userNumber);
				//HU.remove(userNumber); // 
				JOptionPane.showMessageDialog(null, "������ ����ڰ� �����Ǿ����ϴ�.");
				Select_View.Select_View();
			}
			if(name.equals("����")) {
				this.UserNumber = (String) (BorrowBookTable.getValueAt(BorrowBookTable.getSelectedRow(), 0));
				
				String userName = (String) (BorrowBookTable.getValueAt(BorrowBookTable.getSelectedRow(), 0));
				String userAddress = (String) (BorrowBookTable.getValueAt(BorrowBookTable.getSelectedRow(), 2));
				String userPhoneNumber = (String) (BorrowBookTable.getValueAt(BorrowBookTable.getSelectedRow(), 3));
				String userNumber = (String) (BorrowBookTable.getValueAt(BorrowBookTable.getSelectedRow(), 1));
				frame1.setVisible(false);
				Edit.Edit(userNumber,userPhoneNumber,userAddress,userName);
				
			}
		});
	}
	public Object getCellEditorValue() {
		// TODO Auto-generated method stub
		return null;
	}

	public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus,
			int row, int column) {
		// TODO Auto-generated method stub
		return jb;
	}

	public Component getTableCellEditorComponent(JTable table, Object value, boolean isSelected, int row,
			int column) {
		// TODO Auto-generated method stub
		return jb;
	}
	
}