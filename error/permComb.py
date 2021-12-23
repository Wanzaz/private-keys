# A Python program to print all
# permutations using library function
from itertools import permutations
 
# Get all permutations of [1, 2, 3]
perm = permutations([1, 2, 3])
 
# Print the obtained permutations
for i in list(perm):
    print (i)


#I discoverd that was not possible put all the 4 790 016 combinations in one array and test it after that
#It brokes if there is the 12 numbers and 7 numbers on one line.
#It can only print the combinations with 12, 6 and that is 924 combinations and after that it goes down 
