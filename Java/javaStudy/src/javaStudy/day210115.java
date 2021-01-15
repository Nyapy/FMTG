package javaStudy;

public class day210115 {
	public static class Test {
		String name;
		int age;

		void set(String name, int age) {
			this.name = name;
			this.age = age;
			System.out.println(name + "�� ���̴� " + age + "�Դϴ�.");
		}

		void set(String name) {
			this.name = name;
			System.out.println("�̸� �缳�� : " + name);
		}

		void set(int age) {
			this.age = age;
			System.out.println("���� �缳��");
		}

		void set() {
			this.name = "No name";
			this.age = 0;
			System.out.println("����");
		}
	}

	public static void main(String[] args) {
		Test AA = new Test();
		AA.set("����");
		AA.set("����", 20);
		AA.set();
		AA.set(26);

		class print {
			public void printData(int data) {
				System.out.println(data);
			}

			public void printData(double data) { 
				System.out.println(data); 
			}
			 
			public void printData(char data) {
				System.out.println(data);
			}

			public void printData(String data) {
				System.out.println(data);
			}
		}
		print B = new print();
		B.printData(4.5);
		
		class thisTest{
			int No ;
			String name;
			int age;
			int salary;
			
			public thisTest() {
				this(0,"Anonymity",0,0);
			}

			public thisTest(int No, String name) {
				this.No = No;
				this.name = name;
			}
			public thisTest(int No, String name, int age) {
				this(No, name);
				this.age = age;
			}


		}
	}
}
