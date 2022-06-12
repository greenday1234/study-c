package library;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class managementUser {

	public void addUser(HashMap<String, User> hashuser, String name, String address, String phoneNumber,String userNumber) {
		Set<String> keys = hashuser.keySet();
		Iterator<String> it = keys.iterator();

		while (it.hasNext()) {
			String name1 = it.next();
			User us = hashuser.get(name1);
			if (us.getUserNumber().equals(userNumber))
			{
				System.out.println("이미 존재하는 회원 번호입니다.");
				return;
			}
				
		}
		hashuser.put(userNumber,new User(name,address,phoneNumber,userNumber));
	}
	
	public void editUser(HashMap<String, User> hashuser, String name, String address, String phoneNumber,String userNumber)
	{
		hashuser.remove(userNumber);
		hashuser.put(userNumber,new User(name,address,phoneNumber,userNumber));
	}
	
	public void removeUser(HashMap<String, User> hashuser,String userNumber) {
		hashuser.remove(userNumber);
	}

	
}
