// https://leetcode.com/problems/tenth-line

# Read from the file file.txt and output the tenth line to stdout.
#Explanation of above :-
#-n --> denotes number of lines
#tail -n --> outputs last 10 lines of file by default
#tail -n+10 --> data will start printing from line number 10 till the end of the file
#| --> pipe operator used for passing data to next command
#head -n --> outputs first 10 lines of file by default
#head -n 1 --> starting from first line outputs 1 line instead of 10 by default
tail -n+10 file.txt | head -n 1