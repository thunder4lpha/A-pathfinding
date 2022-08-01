#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Point
{
    public:
    int x, y;
    Point(int a, int b) {
        x = a; y = b;
    }
};

int sqr(int a) { return a*a; }

int distance(Point a, Point b) {
    return sqrt(sqr(a.x - b.x)+sqr(b.y - a.y));
}

vector<Point> findPath(Point current, Point target, vector<vector<char>> grid, vector<Point> path) {
    // Recursive function for A* algorithm
    path.push_back(current);
    if (current.x == target.x && current.y == target.y) {
        return path;
    }

    // Check around
    int min_dist = 90;
    Point dir(0, 0);
    // Check left
    Point left(current.x-1, current.y);
    if (current.x > 0 && distance(left, target) < min_dist && grid[left.y][left.x] != 'b') {
        min_dist = distance(left, target);
        dir = left;
    }
    // Check right
    Point right(current.x+1, current.y);
    if (current.x < 5 && distance(right, target) < min_dist && grid[right.y][right.x] != 'b') {
        min_dist = distance(right, target);
        dir = right;
    }
    // Check up
    Point up(current.x, current.y-1);
    if (current.y > 0 && distance(up, target) < min_dist && grid[up.y][up.x] != 'b') {
        min_dist = distance(up, target);
        dir = up;
    }
    // Check down
    Point down(current.x, current.y+1);
    if (current.y < 4 && distance(down, target) < min_dist && grid[down.y][down.x] != 'b') {
        min_dist = distance(down, target);
        dir = down;
    }
    return findPath(dir, target, grid, path);
}

int main() {
    vector<vector<char>> grid = {
        { 's','-','-','-','-','-' },
        { '-','-','-','-','-','-' },
        { '-','-','-','b','-','-' },
        { '-','-','b','b','-','-' },
        { '-','-','-','-','-','t' }
    };
    
    Point start(0, 0);
    Point target(5, 4);

    vector<Point> path;
    path = findPath(start, target, grid, path);
    for (int i=0; i<path.size(); i++) {
        cout << path[i].x << ' ' << path[i].y << endl;
    }

    return 0;
}