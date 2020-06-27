#include <bits/stdc++.h>
#define pereche pair<int,int>
#define x first
#define y second
using namespace std;

ifstream fin("cuvinte.in");
ofstream fout("cuvinte.out");
//------------------------------------------
const int dx[]= {1,0};
const int dy[]= {0,1};
vector<string>words;
string word;
int numberOfWords,rows,cols;
int solved;
char mat[1000][1000];
pereche pos[51][1000];
//------------------------------------------
void DeleteWord(int index)
{
    int length=words[index].size();
    for(int i=0;i<length;i++)
    {
        mat[pos[index][i].x][pos[index][i].y]=NULL;
        pos[index][i].x=pos[index][i].y=0;
    }
}
//------------------------------------------
void InsertWord(int index,int xpos,int ypos,int dir)
{
    int length=words[index].size();
    for(int i=0;i<length;i++)
    {
        mat[xpos][ypos]=words[index][i];
        pos[index][i].x=xpos;
        pos[index][i].y=ypos;
        xpos+=dx[dir];
        ypos+=dy[dir];
    }
}
//------------------------------------------
int ValidPlace(int index,int xpos,int ypos,int dir)
{
    int length=words[index].size();
    if(dir==0){if(xpos+length-1>rows)return 0;}
    else if(ypos+length-1>cols)return 0;
    for(int i=0; i<length; i++)
    {
        if(mat[xpos][ypos] && mat[xpos][ypos]!=words[index][i])return 0;
        xpos+=dx[dir];
        ypos+=dy[dir];
    }
    return 1;
}
//------------------------------------------
void PrintMatrix()
{
    solved=1;
    for(int i=0;i<numberOfWords;i++)
    {
        for(int j=0;j<words[i].size();j++)
        {
            mat[pos[i][j].x][pos[i][j].y]=words[i][j];
        }
    }
    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=cols; j++)
        {
            if(mat[i][j]==NULL)fout<<"-";
            else fout<<mat[i][j];
        }
        fout<<'\n';
    }
}
//------------------------------------------
void solve(int index)
{
    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=cols; j++)
        {
            for(int k=0; k<=1; k++)
            {
                if(solved)return;
                if(ValidPlace(index,i,j,k))
                {
                    InsertWord(index,i,j,k);
                    if(index==numberOfWords-1)PrintMatrix();
                    else solve(index+1);
                    DeleteWord(index);
                }
            }
        }
    }
}
//------------------------------------------
int main()
{
    fin>>numberOfWords;
    fin>>rows>>cols;
    for(int i=1; i<=numberOfWords; i++)
    {
        fin>>word;
        words.push_back(word);
    }
    solve(0);
    return 0;
}
