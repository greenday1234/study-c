package library;

import java.util.Vector;

public class User {
	private String name;// 사용자 이름
	private String address;// 사용자 주소
	private String phoneNumber;// 사용자 전화번호
	private String userNumber;
	private Vector<String> bookISBN = new Vector<String>();// 대여한 책의 ISBN 코드 벡터

	public User(String name, String address, String phoneNumber, String userNumber) {
		this.setName(name);
		this.setAddress(address);
		this.setPhoneNumber(phoneNumber);
		this.setUserNumber(userNumber);
		bookISBN.add(" ");
		bookISBN.add(" ");
		bookISBN.add(" ");
	}
	public User(String name, String address, String phoneNumber, String userNumber,String book1,String book2,String book3) {
		this.setName(name);
		this.setAddress(address);
		this.setPhoneNumber(phoneNumber);
		this.setUserNumber(userNumber);
		bookISBN.add(book1);
		bookISBN.add(book2);
		bookISBN.add(book3);
	}
	public String getName() {// 이름 리턴
		return name;
	}

	public int BookCount()
	{
		int BookCount=0;
		for(int i=0;i<3;i++)
		{
			if(bookISBN.get(i).equals(" "))
			{
				continue;
			}
			else
				BookCount++;
			
		}
		return BookCount;
	}
	public void setName(String name) {// 이름 설정
		this.name = name;
	}

	public String getAddress() {// 주소 리턴
		return address;
	}

	public void setAddress(String address) {// 주소 설정
		this.address = address;
	}

	public String getPhoneNumber() {// 전화번호 리턴
		return phoneNumber;
	}

	public void setPhoneNumber(String phoneNumber) {// 전화번호 설정
		this.phoneNumber = phoneNumber;
	}

	public void setBookISBN(String bookISBN) {// 책 ISBN코드 String으로 받아와서 벡터에 저장. 단 빌려간 책이 3권 이상이면 못빌림.
		
		for(int i=0;i<this.bookISBN.size();i++)
		{
			if(this.bookISBN.get(i).equals(" "))
			{
				this.bookISBN.add(i,bookISBN);
				this.bookISBN.remove(i+1);
				
				return;
			}
			
		}
		
	}

	
	public String[] getBookISBN()// 빌려간 책 ISBN 배열로 리턴;
	{
		String arr[] = new String[3];
		arr = bookISBN.toArray(arr);
		return arr;
	}

	public void deleteBookISBN(String bookISBN) {
		for(int i=0;i<this.bookISBN.size();i++)
		{
			if(this.bookISBN.get(i).equals(bookISBN))
			{
				this.bookISBN.add(i," ");
				this.bookISBN.remove(i+1);		
				return;
			}		
		}
	}
	public String getUserNumber() {
		return userNumber;
	}

	public void setUserNumber(String userNumber) {
		this.userNumber = userNumber;
	}
	
	 public String toString() {
		   return name+"/"+address+"/"+phoneNumber+"/"+userNumber+"/"+bookISBN.get(0)+"/"+bookISBN.get(1)+"/"+bookISBN.get(2);
	   }
}