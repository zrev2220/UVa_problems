// Passes sample, but not uDebug
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
			while (br.ready())
			{
				String[] list = br.readLine().split(" ");
				int[] negsLeft = new int[list.length - 1]; int neg = 0;
				for (int i = negsLeft.length - 1; i >= 0; i--)
				{
					if (Integer.parseInt(list[i]) < 0)
						negsLeft[i] = ++neg;
				}
				BigInteger maxProd = new BigInteger(list[0]);
				BigInteger runningProd = BigInteger.ONE;
				BigInteger runningProd_neg = BigInteger.ONE;
				for (int i = 0; i < list.length - 1; i++)
				{
					BigInteger next = new BigInteger(list[i]);
					runningProd = runningProd.multiply(next);
					runningProd_neg = runningProd_neg.multiply(next);
					maxProd = maxProd.max(runningProd.max(runningProd_neg));
					if (runningProd.compareTo(BigInteger.ZERO) == 0)
					{
						runningProd = BigInteger.ONE;
						runningProd_neg = BigInteger.ONE;
					}
					else if (negsLeft[i] % 2 != 0)
						runningProd = BigInteger.ONE;
				}
				pr.println(maxProd);
			}
		} catch (IOException ex) {}
		
		pr.close();
	}
}
