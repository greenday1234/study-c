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
		if(b.getRent().equals("�뿩��"))
		{
			b.setRent("�뿩����");	
			Long diffsec;
			diffsec=(Calendar.getInstance().getTimeInMillis()-Long.parseLong(b.getBorrowDate()))/1000;
			diffsec=diffsec/(24*60*60);
			if(diffsec>14)
			{
				return diffsec-14 + "�ϸ�ŭ ��ü �Ǽ̽��ϴ�.��ü�Ḧ ���� �ϼž� �մϴ�.";
			}
			b.setBorrowDate(" ");
		}
				
		User u=fu.returnUserByISBN(ISBN);
		u.deleteBookISBN(ISBN);
		System.out.println(u.toString());
		return " ";
	}
}
