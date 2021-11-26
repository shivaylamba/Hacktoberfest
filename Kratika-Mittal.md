/*InitCap
Write a program to convert the first character of each word in a sentence to uppercase.
*/




import java.util.Scanner;
public class Class1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the Sentence:");
		String sent = sc.nextLine();
		sc.close();
		int count = 0;
		int flag=0;
		int cap=1;
		char ch[] = sent.toCharArray();
		int v = ch[0];
		if((v>=65&&v<=90))
		{
			flag++;
		}
		int a = ch[0]-32;
		ch[0] = (char)a;

		for(int i=0;i<ch.length;i++)
		{
			count=0;
			if(ch[i]==32)
			{
				count++;
				cap++;
				int m = ch[i+1];
				if((m>=65&&m<=90))
				{
					flag++;
				}
			}
			if((count==1))
			{
				int b = ch[i+1]-32;
				ch[i+1] = (char)b; 
			}
		}
		if(cap==flag)
		{
			System.out.print("First character of each word in the sentence is already in uppercase");
		}
		else
		{
			for(int i=0;i<ch.length;i++)
				System.out.print(ch[i]);
		}

	}
}
