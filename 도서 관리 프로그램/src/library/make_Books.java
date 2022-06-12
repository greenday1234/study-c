package library;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
import java.util.StringTokenizer;

public class make_Books {
	public HashMap<String, Book> hashbook = new HashMap<String, Book>();

	public make_Books(File file) {	
		try {

			BufferedReader inFiles= new BufferedReader(new InputStreamReader(new FileInputStream(file.getPath()), "euc-kr"));

			String line = "";
			StringTokenizer stk;
			String title;
			String author;
			String ISBN;
			String rent;
			String borrowDate;
			while ((line = inFiles.readLine()) != null) {
				stk = new StringTokenizer(line, "/");
				title = stk.nextToken();
				author = stk.nextToken();
				ISBN = stk.nextToken();
				rent =stk.nextToken();
				borrowDate=stk.nextToken();
				hashbook.put(ISBN, new Book(title, author, ISBN, rent,borrowDate));

			}
			Set<String> keys= hashbook.keySet();
			Iterator<String> it=keys.iterator();
			
			while(it.hasNext()) {
				String st=it.next();
				
				Book bk=hashbook.get(st);
				System.out.println(bk.toString());
			}
			
			inFiles.close();
		} catch (IOException e) {
			// TODO: handle exception
			System.out.println("파일을 열지 못했습니다.");
		}		
	}
	
	public HashMap<String,Book> reBooks(){
		return hashbook;
	}
}
