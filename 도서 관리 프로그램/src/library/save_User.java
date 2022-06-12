package library;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class save_User {
	public save_User(File file, HashMap<String, User> hashuser) {
		try {
			FileOutputStream fos = new FileOutputStream(file);
			OutputStreamWriter osw = new OutputStreamWriter(fos, "euc-kr");
			BufferedWriter bw = new BufferedWriter(osw);
			if (file.isFile() && file.canWrite()) {
				// ¾²±â
				Set<String> keys = hashuser.keySet();
				Iterator<String> it = keys.iterator();
				String string;
				while (it.hasNext()) {
					String st = it.next();
					User bk = hashuser.get(st);
					string = bk.toString();
					bw.write(string + "/");
					bw.newLine();
				}
				bw.flush();
				osw.close();
				fos.close();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
