#include <bits/stdc++.h>
using namespace std; int
size_of_grid, b, a, cnt = 0; int
arr[128][128];
// Placing tile at the given coordinates
void place(int x1, int y1, int x2,
int y2, int x3, int y3)
{ cnt++;
arr[x1][y1] = cnt;
arr[x2][y2] = cnt;
arr[x3][y3] = cnt;
} int tile(int n, int x, int
y)
{
 int r, c;
 if (n == 2) {
 cnt++;
 for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
    if (arr[x + i][y + j] == 0) {
arr[x + i][y + j] = cnt;
 }
 }
}
return 0;
 }
 // finding vaccant location
 for (int i = x; i < x + n; i++) {
for (int j = y; j < y + n; j++) {
if (arr[i][j] != 0)
 r = i, c = j;
 }
 }
 // If missing tile is 1st quadrant
 if (r < x + n / 2 && c < y + n / 2)
 place(x + n / 2, y + (n / 2) - 1, x + n / 2,
y + n / 2, x + n / 2 - 1, y + n / 2);
// If missing Tile is in 3rd quadrant
else if (r >= x + n / 2 && c < y + n / 2)
place(x + (n / 2) - 1, y + (n / 2), x + (n / 2),
y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1);
// If missing Tile is in 2nd quadrant
else if (r < x + n / 2 && c >= y + n / 2)
place(x + n / 2, y + (n / 2) - 1, x + n / 2,
y + n / 2, x + n / 2 - 1, y + n / 2 - 1);
// If missing Tile is in 4th quadrant
else if (r >= x + n / 2 && c >= y + n / 2)
place(x + (n / 2) - 1, y + (n / 2), x + (n / 2),
y + (n / 2) - 1, x + (n / 2) - 1,
 y + (n / 2) - 1);

 // dividing it again in 4 quadrants
tile(n / 2, x, y + n / 2);
 tile(n / 2, x, y);
 tile(n / 2, x + n / 2, y);
 tile(n / 2, x + n / 2, y + n / 2);
return 0;
} int main()
{
 size_of_grid = 8;
memset(arr, 0, sizeof(arr));
 a = 0, b = 0; arr[a][b] = -1;
tile(size_of_grid, 0, 0);
for (int i = 0; i < size_of_grid; i++)
{
 for (int j = 0; j < size_of_grid; j++)
cout << arr[i][j] << " \t";
cout << "\n";
 }
}