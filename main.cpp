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

vector<vector<State>> Search (int start[2], int goal[2])
{
    vector<vector<State>> path_vector{};
    cout<<"No path find"<<"\n";

    return  path_vector;
}

int main()
{
    

}
