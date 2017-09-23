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
		try
		{
			String line = br.readLine();
			while (!line.equals("END"))
			{
				String prev = line;
				String next = String.valueOf(line.length());
				int i = 1;
				while (!prev.equals(next))
				{
					prev = next;
					next = String.valueOf(next.length());
					i++;
				}
				pr.println(i);
				
				line = br.readLine();
			}
		} catch (IOException ex) {}
		
		pr.close();
	}
}
