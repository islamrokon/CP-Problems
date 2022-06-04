 #include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  //cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    priority_queue<int,vector<int> > small;
    priority_queue<int,vector<int>,greater<int> > big;
    int tmp;
    cin>>tmp;
    small.push(tmp);
    while(cin>>tmp){
        if(tmp>0){
            if(small.size()>big.size()){
                if(tmp>small.top()){
                    big.push(tmp);
                }
                else{
                    big.push(small.top());
                    small.pop();
                    small.push(tmp);
                }
            }
            else if(small.size()<big.size()){
                if(tmp>big.top()){
                    small.push(big.top());
                    big.pop();
                    big.push(tmp);
                }
                else{
                    small.push(tmp);
                }
            }
            else{
                if(tmp<small.top()){
                    small.push(tmp);
                }
                else{
                    big.push(tmp);
                }
            }
        }
        else if(tmp==-1){
            if(small.size()>big.size()){
                cout<<small.top()<<'\n';
                small.pop();
            }
            else if(small.size()==big.size()){
                cout<<small.top()<<'\n';
                small.pop();
                small.push(big.top());
                big.pop();
            }
            else{
                cout<<big.top()<<'\n';
                big.pop();
            }
        }
        else{
            if(t)
                cout<<'\n';
            break;
        }
    }
  }
}
