class Twitter {
public:
    map <int,set<int>> follower; //followe->list of following
    vector<pair<int,int>> timeline; //userid ,tweetid

    Twitter() {
        follower.clear();
        timeline.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push_back({userId,tweetId});
        return ;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> top10;
        int ctr=0;
        for(int i=timeline.size()-1;i>=0 &&ctr<10;i-- ){
            if(timeline[i].first==userId || follower[userId].count(timeline[i].first)){
                top10.push_back(timeline[i].second);
                ctr++;
            }
        }
        return top10;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
        return;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */