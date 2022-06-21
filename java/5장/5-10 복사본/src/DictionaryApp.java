abstract class PairMap{
	protected String keyArray [];
	protected String valueArray [];
	abstract String get(String key);
	abstract void put(String key, String value);
	abstract String delete(String key);
	abstract int length();
}

class Dictionary extends PairMap{
	int count = 0;
	public Dictionary(int n) {
		keyArray = new String[n];
		valueArray = new String[n];
	}
	public String get(String key) {
		for(int i=0;i<count;i++) {
			if(keyArray[i].equals(key)) {
				return valueArray[i];
			}
		}
		return null;
	}
	public void put(String key, String value) {
		int i=0;
		for (i=0;i<count;i++) {
			if(keyArray[i].equals(key))
				break;
		}
		if(i==count) {
			if(i<keyArray.length) {
				keyArray[i] =  key;
				valueArray[i] = value;
				count++;
			}
		}
		else
		{
			keyArray[i] = key;
			valueArray[i] = value;
		}
	}
	public String delete(String key) {
		int i=0;
		for(i=0;i<count;i++) {
			if(keyArray[i].equals(key)) {
				break;
			}
		}
		if(i == count)
			return null;
		String value = valueArray[i];
		for(int j=i;j<count-1;j++) {
			keyArray[j]=keyArray[j+1];
			valueArray[j] = valueArray[j+1];
		}
		count--;
		return value;
	}
	public int length() {
		return count;
	}
	
}
public class DictionaryApp{
	public static void main(String[] args) {
		Dictionary dic = new Dictionary(10);
		dic.put("황기태", "자바");
		dic.put("이재문", "파이선");
		dic.put("이재문", "C++");
		System.out.println("이재문의 값은 " + dic.get("이재문"));
		System.out.println("황기태의 값은 " + dic.get("황기태"));
		dic.delete("황기태");
		System.out.println("황기태의 값은 " + dic.get("황기태"));

	}
}