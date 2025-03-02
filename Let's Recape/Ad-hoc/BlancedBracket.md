# Blanced Bracket 
Problem : D - Colorful Bracket Sequence ( Atcoder )
```
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    stack<char> st;

    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if((s[i]=='(')||(s[i]=='[')||(s[i]=='<'))st.push(s[i]);
        else{
            bool ok=false;
            if(st.empty()){
              cout<<"No"<< '\n';
                return 0;
            }
            if((s[i]==')')&&(st.top()!='('))ok=true;
            if((s[i]==']')&&(st.top()!='['))ok=true;
            if((s[i]=='>')&&(st.top()!='<'))ok=true;
            if(ok){
                cout<<"No"<< '\n';
                return 0;
            }
            st.pop();
        }
    }
    if(st.empty())cout<<"Yes"<< '\n';
    else cout<<"No"<< '\n';
}
```