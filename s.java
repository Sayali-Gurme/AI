import java.util.*;
class Demo{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String str="\\Hello World";
		Demo obj=new Demo();
		System.out.println("String after AND");
		obj.ANDoperator(str);
		System.out.println("String after XOR");
		obj.XORoperator(str);
		
	}
	static void ANDoperator(String str){
		char arr[]=str.toCharArray();
		for(int i=0;i<arr.length;i++){
			int ascii=(int)arr[i];
			int result=ascii & 127;
			System.out.print((char)result);
		}
		System.out.println();
	}
	static void XORoperator(String str) {
		char[] arr = str.toCharArray();
		for (int i = 0; i < arr.length; i++) {
		    int ascii = (int) arr[i];
		    int result = ascii ^ 127;
		    System.out.print((char) result);
		}
		System.out.println();
	}

}
