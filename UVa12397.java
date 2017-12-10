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
		TreeMap<Integer, Integer> stickMap = new TreeMap<>();
		stickMap.put(1, 1);
		stickMap.put(4, 3);
		stickMap.put(5, 2);
		stickMap.put(9, 3);
		stickMap.put(10, 2);
		stickMap.put(40, 4);
		stickMap.put(50, 2);
		stickMap.put(90, 4);
		stickMap.put(100, 2);
		stickMap.put(400, 5);
		stickMap.put(500, 3);
		stickMap.put(900, 6);
		stickMap.put(1000, 4);
		
		while (in.hasNext())
		{
			int n = in.nextInt();
			int sticks = 0;
			while (n > 0)
			{
				// out.printf("n is %d%n", n);
				Integer i = (stickMap.containsKey(n)) ? n : stickMap.lowerKey(n);
				// out.printf("i is %d%nsubtract %d from %d%nadd %d sticks%n", i, i, n, stickMap.get(i));
				n -= i;
				sticks += stickMap.get(i);
			}
			out.println(sticks);
		}
	}
}
