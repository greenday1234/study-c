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
			System.out.println(u.getName()+"회원 님은 반납 후 대여 가능합니다.");
			return false;
		}
		if(b.getRent().equals("대여가능"))
		{
			System.out.println("good");
			b.setRent("대여중");
			b.setBorrowDate(Long.toString(Calendar.getInstance().getTimeInMillis()));
		}
		else
		{
			System.out.println(b.toString()+"은 대여중인 도서입니다.");
			return false;
		}
			
		
		u.setBookISBN(ISBN);
		System.out.println(u.toString());
		return true;
	}
	
	
}
