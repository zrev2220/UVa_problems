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
		TreeMap<Character, Integer> code = new TreeMap<>();
		code.put('A', -1);
		code.put('B', 1);
		code.put('C', 2);
		code.put('D', 3);
		code.put('E', -1);
		code.put('F', 1);
		code.put('G', 2);
		code.put('H', -1);
		code.put('I', -1);
		code.put('J', 2);
		code.put('K', 2);
		code.put('L', 4);
		code.put('M', 5);
		code.put('N', 5);
		code.put('O', -1);
		code.put('P', 1);
		code.put('Q', 2);
		code.put('R', 6);
		code.put('S', 2);
		code.put('T', 3);
		code.put('U', -1);
		code.put('V', 1);
		code.put('W', -1);
		code.put('X', 2);
		code.put('Y', -1);
		code.put('Z', 2);
		// if necessary
		// BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		out.printf("         %-25s%s%n", "NAME", "SOUNDEX CODE");
		while (in.hasNext())
		{
			String name  = in.next();
			String soundex = name.substring(0, 1);
			int lastx = code.get(soundex.charAt(0));
			for (int i = 1; i < name.length(); ++i)
			{
				if (soundex.length() == 4)
					break;
				else
				{
					char letter = name.charAt(i);
					int x = code.get(letter);
					if (x != -1 && x != lastx)
					{
						soundex += x;
					}
					lastx = x;
				}
			}
			while (soundex.length() < 4)
				soundex += "0";
			out.printf("         %-25s%s%n", name, soundex);
		}
		out.println("                   END OF OUTPUT");
		
		// pr.close();
	}
}
