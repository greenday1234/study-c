public class StringEx {
	public static void main(String[] args) {
		String a = new String(" C#");
		String b = new String(",C++");
		
		System.out.println(a + "의 길이는 " + a.length());
		System.out.println(a.contains("#"));	//문자열 포함
		
		a = a.concat(b);	//문자열 연결
		System.out.println(a);
		
		a = a.trim();	//문자열 공백 삭제
		System.out.println(a);
		
		a = a.replace("C#", "Java");	//문자열 대치(변경)
		System.out.println(a);
		
		String s[] = a.split(",");	//문자열 분리
		for(int i=0;i<s.length;i++) {
			System.out.println("분리된 문자열 " + i + ": " + s[i]);
		}
		a = a.substring(5);	//문자열 해당 위치부터 리턴
		System.out.println(a);
		
		char c = a.charAt(2);	//문자열 해당 인덱스 리턴
		System.out.println(c);
	}
}
