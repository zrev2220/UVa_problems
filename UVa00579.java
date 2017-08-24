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
		String line = in.nextLine();
		while (!line.equals("0:00"))
		{
			int h = Integer.valueOf(line.substring(0, line.indexOf(":")));
			int m = Integer.valueOf(line.substring(line.indexOf(":") + 1));
			double mdeg = (double) m * 6.0;
			double hdeg = (double) ((h % 12) * 30) + ((double) m / 60.0 * 30.0);
			double ans = Math.abs(mdeg - hdeg);
			if (ans > 180) ans = 360 - ans;
			out.printf("%.3f%n", ans);
			
			line = in.nextLine();
		}
		
		// pr.close();
	}
}
