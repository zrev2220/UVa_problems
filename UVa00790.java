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
		int N = in.nextInt();
		in.nextLine(); in.nextLine();
		while (N-- > 0)
		{
			TreeMap<Integer, Team> teams = new TreeMap<>();
			try
			{
				String inline = br.readLine();
				while (!inline.equals("") && br.ready())
				{
					String[] input = inline.split(" ");
					int id = Integer.parseInt(input[0]);
					char prob = input[1].charAt(0);
					String timeString = input[2];
					boolean passed = input[3].equals("Y");
					
					int time = 60 * Integer.parseInt(timeString.substring(0, 1)) + Integer.parseInt(timeString.substring(2, 4));
					teams.putIfAbsent(id, new Team(id));
					teams.get(id).submission(prob, time, passed);
					
					inline = br.readLine();
				}
			}
			catch (Exception ex)
			{
				err.println("ERROR: " + ex.getMessage());
				System.exit(1);
			}
			ArrayList<Team> sortedTeams = new ArrayList<>(teams.values());
			Collections.sort(sortedTeams);
			pr.println("RANK TEAM PRO/SOLVED TIME");
			for (int i = 0, rank = 1; i < sortedTeams.size(); ++i)
			{
				if (i != 0)
				{
					if (sortedTeams.get(i).compareTo(sortedTeams.get(i - 1)) != 0)
					{
						rank = i + 1;
					}
				}
				pr.printf("%4d %s%n", rank, sortedTeams.get(i).toString());
			}
		}
		
		pr.close();
	}
}

class Team implements Comparable<Team>
{
	public int id;
	public TreeMap<Character, Integer> problems = new TreeMap<>();
	public int nSolved;
	public int totalTime;
	
	public Team(int _id)
	{
		this.id = _id;
		this.nSolved = 0;
		this.totalTime = 0;
	}
	
	public void submission(char prob, int time, boolean passed)
	{
		int curTime = problems.getOrDefault(prob, 0);
		if (passed)
		{
			problems.put(prob, -1 * curTime + time);
			++nSolved;
			totalTime += -1 * curTime + time;
		}
		else
			problems.put(prob, curTime - 20);
	}
	
	@Override
	public String toString()
	{
		return String.format("%4d %4s       %4s", id, (nSolved != 0) ? String.valueOf(nSolved) : "", (totalTime != 0) ? String.valueOf(totalTime) : "");
	}
	
	@Override
	public int compareTo(Team other)
	{
		if (this.nSolved == other.nSolved)
			return this.totalTime - other.totalTime;
		return other.nSolved - this.nSolved;
	}
}
