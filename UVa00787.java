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
				BigInteger maxProd = null;
				BigInteger maxProdPos = BigInteger.ZERO;
				BigInteger maxProdNeg = BigInteger.ZERO;
//				pr.printf("next:%5s max:%10s pos:%10s neg:%10s%n", "null", "null", maxProdPos.toString(), maxProdNeg.toString());
				for (int i = 0; i < list.length - 1; i++)
				{
					BigInteger oldPos = (maxProdPos.compareTo(BigInteger.ZERO) == 0) ? BigInteger.ONE : maxProdPos;
					BigInteger oldNeg = (maxProdNeg.compareTo(BigInteger.ZERO) == 0) ? BigInteger.ONE : maxProdNeg;
					int next = Integer.parseInt(list[i]);
					if (next < 0)
					{
						if (oldNeg.compareTo(BigInteger.ZERO) == -1)
							maxProdPos = oldNeg.multiply(BigInteger.valueOf(next));
						else
							maxProdPos = BigInteger.ZERO;
						maxProdNeg = oldPos.multiply(BigInteger.valueOf(next));
					}
					else if (next > 0)
					{
						maxProdPos = oldPos.multiply(BigInteger.valueOf(next));
						if (maxProdNeg.compareTo(BigInteger.ZERO) == -1)
							maxProdNeg = oldNeg.multiply(BigInteger.valueOf(next));
					}
					else
					{
						maxProdPos = BigInteger.ZERO;
						maxProdNeg = BigInteger.ZERO;
					}
					if (maxProd == null)
						maxProd = (maxProdPos == BigInteger.ZERO) ? maxProdNeg : maxProdPos;
					else
						maxProd = maxProd.max(maxProdPos.max(maxProdNeg));
//					pr.printf("next:%5d max:%10s pos:%10s neg:%10s%n", next, maxProd.toString(), maxProdPos.toString(), maxProdNeg.toString());
				}
				pr.println(maxProd);
			}
		} catch (IOException ex) {}
		
		pr.close();
	}
}
