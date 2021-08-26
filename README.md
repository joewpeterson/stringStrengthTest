stringStrenthTest is code motivated by a job interview. The question was:

You have M identical ropes and N identical weights. You want to do an experiment
to determin the strength S of the identical ropes by testing how many weights
can be held by one single rope.  The strength S of the ropes is an iterger:
	1) if a rope breaks with the first weight, S=0
	2) if a from can hold n weights but breaks with n+1 weights, S=1
	3) if a rope can hold N weights, S=N
In one test (a check of how much weight the string can carry) if the rope breaks
you have to take another rope and continue the experiment. If all M ropes break
before you have identified the S, the test fails

Write a C/C++ program which:
	Given M and N, calculates the minimum number of tests, T, needed to 
	guarantee you can determine S. Try to optimize the time complexity

/******************************************************************************/
Note on my choise of language:
	I choose C++ because most of my work is done in C and I have found 
	prospective employers don't like that much. This gives me a small
	oportinuty to show I can also C++. The most import C++ specific tool I
	use here are smart pointers.

Assumption:
	I assume that simple table lookup is not what you are looking for. At
	the very least you would like to see how one builds the table. I do
	this and implement a recursive algorithm which runs a little faster for
	small N.

Note on my recursive algorithm:
	I find my answer by supposing a function exists which, given M strings
	and T tests, it returns the maximum weight (MW) that can be searched
	for where I can determine S in the worst case. If N lies between two
	successive MWs, chosen from M strings and (t, t+1) tests, than than the
	higher of two will give the smallest number of tests which with
	gaurantee I can find the answer. 

	As to the construction of the function MW(T, N); I'll choose to start
	a test with some weight. There are two outcomes of the test: either 
	the string breaks or it does not. if it breaks, I will have one less 
	test and one less string with a search space below my initial test. If
	it does not break, I will have one less test and N strings to search
	the space above the test weight. So the recursive equation to determine
	MW is:

		MW = MW(T-1, N) //search space if first test does not break
		     + MW(T-1, N-1) //search space if first test does break
		     + 1 //current weight determined.

	I found that with some coarsening, this routine ran fast for upwords
	of N = 1000 relative to a routine which builds a table.
	
Note on my table search routine:
	After N = 1000, the recursive algorithm slows down. If you build a 
	table of outputs for MW you see a patern:

	MW + 1
	T\M	0	1	2	3	4	
	------------------------------------------
	0	1	1	1	1	1
	1	1	2	2	2	2
	2	1	3	4	4	4
	3	1	4	7	8	8
	4	1	5	11	15	16

	MW + 1 is the sum of two smaller MWs (specifically, MW(T-1, N) and
	MW(T-1, N-1)). One can construct subsequent layers of the table with 
	a small number of sums rather than with a recursive call. 

	One reason this is routine is not faster than the recursive routine
	for smaller numbers of N is that I do one expensive check which saves
	a lot of time if the user enters a bad M. With an infinite number of
	tests we know to use binomial search. But this will only use log2(N)
	strings. So M=log2(N) is effectively infinite strings. If the user
	enters a very large number for M, there is no reason to contruct the
	table to M, rather one constructs the table to log2(N).

