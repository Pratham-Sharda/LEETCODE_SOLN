class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(s.find(endWord)==s.end()){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        if(s.find(beginWord)!=s.end()){
            s.erase(beginWord);
        }
        int depth=0;
        while(!q.empty()){
            int len=q.size();

            while(len--){
                string curr=q.front();
                q.pop();
                if(curr==endWord){
                    return depth+1;
                }
                for(int i=0;i<curr.length();i++){
                    char original=curr[i];
                    for(char it='a';it<='z';it++){
                        curr[i]=it;
                        if(s.find(curr)!=s.end()){
                            q.push(curr);
                            s.erase(curr);
                        }
                    }
                    curr[i]=original;
                }
            }

            depth++;
        }

        return 0;
    }
};