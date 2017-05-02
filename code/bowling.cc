#include <bits/stdc++.h>
using namespace std;

void split(const string& s, vector<string>& v, const string& c)
{
    v={};
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int main(){
    string temp;
    cin>>temp;
    vector<string> score;
    split(temp,score,"|");
    int n=score.size();
    if(n>11){
        score[n-2]=score[n-1];
        score.pop_back();
    }
    else{
        score.pop_back();
    }
    n=score.size();
    if(n==11&&score[10].size()==2) n+=1;
    vector<int> all(n);
    vector<int> tag(n,0);
    for(int i=0;i<10;i++){
        if(score[i][0]=='X'){
            all[i]=10;
            tag[i]=2;
        }
        else if(score[i][1]=='/'){
            all[i]=10;
            tag[i]=1;
        }
        else{
            int t=0;
            if(score[i][0]!='-') t+=score[i][0]-'0';
            if(score[i][1]!='-') t+=score[i][1]-'0';
            all[i]=t;
        }
    }
    if(n>10){
    if(score[10][0]=='X') all[10]=10;
    else if(score[10][0]=='-') all[10]=0;
    else all[10]=score[10][0]-'0';
    if(n==12){
        if(score[10][1]=='X') all[11]=10;
        else if(score[10][1]=='/') all[11]=10-all[10];
        else if(score[10][1]=='-') all[11]=0;
        else all[11]=score[10][1]-'0';
    }
}

    int res=0;
    for(int i=0;i<10;i++){
        if(tag[i]==2){
            res+=(all[i]+all[i+1]+all[i+2]);
        }
        else if(tag[i]==1){
            res+=(all[i]+all[i+1]);
        }
        else{
            res+=all[i];
        }
        cout<<res<<endl;
    }
    cout<<res<<endl;
}