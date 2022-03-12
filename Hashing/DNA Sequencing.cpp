#include<bits/stdc++.h>
#define ll unsigned long long
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M 1000000
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
#define base 31
using namespace std;
ll h[M],h1[M];
ll hval,po[M];
unordered_map<ll,ll>ump;
vector<ll>vec;
vector<string>vec1,vec2;
bool first=1;
/*void display()
{
    if(!first)
        cout<<"\n";
    first=0;
    for(auto x:vec2)
        cout<<x<<'\n';
}*/
void hashvalcheck(string &ss)
{
    h1[0]=ss[0]-'a'+1;
    if(ump.find(h1[0])!=ump.end())
        vec.push_back(h1[0]);
    for(int i=1; i<ss.size(); i++)
    {
        h1[i]=h1[i-1]*base+ss[i]-'a'+1;
        if(ump.find(h1[i])!=ump.end())
            vec.push_back(h1[i]);
        for(int j=0; j<=i-1; j++)
        {
            hval=h1[i]-h1[j]*po[i-j];
            if(ump.find(hval)!=ump.end())
                vec.push_back(hval);
        }
    }
}
void hashval(string &s)
{
    h[0]=s[0]-'a'+1;
    ump[h[0]]++;
    for(int i=1; i<s.size(); i++)
    {
        h[i]=h[i-1]*base+s[i]-'a'+1;
        ump[h[i]]++;
        for(int j=0; j<=i-1; j++) ///when i==3;
        {
            hval=h[i]-h[j]*po[i-j];
            ump[hval]++;
        }
    }

}
int main()
{
    po[0]=1;
    for(int i=1; i<350; i++)
    {
        po[i]=po[i-1]*base;
    }
    string str1,str2;
    while(cin>>str1>>str2)
    {
        ump.clear();
        vec.clear();
        vec1.clear();
        vec2.clear();
        hashval(str1);
        hashvalcheck(str2);
        if(vec.empty())
        {
            cout<<"No common sequence.\n";
        }
        else
        {
            for(auto a:vec)
            {
                string st;
                while(a)
                {
                    char ch=a%31+97-1;
                    st+=ch;
                    a/=31;
                }
                reverse(st.begin(),st.end());
                if(!vec1.empty())
                {
                    string s=vec1.back();
                    if(st.size()==s.size())
                        vec1.push_back(st);
                    else if(st.size()>s.size())
                    {

                        vec1.clear();
                        vec1.push_back(st);
                    }
                }
                else
                    vec1.push_back(st);


            }
            set<string>s(vec1.begin(),vec1.end());
            if(!first)
                cout<<"\n";
            first=0;
            for(auto aa:s)
            {
                cout<<aa<<'\n';
                //vec2.push_back(aa);

            }
        }
        ///display();
        getline(cin, str1);
    }
}
