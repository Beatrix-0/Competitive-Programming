
#include <bits/stdc++.h> // Logic + Code
using namespace std;

bool cmp(pair<int,int>a,pair<int,int> b)
{
    if (a.first!=b.first) // dui ta value soman na hole value jeta boro ota age jabe
    {
        return a.first>b.first;
    }
    else // jodi soman hoy tahole index jeta choto ota age jabe
    {
        return a.second < b.second;
    }
}



int main()
{
   int t ;
   cin>> t ;
   while ( t-- )
   {
       int n , k;
       cin>>n >>k ;
       vector<int>v(n);
       for ( int i = 0 ; i< n ; i++ )
       {
           cin>> v[i];

           v[i] = v[i] % k ;
       }

       vector<int>ans;
       vector < pair< int,int >> chk;

           for ( int i = 0 ; i< n ; i++ )
           {
               if ( v[i] == 0 )
               {
                   ans.push_back( i + 1 );
               }
               else
               {
                   chk.push_back({v[i] , i + 1 });
               }
           }

           sort ( chk.begin() , chk.end() , cmp ); // cmp call korar karon ami nijer moto customize kore sort korbo , default vabe na kore

           for ( auto it : chk )
           {
               ans.push_back(it.second);
           }

           for ( auto it : ans  )
           {
               cout << it << " ";
           }
           cout << '\n';

   }

    return 0;
}

/*
Video link : https://youtu.be/zLG9fnYRuwE?feature=shared
Logic :
    1. 1st e sob golar mod ber korbo , mod jodi 0 hoy tahole buja jabe segola age remove hobe , tai ogolar moddhe kono
    operation er dorkar nai, just index golo ans vector e store korbo
    2. ekta pair thakbe jekhane bakigolor value and index store hobe
    3. then value onojaiye pair k sort korbo , cmp function call kora hoyeche kon index age jabe decide korar jonno
    4. tarpor sort value golor index ans vector e push korbo ... last e ans print korbo

    NOTE : index and value niye eksathe kaj korte hole pair use kora lage ***
*/
