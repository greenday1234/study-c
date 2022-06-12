package library;

import java.util.Calendar;
import java.util.HashMap;

public class return_Book {

	String ISBN;
	find_Book fb;
	find_User fu;
	public return_Book(HashMap<String,User> HU, HashMap<String, Book> HB) {
		fb = new find_Book(HB);
		fu = new find_User(HU);
	}
	public String returnBook(String ISBN) {
		Book b=fb.returnBook(ISBN);
		if(b.getRent().equals("대여중"))
		{
			b.setRent("대여가능");	
			Long diffsec;
			diffsec=(Calendar.getInstance().getTimeInMillis()-Long.parseLong(b.getBorrowDate()))/1000;
			diffsec=diffsec/(24*60*60);
			if(diffsec>14)
			{
				return diffsec-14 + "일만큼 연체 되셨습니다.연체료를 지불 하셔야 합니다.";
			}
			b.setBorrowDate(" ");
		}
				
		User u=fu.returnUserByISBN(ISBN);
		u.deleteBookISBN(ISBN);
		System.out.println(u.toString());
		return " ";
	}
}
