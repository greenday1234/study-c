package library;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class find_User {
	public HashMap<String, User> hashuser = new HashMap<String, User>();

	public find_User(HashMap<String, User> hashuser) {
		this.hashuser = hashuser;
	}

	public HashMap<String, User> findUserByName(String name) {
		HashMap<String, User> findUsers = new HashMap<String, User>();
		Set<String> keys = hashuser.keySet();
		Iterator<String> it = keys.iterator();

		while (it.hasNext()) {
			String name1 = it.next();
			User us = hashuser.get(name1);
			if (us.getName().equals(name))
				findUsers.put(us.getUserNumber(), us);
		}
		return findUsers;
	}

	public User returnUser(String userNumber) {
		User u;
		u = hashuser.get(userNumber);
		return u;
	}

	public User returnUserByISBN(String ISBN) {

		Set<String> keys = hashuser.keySet();
		Iterator<String> it = keys.iterator();
		User us=new User("오류", "오류", "오류", "오류");
		while (it.hasNext()) {
			String name1 = it.next();
			us = hashuser.get(name1);
			String[] ArrayISBN = us.getBookISBN();
			for (int i = 0; i < ArrayISBN.length; i++) {
				if (ArrayISBN[i].equals(ISBN)) {
					return us;
				}
			}
		}
		return us;
	}
}
