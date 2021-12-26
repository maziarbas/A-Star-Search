#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>

using std::string;
using std::vector;
using std::istringstream;
using std::ifstream;
using std::cout;
using std::abs;
using std::sort;

enum class State{KEmpty, KObstacle,kClosed,KPath};

vector<State> ParseLine(string line)
{
    istringstream sline(line);
    int n;
    char c; 
    vector<State> row;

    while(sline>>n>>c && c==',')
    {
        if(n==0)
        {
            row.push_back(State::KEmpty);
        }
        else{
            row.push_back(State::KObstacle);
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path){
    ifstream board_file(path);
    vector<State> row{};
    vector<vector<State>> board{};
    string line;

    if(board_file){
        while(getline(board_file,line)){
            row=ParseLine(line);
            board.push_back(row);
        }
    }
    return board;    
}

// compares two nodes 
bool Compare(const vector<int> node1, const vector<int> node2){
    int node1_f_value = node1[2]+node1[3];
    int node2_f_value = node2[2]+node2[3];
    return node1_f_value>node1_f_value;
}

// calculates the manhatan distance as h value 
int Heuristic(int x1,int y1,int x2,int y2){
    return abs(x2-x1)+abs(y2-y1);
}
// sorts the open cells 
void CellSort(vector<vector<int>> *v){
    sort(v->begin(),v->end(),Compare);
}

void AddToOpen(int x, int y, int g, int h,vector<vector<State>> &grid, vector<vector<int>> &open){
    vector<int> node {x,y,g,h};
    open.push_back(node);
    grid[x][y]=State::kClosed;
}

// A* starts here above supports A* 
vector<vector<State>> Search (vector<vector<State>> grid ,int init[2], int goal[2]){
    vector<vector<int>> open{};
    int x = init[0];
    int y = init[1];
    int g=0;
    int h = Heuristic(x,y,goal[0],goal[1]);
    AddToOpen(x,y,g,h, grid, open);
    while(open.size()>0){
        CellSort(&open);
        auto current = open.back();
        open.pop_back();
        x=current[0];
        y=current[1];
        grid[x][y]=State::KPath;

        if(x==goal[0], y==goal[1]){
            return grid;
        }
    }
    cout<<"No path find"<<"\n";
    return  vector<vector<State>>{};
}

string CellString(State cell){
    switch(cell){
        case State::KEmpty:return "0   ";
        case State::KObstacle:return"⛰️   ";
    }}

void PrintBoard(const vector<vector<State>> board){
    for(int i=0;i<board.size(); i++){
        for(int j=0;j<board[i].size();j++){
            cout<<CellString(board[i][j]);
        }
        cout<<"\n";
    }}

int main(){
    int init[] = {0,0};
    int goal[]={4,5};
    vector<vector<State>> board = ReadBoardFile("1.board");
    vector<vector<State>> solution = Search(board,init,goal);
    PrintBoard(solution);
    
}
