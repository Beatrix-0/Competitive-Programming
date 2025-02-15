    #include<bits/stdc++.h>
    using namespace std ;

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int t ;  cin>> t;
        for ( int i = 1 ; i <= t ; i++ )
        {

           int n , m ;
           cin>> n >> m ;
           set<string>a , b ;
           while ( n-- )
           {
               string x ; cin>> x ;
               a.insert(x);
           }
           while ( m-- )
           {
               string y ; cin>> y ;
               b.insert(y);
           }

           cout << "Case " << i << ":" << '\n';
           cout << "Jackal " << a.size() << '\n';
           cout << "Bari " << b.size() << '\n';
           a.clear();
           b.clear();
        }


        return 0 ;
    }
