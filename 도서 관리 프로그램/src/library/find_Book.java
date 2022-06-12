package library;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class find_Book {
	 public HashMap<String, Book> hashbook = new HashMap<String, Book>();

	public find_Book(HashMap<String, Book> hashbook) {
		this.hashbook = hashbook;
	}

	public HashMap<String, Book> findBookByTitle(String title) {
		HashMap<String, Book> findBooks = new HashMap<String, Book>();
		Set<String> keys = hashbook.keySet();
		Iterator<String> it = keys.iterator();

		while (it.hasNext()) {
			String title1 = it.next();
			Book bk = hashbook.get(title1);
			if (bk.getTitle().equals(title) )
				findBooks.put(bk.getISBN(), bk);
		}
		return findBooks;
	}

	public Book returnBook(String ISBN) {
		Book b;
		b = hashbook.get(ISBN);
		return b;
	}
}
