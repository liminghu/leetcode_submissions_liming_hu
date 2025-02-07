// https://leetcode.com/problems/transpose-file

# Read from the file file.txt and print its transposed content to stdout.
ncol=`head -n1 file.txt | wc -w`

for i in `seq 1 $ncol` do echo `cut -d' ' -f$i file.txt`