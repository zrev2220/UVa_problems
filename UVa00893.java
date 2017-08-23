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
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		String[] params = null;
		try {params = br.readLine().split(" ");} catch (IOException ex) {}
		while (!params[0].equals("0"))
		{
			int plusd = Integer.valueOf(params[0]);
			int d = Integer.valueOf(params[1]);
			int m = Integer.valueOf(params[2]);
			int y = Integer.valueOf(params[3]);
			GregorianCalendar cal = new GregorianCalendar(y, m - 1, d);
			cal.add(Calendar.DAY_OF_MONTH, plusd);
			pr.printf("%d %d %d%n", cal.get(Calendar.DAY_OF_MONTH), cal.get(Calendar.MONTH) + 1, cal.get(Calendar.YEAR));
			
			try {params = br.readLine().split(" ");} catch (IOException ex) {}
		}
		
		pr.close();
	}
}
