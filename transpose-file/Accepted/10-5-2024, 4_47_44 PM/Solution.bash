// https://leetcode.com/problems/transpose-file

# Read from the file file.txt and print its transposed content to stdout.
while read -a line; do
    for ((i=0; i < "${#line[@]}"; i++)); do a[$i]="${a[$i]} ${line[$i]}"
    done
done < file.txt
for ((i=0; i < ${#a[@]}; i++)); do echo ${a[i]}
done
