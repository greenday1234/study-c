package library;

import java.util.Calendar;
import java.util.HashMap;

public class borrow_Book {
	
	String ISBN;
	find_Book fb;
	find_User fu;
	public borrow_Book(HashMap<String,User> HU, HashMap<String, Book> HB) {
		fb=new find_Book(HB);
		fu=new find_User(HU);
	}
	public boolean borrow(String ISBN,String userNumber) {
		Book b=fb.returnBook(ISBN);
		User u=fu.returnUser(userNumber);
		if(u.BookCount()==3)
		{
			System.out.println(u.getName()+"ȸ�� ���� �ݳ� �� �뿩 �����մϴ�.");
			return false;
		}
		if(b.getRent().equals("�뿩����"))
		{
			System.out.println("good");
			b.setRent("�뿩��");
			b.setBorrowDate(Long.toString(Calendar.getInstance().getTimeInMillis()));
		}
		else
		{
			System.out.println(b.toString()+"�� �뿩���� �����Դϴ�.");
			return false;
		}
			
		
		u.setBookISBN(ISBN);
		System.out.println(u.toString());
		return true;
	}
	
	
}
