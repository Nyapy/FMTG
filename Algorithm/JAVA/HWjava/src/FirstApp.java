
public class FirstApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("ù ��°. Hello, World");
		if (true){
			int x = 5;
			
			System.out.println(x);
		}
		int age = 25;
		double avgAge = (double)age;
		System.out.println(avgAge);
		
//		byte b1 = 127;
//		char c1 = '��';
//		int i1;
//		double d1;
//		System.out.println("�ڵ� ����ȯ ���");
//		i1 = b1;
//		System.out.println("i1 = b1�� ����ȯ " + i1);
//		i1 = c1;
//		System.out.println("i1 = c1�� ����ȯ " + i1);
//		d1 = i1;
//		System.out.println("d1 = i1�� ����ȯ " + d1);
//		
//		int sum = 128;
//		byte data = (byte)sum;
//		System.out.println(data);
		byte b1 = 127;
		char c1;
		int i1 = 128;
		int i2 = 97;
		double d1 = 3.14;
		System.out.println("����� ����ȯ ���");
		b1 = (byte)i1;
// ��Ʈ �����ʹ� ����Ʈ������ ����ȯ������ ����Ʈ�� 128�� ǥ���� �� �����Ƿ� �����ٸ��� -128�� ����
		System.out.println("b1 = i1�� ����ȯ " + b1);
		c1 = (char)i2;
// 97�̶�� ��Ʈ �����͸� char ������ ����ȯ ���� �� 97�� �����ڵ�� �ϴ� ������ �ҹ��� a�� c1�� ����
		System.out.println("c1 = i2�� ����ȯ " + c1);
		i1= (int)d1;
// int double �����͸� int �����ͷ� ����� ����ȯ�Ͽ� 3.15 �Ҽ��� �Ʒ��� ������ ���� �κи��� i1 ������ ����
		System.out.println("d1 = i1�� ����ȯ " + i1);
		
	
		
	}

}
