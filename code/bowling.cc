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
    vector<int> all(10);
    vector<int> ball;
    vector<int> tag(10,0);
    for(int i=0;i<10;i++){
        int t=0;
        if(score[i][0]=='X'){
            ball.push_back(10); 
            all[i]=10;
            tag[i]=2;
            continue;
        }
        if(score[i][0]=='-'){
            ball.push_back(0);
        }
        else{
            ball.push_back(score[i][0]-'0');
            t+=(score[i][0]-'0');
        }
        if(score[i][1]=='/'){
            ball.push_back(10-(score[i][0]-'0'));
            all[i]=10;
            tag[i]=1;
        }
        else if(score[i][1]=='-'){
            ball.push_back(0);
            all[i]=t;
        }
        else{
            ball.push_back(score[i][1]-'0');
            t+=(score[i][1]-'0');
            all[i]=t;
        }
    }
    if(tag[9]!=0){
        if(score[11][0]=='X'){
            ball.push_back(10);
        }
        else if(score[11][0]=='-'){
            ball.push_back(0);
        }
        else{
            ball.push_back(score[11][0]-'0');
        }
        if(tag[9]==2){
            if(score[11][1]=='X'){
                ball.push_back(10);
            }
            else if(score[11][1]=='/'){
                ball.push_back(10-score[11][0]+'0');
            }
            else if(score[11][1]=='-'){
                ball.push_back(0);
            }
            else{
                ball.push_back(score[11][1]-'0');
            }
        }
    }

    int res=0;
    int index=0;
    for(int i=0;i<10;i++){
        if(tag[i]==2){
            index+=1;
            res+=(all[i]+ball[index]+ball[index+1]);
        }
        else if(tag[i]==1){
            index+=2;
            res+=(all[i]+ball[index]);
        }
        else{
            index+=2;
            res+=all[i];
        }
        cout<<res<<endl;
    }
    cout<<res<<endl;
}