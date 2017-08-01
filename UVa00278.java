import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution
{
	static PrintStream out = System.out;
	static final int INF = 1000000000;
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		while (N-- > 0)
		{
			String piece = in.next();
			int m = in.nextInt();
			int n = in.nextInt();
			int ans = 0;
			int lg = Math.max(m, n);
			int sm = Math.min(m, n);
			switch (piece)
			{
				case "k":
					ans = (((m + 1) / 2) * ((n + 1) / 2)) + ((m / 2) * (n / 2));
					break;
				case "r": case "Q":
					ans = sm;
					break;
				case "K":
					ans = (lg / 2 + lg % 2) * (sm / 2 + sm % 2);
					break;
			}
			out.println(ans);
		}
	}
}
