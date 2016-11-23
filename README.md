# AI Bot for the game of Tak
Code for AI bot, for playing a game of Tak. <a href="https://en.wikipedia.org/wiki/Tak_(game)">Tak</a> is a recent game taken from the The Kingkiller chronicle is a board game and a game of strategy. The bot we have developed is part of an assignment for <a href="http://www.cse.iitd.ac.in/~mausam/courses/col333/autumn2016/">COL333</a> Intro. to AI course.

To make the bot play against itself call the following scripts in the same order:
./server.sh <PortNo>
./player1.sh <PortNo>
./player2.sh <PortNo>

We have used minimax search with alpha beta pruning and used some manually crafted heuristics, designed specifically for the game of Tak.



