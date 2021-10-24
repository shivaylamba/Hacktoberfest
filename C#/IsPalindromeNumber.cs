using System;
					
public class Program
{
	public static bool IsPalindrome(int n)
	{
		int divisor = 1;
		while (n / divisor >= 10)
		{
			divisor *= 10;
		}
		
		while (n != 0)
		{
			int leading = n / divisor;
			int trailing = n % 10;
			if (leading != trailing)
			{
				return false;
			}
			n = (n % divisor) / 10;
			divisor /= 100;
		}
		
		return true;
	}
	
	public static void Main()
	{
		Console.WriteLine(IsPalindrome(1001));
	}
}
