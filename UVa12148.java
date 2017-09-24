// WA, but passes sample, uDebug, and discussion
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main
{
	static PrintStream out = System.out;
	static PrintStream err = System.err;
	static final int INF = 1000000000;
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		// if necessary
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = in.nextInt();
		while (n != 0)
		{
			GregorianCalendar curDate = null, lastDate = null;
			int curValue = 0, lastValue = 0;
			int certainDays = 0, certainAmt = 0;
			for (int i = 0; i < n; i++)
			{
				int day = in.nextInt(), month = in.nextInt(), year = in.nextInt(), value = in.nextInt();
				lastDate = curDate;
				curDate = new GregorianCalendar(year, month - 1, day);
				lastValue = curValue;
				curValue = value;
				if (i != 0)
				{
					lastDate.add(Calendar.DAY_OF_YEAR, 1);
					if (lastDate.equals(curDate))
					{
						certainDays++;
						certainAmt += curValue - lastValue;
					}
				}
			}
			out.printf("%d %d%n", certainDays, certainAmt);
			
			n = in.nextInt();
		}
		
		// pr.close();
	}
}
