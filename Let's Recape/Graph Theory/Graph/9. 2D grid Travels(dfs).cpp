#include<bits/stdc++.h>
using namespace std ;

const int mx = 25;
char s[mx][mx];
int vis[mx][mx];
int h , w , cnt; // h = row , w = col

int dx[] = {+1 ,-1 ,+0 , -0};
int dy[] = {+0 ,-0 ,+1 , -1};

bool valid ( int x , int y )
{
    if( x >= 0 && x < h && y >= 0 && y < w && s[x][y]!= '#' && vis[x][y]!= 1 )
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

void dfs( int i , int j )
{
    vis[i][j] = 1 ;
    cnt++;
    for ( int k = 0 ; k < 4 ; k++ )
    {
        int x = i+dx[k];
        int y = j+dy[k];
        if ( valid(x,y))
        {
            dfs( x , y );
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t ;  cin>> t;
    for ( int i = 1 ; i <= t ; i++ )
    {
        memset(vis , 0 , sizeof(vis));
        cnt = 0 ;
       cin>> w >> h ;
       for ( int i = 0 ; i < h ; i++ )
       {
           for ( int j = 0 ; j < w ; j++ )
           {
               cin>> s[i][j];
           }
       }

       for ( int i = 0 ; i < h ; i++ )
       {
           for ( int j = 0 ; j < w ; j++ )
           {
               if ( s[i][j] == '@')
               {
                   dfs(i,j);
                   break ;
               }
           }
       }
       cout << "Case " << i << ": " << cnt << '\n';


    }


    return 0 ;
}

// Problem : https://lightoj.com/problem/guilty-prince