# sudoku solver in c

## steps

- [x] lets get a basic c template working in c
- [x] we need a 9x9 grid that represents a sudoku board
- [x] and then lets populate that board with some hard coded values
- [x] and finally we make sure we can print out the sudoku puzzle on the screen 
- [x] lets put some borders on the grid so it is more readable
- [x] replace the 0 with '.' so it is more readable on screen
- [x] later we will replace those hard coded values with a real puzzle. let me
    grab one. hold on.
- [x] we still need to load this array pointer that contains the puzzle into
    the grid. so lets do that now. 
- [x] lets get a new func to check a cell and if a value is allwed in a cell.
    - [x] check 1: check that the number does not appear in that same row
    - [x] check 2: check that the number does not appear in that same col
    - [x] check 3: check that the number does not appear in the same box
    - given a row, col and a value. above 3 checks must be satisfied to pass. 
    - [x] we need some tests here for the ok() func.
        - [x] (0,2). r already has 8. c already has 3,1,8. box has 8,3,7. so 
            the only values left are: 2,4,6,9
        - [x] (5,5). r has 1,3. c has 5,7. box has 1,4,5,7. only candidates 
            allowed are: 2,6,8,9
- [x] ok. now we need to test each blank cell with all possible values from 1-9  
- [x] since for each cell, we run exactly the same function, we can write a 
    recursive function. lets call it solve().
- [x] after we iterate through each cell, and find a candidate, we write that
    1st candidate into that cell and move on. 
- [x] but if we are left with any cells not fillable while iterating through
    all cells, that implies that the previous cell was wrongly fille.
- [x] we then backtrack, and fill that cell in with the 2nd candidate. and then 
    continue in a similar fashion! 


### convert an index into a row and col number
- there are 9 rows and 9 cols
- after every 9 values in the array, a new row starts
- and every 9th value on is a new col
- r = pos / 9. due to c's integer math.
- c = pos % 9

pos     r       c
0       0       0
1       0       1
2       0       2
...

