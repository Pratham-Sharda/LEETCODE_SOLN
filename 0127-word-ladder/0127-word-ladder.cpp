class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(s.find(endWord)==s.end()){
            return 0;
        }
        q.push({beginWord,1});
        if(s.find(beginWord)!=s.end()){
            s.erase(beginWord);
        }

        while(!q.empty()){
            string curword=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(curword==endWord){
                return dis;
            }
            for(int i=0;i<curword.size();i++){
                char original=curword[i];
                for(char t='a';t<='z';t++){
                    curword[i]=t;
                    if(s.find(curword)!=s.end()){
                        s.erase(curword);
                        q.push({curword,dis+1});
                    }
                }
                curword[i]=original;
            }
        }

        return 0;
    }
};