#include<bits/stdc++.h> // Code 
using namespace std;
int main ()
{
    
    int t;
    cin>> t ;
    while ( t-- )
    {
        int n ;
        cin>>n ;
        string a ;
        cin>> a ;
        
        vector < int > pref( n , 0 ), suff( n , 0 );
        set < char > st ;
        
        // calculating prefix  
        for ( int i = 0 ; i < n ; i++ )
        {
            st.insert(a[i]);
            pref[i] = st.size();
            
        }
        // clear korar karon next e jeno suffix golo claculate korte pari .. nahole prefix golo o ad hobe 
        st.clear();
        
        // calculating suffix 
        
        for ( int i = n-1 ; i >= 0 ; i-- )
        {
            st.insert(a[i]);
            suff[i] = st.size();
            
        }
        int ans = 0 ;
        for ( int i = 0 ; i< n-1 ; i++ )
        {
            ans = max ( ans , pref[i] + suff[i+1] );
        }
        
        
        cout << ans << '\n';
    }

    return 0;
}

/*
Video : https://youtu.be/74gh6bV2vwM?feature=shared

*/