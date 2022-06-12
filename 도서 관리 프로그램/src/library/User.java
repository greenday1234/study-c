package library;

import java.util.Vector;

public class User {
	private String name;// ����� �̸�
	private String address;// ����� �ּ�
	private String phoneNumber;// ����� ��ȭ��ȣ
	private String userNumber;
	private Vector<String> bookISBN = new Vector<String>();// �뿩�� å�� ISBN �ڵ� ����

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
	public String getName() {// �̸� ����
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
	public void setName(String name) {// �̸� ����
		this.name = name;
	}

	public String getAddress() {// �ּ� ����
		return address;
	}

	public void setAddress(String address) {// �ּ� ����
		this.address = address;
	}

	public String getPhoneNumber() {// ��ȭ��ȣ ����
		return phoneNumber;
	}

	public void setPhoneNumber(String phoneNumber) {// ��ȭ��ȣ ����
		this.phoneNumber = phoneNumber;
	}

	public void setBookISBN(String bookISBN) {// å ISBN�ڵ� String���� �޾ƿͼ� ���Ϳ� ����. �� ������ å�� 3�� �̻��̸� ������.
		
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

	
	public String[] getBookISBN()// ������ å ISBN �迭�� ����;
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