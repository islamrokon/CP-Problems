///https://www.youtube.com/watch?v=sMARZCTPyNI&t=1083s
#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)

using namespace std;

vector<int> constructTempArray(string pattern)
{
    vector<int> lps(pattern.length());
    int index = 0;
    for (int i = 1; i < (int) pattern.length(); i++) ///i will go forward
    {
        index=lps[i-1]; ///index is for matching with that character.
        while(index>0 && pattern[i]!=pattern[index]) ///if we can't get match.
            index=lps[index-1]; ///index will go back by it's lps value till we can't get match,but index must be greater than 0
        if(pattern[i]==pattern[index]) ///if we get match then by adding one with index we can store lps value of i.
            index++; ///we are adding because index number start from 0 but length start from 1.
        lps[i]=index; ///if we can't get match in while loop index become 0 so lps value will be 0.
    }
    return lps;
}
void KMPMultipleTimes (string text, string pattern)
{
    bool found = false;
    vector<int> lps = constructTempArray(pattern);
    int j = 0, i = 0;
    // i --> text, j --> pattern
    while (i < (int) text.length())
    {
        if (text[i] == pattern[j]) ///if we found match then both text and pattern will go forward.
            ++i, ++j;
        else
        {
            if (j != 0)
                j = lps[j - 1]; ///if match doesn't found then we again start matching from prefix of same suffix.
            else ++i; ///j is 0 means pattern matching start from beginning and text will move by 1.
        }

        if (j == (int) pattern.length()) ///if we match all the character of pattern means we get match.
        {
            cout << "found match at : " << (i - pattern.length()) << endl; ///we need to go to the pattern length back of text for from where we get started matching.
            j = lps[j-1]; ///we start matching again of the pattern for more in text.
            found = true;
        }
    }
    if (!found)
        cout << "not found" << endl;
}
int main()
{
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    KMPMultipleTimes(text, pattern);
    return 0;
}
