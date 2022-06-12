package library;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

public class save_Book {

	public save_Book(File file, HashMap<String, Book> hashbook) {
		try {
			FileOutputStream fos = new FileOutputStream(file);
			OutputStreamWriter osw = new OutputStreamWriter(fos, "euc-kr");
			BufferedWriter bw = new BufferedWriter(osw);
			if (file.isFile() && file.canWrite()) {
				// ¾²±â
				Set<String> keys = hashbook.keySet();
				Iterator<String> it = keys.iterator();
				String string;
				while (it.hasNext()) {
					String st = it.next();
					Book bk = hashbook.get(st);
					string = bk.toString();
					bw.write(string);
					bw.newLine();
				}
				bw.flush();
				osw.close();
				fos.close();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
