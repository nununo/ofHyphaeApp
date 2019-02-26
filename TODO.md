- Your branch and 'origin/master' have diverged?
- Get rid of apple core: tendency to have more hypha in the 4 diagonals. But how?
- Make each Hypha have its own ofNoise offset again
- Replace Hyphae.removeAllHypha() with a dieEvent. This way much less time is wasted asking every single Hypha if it is alive

- At 4K@30fps I have performance issues which must be solved (there is even a sudden jump forward at some point)  
- Changing the framerate to 10 results in much less forks. Why?
- Allow to fade to black also
- Review Hypha nextForkDistance
- Implement proper state machine to manage hyphae lifecycle
- Same params still don't generate the exact same Hypha

- Make Hypha alpha inversely proportional to log(params.maxHyphaCount)?
- Convert other settings into sets
- Try to make Hyphae looks not depend on its growth speed

- Save set of parameters to file?
- Load set of parameters from file?
