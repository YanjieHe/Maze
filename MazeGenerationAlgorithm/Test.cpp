#include "Test.hpp"
#include "Kruskal.hpp"
#include "Prim.hpp"
#include "RecursiveBacktracker.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;
void TestRecursiveBacktracker()
{
    cout << "start" << endl;
    int rows = 100;
    int cols = 100;
    RecursiveBacktracker tracker(rows, cols, 10);
    tracker.BackTrack(0);
    tracker.WriteToFile("maze_backtracker.txt");
    std::system("../"
                "build-MazeGUI-Desktop-Debug/MazeGUI maze_backtracker.txt &");
    cout << "finished" << endl;
}

void TestKruskal()
{
    cout << "start kruskal" << endl;
    int rows = 100;
    int cols = 100;
    Kruskal kruskal(rows, cols, 10);
    kruskal.Generate();
    kruskal.WriteToFile("maze_kruskal.txt");
    std::system("../"
                "build-MazeGUI-Desktop-Debug/MazeGUI maze_kruskal.txt &");
    cout << "finished" << endl;
}

void TestPrim()
{
    cout << "start prim" << endl;
    int rows = 100;
    int cols = 100;
    Prim prim(rows, cols, 10);
    prim.Generate();
    prim.WriteToFile("maze_prim.txt");
    std::system("../"
                "build-MazeGUI-Desktop-Debug/MazeGUI maze_prim.txt &");
    cout << "finished" << endl;
}
