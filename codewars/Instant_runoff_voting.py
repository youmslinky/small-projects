voters = [["dem", "ind", "rep"],
		  ["dem", "ind", "rep"],
		  ["rep", "ind", "dem"],
		  ["rep", "ind", "dem"],
		  ["rep", "ind", "dem"],
		  ["ind", "dem", "rep"],
		  ["ind", "dem", "rep"],
		  ["ind", "dem", "rep"]]

voters_majority = [["dem", "ind", "rep"],
		  ["rep", "ind", "dem"],
		  ["ind", "dem", "rep"],
		  ["ind", "rep", "dem"],
		  ["ind", "rep", "dem"]]

voters_letters = [["a", "c", "d", "e", "b"],
		          ["e", "b", "d", "c", "a"],
		          ["d", "e", "c", "a", "b"],
		          ["d", "e", "c", "b", "a"],
		          ["a", "e", "b", "c", "d"]];


def runoff(voters):
    #initialize tally with all candidates
	tally=dict((k,0) for k in voters[0])

	while len(tally)>1:
        #tally votes
		for ballot in voters:
			for selection in ballot:
				if selection in tally:
					tally[selection]+=1
					break

		#check if anyone has majority
		for candidate,votes in list(tally.items()):
			if float(votes)/len(voters) > .5:
				return candidate

		#if there is a tie, no one wins
		leastVotes=min(tally.values())
		mostVotes=max(tally.values())
		if mostVotes == leastVotes:
			return None

		#remove candidates with least amount of votes
		for candidate,votes in list(tally.items()):
			if votes==leastVotes:
				del tally[candidate]

		#reset tally to 0 for all candiates
		for candidate,votes in list(tally.items()):
			tally[candidate]=0

	return list(tally.keys())[0]


print((runoff(voters)))

