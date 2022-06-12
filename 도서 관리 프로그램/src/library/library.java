/*package library;

import java.io.File;
import java.util.HashMap;
import java.util.Scanner;

public class library {

	public static void run() {
		HashMap<String, Book> hashbook;
		HashMap<String, User> hashuser;
		Scanner scanner=new Scanner(System.in);
		File f=new File("C:\\Users\\dhrjf\\Documents\\20214001 - theibrokhim_java\\library\\src\\library\\Books.txt");
		make_Books mb=new make_Books(f);
		hashbook=mb.reBooks();	
		File f1=new File("C:\\Users\\dhrjf\\Documents\\20214001 - theibrokhim_java\\library\\src\\library\\User.txt");
		make_User mu=new make_User(f1);
		hashuser=mu.reUser();
		find_Book fb=new find_Book(mb.reBooks());
		find_User fu=new find_User(mu.reUser());
		boolean bool=true;
		while(bool)
		{
			System.out.println("대여 또는 반납");
			String menu=scanner.nextLine();
			switch (menu) {
			case "대여": {
				System.out.print("회원 번호를 입력하세요>>");
				String userNumber=scanner.nextLine();
				System.out.print("책ISBN 코드를 입력하세요>>");
				String BookNumber=scanner.nextLine();
				borrow_Book bB=new borrow_Book(fb, fu);
				if(bB.borrow(BookNumber, userNumber)==false)
					System.out.println("책을 빌릴 수 없습니다");
				break;
			}
			case "반납": {
				System.out.print("회원 번호를 입력하세요>>");
				String userNumber=scanner.nextLine();
				System.out.print("책ISBN 코드를 입력하세요>>");
				String BookNumber=scanner.nextLine();
				return_Book rB=new return_Book(fb, fu);
				rB.returnBook(BookNumber, userNumber);
				break;
			}
			case "그만":{
				bool=false;
				break;
			}
			default:
				throw new IllegalArgumentException("Unexpected value: " + menu);
			}
		
		}
		
		scanner.close();
		save_Book sb=new save_Book(f,hashbook);
		save_User su=new save_User(f1, hashuser);
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		run();
		
		
		
	}

}
*/