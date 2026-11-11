#include <stdio.h>

int g[9][9];

// lets move the print func to a separate func
void show(void) {
  // for each row, we print all cols and then move to the next row
  for (int r = 0; r < 9; r++) {
    // for every 3 rows, we need a horizontal separator
    if (r % 3 == 0) {
      printf("+-------+-------+-------+\n");
    }
    // print the col first
    for (int c = 0; c < 9; c++) {
      if (c % 3 == 0) { // col separators
        printf("| ");
      }
      if (g[r][c] != 0) {
        printf("%d ", g[r][c]);
      } else {
        printf("%s ", ".");
      }
    }
    printf("| \n");
  }
  printf("+-------+-------+-------+\n");
}

int ok(int r, int c, int n) {
  // given a row and col, we know the cell. From the cell we must find a
  // consistent way to iterate across the whole box that the cell belongs to.
  // step 1: lets find the bounding edge, top left, of that given cell.
  int br = r / 3 * 3; // 1 box has 3 rows. so we get 3 groups. x3 gives row num
  int bc = c / 3 * 3; // same but for col.

  for (int i = 0; i < 9; i++) {
    // checks: same row. same col. we still need a box check.
    // we take the box top left bound and need to go thru 3 rows and 3 cols. And
    // we already saw how to do that below.
    if (g[r][i] == n || g[i][c] == n || g[br + i / 3][bc + i % 3] == n) {
      return 0;
    }
  }
  return 1;
}

int solve(int pos) {
  // terminating condition first!
  if (pos == 81) {
    return 1;
  } // ok!

  // get row and col number.
  int r = pos / 9;
  int c = pos % 9;

  // also, never check a cell with values in it (from the puzzle).
  if (g[r][c] != 0) {
    return solve(pos + 1); // skip to the next cell.
  }

  // lets iterate through 1-9 and check each cell
  for (int n = 1; n <= 9; n++) {
    if (ok(r, c, n)) {
      g[r][c] = n; // we fill the cell with the value first.
      // first we must continue to next cell.
      if (solve(pos + 1)) {
        return 1;
      }
    }
  }

  // but first we backtrack and enter 0 in that prev cell
  g[r][c] = 0;
  return 0;
}

int main() {
  // the puzzle!
  const char *p = "800000000"
                  "003600000"
                  "070090200"
                  "050007000"
                  "000045700"
                  "000100030"
                  "001000068"
                  "008500010"
                  "090000400";

  // load the puzzle into the grid. from index 0-80.
  for (int pos = 0; pos < 81; pos++) {
    // 1. convert a idx into a row and col. 2. convert the value into a digit.
    g[pos / 9][pos % 9] = p[pos] - '0';
  }

  show(); // before

  solve(0); // we pass in the first index and the recursive func calls itself.

  show(); // after
}
