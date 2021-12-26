#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>

using std::string;
using std::vector;
using std::istringstream;
using std::ifstream;
using std::cout;
using std::abs;

enum class State{KEmpty, KObstacle};

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

vector<vector<State>> ReadBoardFile(string path)
{
    ifstream board_file(path);
    vector<State> row{};
    vector<vector<State>> board{};
    string line;

    if(board_file){

        while(getline(board_file,line))
        {
            row=ParseLine(line);
            board.push_back(row);
        }
    }
    return board;    
}

int Heuristic(int x1,int y1,int x2,int y2)
{
    return abs(x2-x1)+abs(y2-y1);
}

// A* starts here above supports A* 
vector<vector<State>> Search (vector<vector<State>> board ,int start[2], int goal[2])
{
    vector<vector<State>> path_vector{};
    cout<<"No path find"<<"\n";

    return  path_vector;
}



string CellString(State cell)
{
    switch(cell){
        case State::KEmpty:return "0   ";
        case State::KObstacle:return"⛰️   ";
    }
}
void PrintBoard(const vector<vector<State>> board){
    for(int i=0;i<board.size(); i++){
        for(int j=0;j<board[i].size();j++){
            cout<<CellString(board[i][j]);
        }
        cout<<"\n";
    }

}

int main()
{
    int init[] = {0,0};
    int goal[]={4,5};
    vector<vector<State>> board = ReadBoardFile("1.board");
    vector<vector<State>> solution = Search(board,init,goal);
    PrintBoard(solution);
    
}
