package library;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class managementBook {

	public void addBook(HashMap<String, Book> hashbook, String title,String author,String ISBN) {
		Set<String> keys = hashbook.keySet();
		Iterator<String> it = keys.iterator();

		while (it.hasNext()) {
			String title1 = it.next();
			Book bk = hashbook.get(title1);
			if (bk.getISBN().equals(ISBN))
			{
				System.out.println("이미 존재하는 ISBN 코드입니다.");
				return;
			}
				
		}
		hashbook.put(ISBN,new Book(title,author,ISBN));
	}
	public void removeBook(HashMap<String, Book> hashbook,String ISBN) {
		hashbook.remove(ISBN);
	}
	
}
