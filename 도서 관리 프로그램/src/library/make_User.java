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

public class make_User {
	public  HashMap<String, User> hashuser = new HashMap<String, User>();
	public make_User(File file) {	
		try {

			BufferedReader inFiles= new BufferedReader(new InputStreamReader(new FileInputStream(file.getPath()), "euc-kr"));

			String line = "";
			StringTokenizer stk;
			String name;
			String address;
			String phoneNumber;
			String userNumber;
			String book1;
			String book2;
			String book3;
			while ((line = inFiles.readLine()) != null) {
				stk = new StringTokenizer(line, "/");
				name = stk.nextToken();
				address = stk.nextToken();
				phoneNumber = stk.nextToken();
				userNumber = stk.nextToken();
				book1=stk.nextToken();
				book2=stk.nextToken();
				book3=stk.nextToken();
				hashuser.put(userNumber, new User(name, address, phoneNumber, userNumber,book1,book2,book3));

			}
			Set<String> keys= hashuser.keySet();
			Iterator<String> it=keys.iterator();
			
			while(it.hasNext()) {
				String st=it.next();
				
				User us=hashuser.get(st);
				System.out.println(us.toString());
			}
			
			inFiles.close();
		} catch (IOException e) {
			// TODO: handle exception
			System.out.println("파일을 열지 못했습니다.");
		}		
	}
	
	public HashMap<String,User> reUser(){
		return hashuser;
	}
}
