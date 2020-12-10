# remove_duplicates_from_an_array
remove duplicates from an unsorted array

The algorithm starts from the first element of the array, blocks it and start counting from the end of the array with the counter j, going down until j becomes equal to i.
The algorithm checks if the element in position j is equal to the element locked in position i, if it finds a duplicate, the algorithm has 2 choices:
 - if j is equal to (n-1) - delete (ie if j is equal to the last element of the array to be "checked" (- delete is used to exclude the cells already checked)) then it is not necessary to move any cell and the 'delete' variable is increased by 1 ('delete' takes into account how many cells to delete);
 - otherwise we cycle the array with a new counter k, starting from position j (where the duplicate is) and start moving the elements of the array back one position, stopping at the last "right" cell, which we find thanks to (n-1) - delete. Once the movements are finished, 'delete' variable is increased by 1.

The algorithm continues to search for duplicates for the value locked in position i, if it does not find any, it goes to the next i, if it finds a new duplicate for i, it repeats the procedure
