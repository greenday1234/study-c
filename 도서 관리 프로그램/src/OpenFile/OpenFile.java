package OpenFile;
import java.io.File;
import java.io.IOException;
import java.util.HashMap;

import library.Book;
import library.User;
import library.find_Book;
import library.find_User;
import library.make_Books;
import library.make_User;

public class OpenFile {
	protected static File f = new File("User.txt");
	protected static File f2 = new File("Books.txt");
	protected static make_User mu = new make_User(f);
	protected static find_User fu = new find_User(mu.hashuser);
	protected static make_Books mb = new make_Books(f2);
	protected static find_Book fb = new find_Book(mb.hashbook);
	
}
