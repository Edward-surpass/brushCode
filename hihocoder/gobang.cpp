#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int Col(vector<vector<char>> &a,int n ,int m,int x,int y,int &flag)
{
    int num = flag = 0;
    for(int left = 1;left < 5;++left)
    {
        if(x-left >= 0) 
        {
            if(a[x-left][y] == '1')
            {
                ++num;
            }
            else{
                if(a[x-left][y] != ' ')
                    ++flag;
                break;
            }
        }
        else
        {
           ++flag; 
        }
    }
    for(int right = 1;right < 5;++right)
    {
        if(x+right < n) 
        {
            if(a[x+right][y] == '1')
            {
                ++num;
            }
            else{
                if(a[x+right][y] != ' ')
                    ++flag;
                break;
            }
        }
        else
        {
           ++flag; 
        }
    }
    return num;
}
int Row(vector<vector<char>> a,int n,int m,int x,int y,int &flag)
{
    int num = flag = 0;
    for(int left = 1;left < 5;++left)
    {
        if(y-left >= 0) 
        {
            if(a[x][y-left] == '1')
            {
                ++num;
            }
            else{
                if(a[x][y-left] != ' ')
                    ++flag;
                break;
            }
        }
        else
        {
           ++flag; 
        }
    }
    for(int right = 1;right < 5;++right)
    {
        if(y+right < m) 
        {
            if(a[x][y+right] == '1')
            {
                ++num;
            }
            else{
                if(a[x][y+right] != ' ')
                    ++flag;
                break;
            }
        }
        else
        {
           ++flag; 
        }
    }
    return num;
}
int angek45(vector<vector<char>> a,int n ,int m,int x,int y,int &flag)
{
    int num = flag = 0;
    for(int left = 1;left < 5;++left)
    {
        if(x-left >= 0 && y-left >=0) 
        {
            if(a[x-left][y-left] == '1')
            {
                ++num;
            }
            else{
                if(a[x-left][y-left] != ' ')
                    ++flag;
                break;
            }
        }
        else
        {
           ++flag; 
        }
    }
    for(int right = 1;right < 5;++right)
    {
        if(x+right < n && y+right < m) 
        {
            if(a[x+right][y +right] == '1')
            {
                ++num;
            }
            else{
                if(a[x+right][y +right] != ' ')
                    ++flag;
                break;
            }
        }
        else
        {
           ++flag; 
        }
    }
    return num;
}
int angek135(vector<vector<char>> a,int n ,int m,int x,int y,int &flag)
{
    int num = flag = 0;
    for(int left = 1;left < 5;++left)
    {
        if(x-left >= 0 && y+left < m) 
        {
            if(a[x-left][y+left] == '1')
            {
                ++num;
            }
            else{
                if(a[x-left][y+left] != ' ')
                    ++flag;
                break;
            }
        }
        else
        {
           ++flag; 
        }
    }
    for(int right = 1;right < 5;++right)
    {
        if(x+right < n && y-right >= 0) 
        {
            if(a[x+right][y +right] == '1')
            {
                ++num;
            }
            else{
                if(a[x+right][y +right] != ' ')
                    ++flag;
                break;
            }
        }
        else
        {
           ++flag; 
        }
    }
    return num;
}
int main()
{
    int n,m;
    cin >>n >>m;
    vector<vector<char> > a(10,vector<char>(10,' '));
    cin.get();
    for(int i=0;i<n;++i)
    {
        string temp;
        getline(cin,temp);
        for(int j=0;j<m;++j)
        {
            a[i][j] = temp[j];
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int flag = 0,allflag = 0,num;
            num= Row(a,n,m,i,j,flag);
            if(num >= 4)
            {
                cout << "YES" << endl;
                return 0;
            }
            else if(num ==3)
            {
                if(flag == 0)
                {
                    cout << "YES" << endl;
                    return 0;
                }
                else if(flag == 1)
                    allflag += flag;
            }
            num= Col(a,n,m,i,j,flag);
            if(num >= 4)
            {
                cout << "YES" << endl;
                return 0;
            }
            else if(num ==3)
            {
                if(flag == 0)
                {
                    cout << "YES" << endl;
                    return 0;
                }
                else if(flag == 1)
                    allflag += flag;
            }
            num= angek45(a,n,m,i,j,flag);
            if(num >= 4)
            {
                cout << "YES" << endl;
                return 0;
            }
            else if(num ==3)
            {
                if(flag == 0)
                {
                    cout << "YES" << endl;
                    return 0;
                }
                else if(flag == 1)
                    allflag += flag;
            }
            num= angek135(a,n,m,i,j,flag);
            if(num >= 4)
            {
                cout << "YES" << endl;
                return 0;:
            }
            else if(num ==3)
            {
                if(flag == 0)
                {
                    cout << "YES" << endl;
                    return 0;
                }
                else if(flag == 1)
                    allflag += flag;
            }
            if(allflag >=2)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return -1;
}
