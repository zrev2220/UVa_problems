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
		int N = 1;
		try
		{
			N = Integer.parseInt(br.readLine());
			br.readLine();
		}
		catch (IOException ex)
		{
			err.println("ERROR: " + ex.getMessage());
			System.exit(1);
		}
		while (N-- > 0)
		{
			TreeMap<Integer, Team> teams = new TreeMap<>();
			int maxId = 0;
			try
			{
				String inline = br.readLine();
				while (inline != null && !inline.equals(""))
				{
					String[] input = inline.split(" ");
					int id = Integer.parseInt(input[0]);
					maxId = Math.max(maxId, id);
					char prob = input[1].charAt(0);
					String timeString = input[2];
					boolean passed = input[3].equals("Y");
					
					int time = 60 * Integer.parseInt(timeString.substring(0, 1)) + Integer.parseInt(timeString.substring(2, 4));
					teams.putIfAbsent(id, new Team(id));
					teams.get(id).submission(prob, time, passed);
					
					inline = br.readLine();
				}
			}
			catch (IOException ex)
			{
				err.println("ERROR: " + ex.getMessage());
				System.exit(1);
			}
			for (int i = 0; i < maxId; ++i)
				teams.putIfAbsent(i + 1, new Team(i + 1));
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
			if (N != 0)
				pr.println();
		}
		
		pr.close();
	}
}

class Team implements Comparable<Team>
{
	public int id;
	public TreeMap<Character, TreeSet<Integer>> problems = new TreeMap<>();
	public int nSolved;
	public HashSet<Character> solvedProblems = new HashSet<>();
	public int totalTime;
	
	public Team(int _id)
	{
		this.id = _id;
		this.nSolved = 0;
		this.totalTime = 0;
	}
	
	public void submission(char prob, int time, boolean passed)
	{
		TreeSet<Integer> subs;
		if (problems.containsKey(prob))
			subs = problems.get(prob);
		else
		{
			subs = new TreeSet<>();
			problems.put(prob, subs);
		}
		if (passed && !solvedProblems.contains(prob))
		{
			if(!subs.add(time))
				totalTime += 20;
			++nSolved;
			solvedProblems.add(prob);
			subs = new TreeSet<>(subs.headSet(time, true));
			totalTime += subs.headSet(subs.last()).size() * 20 + subs.last();
		}
		else if (passed && solvedProblems.contains(prob))
		{
			totalTime -= subs.headSet(subs.last()).size() * 20 + subs.last();
			subs.add(time);
			if (subs.size() != 1)
				subs.remove(subs.last());
			totalTime += subs.headSet(subs.last()).size() * 20 + subs.last();
		}
		else if (!passed && solvedProblems.contains(prob))
		{
			if (time <= subs.last())
				totalTime += 20;
		}
		else if (!passed && !solvedProblems.contains(prob))
			subs.add(time);
	}
	
	@Override
	public String toString()
	{
		if (nSolved == 0)
			return String.format("%4d", id);
		return String.format("%4d %4d       %4d", id, nSolved, totalTime);
	}
	
	@Override
	public int compareTo(Team other)
	{
		if (this.nSolved == other.nSolved)
			return this.totalTime - other.totalTime;
		return other.nSolved - this.nSolved;
	}
}
