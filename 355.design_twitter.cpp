//coding:utf-8
/*****************************************
Program: Design tweeter
Description: 
Author: cshanbo@gmail.com
Date: 2016-08-17 09:00:37
Last modified: 2016-08-29 16:56:50
GCC version: 4.9.3
*****************************************/

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef struct tweet {
    int id;
    int timeline;
    tweet() {}
    tweet(int i, int j): id(i), timeline(j) {}
} TWEET;


typedef struct User {
    int id;
    vector<TWEET> tweets;
    unordered_set<int> to;
    unordered_set<int> from;
} USER;

namespace std {
    template <>
    struct hash<USER>{
        size_t operator()(const USER& u) const{
            return hash<int>()(u.id);
        }
    };
}

bool static compare(const TWEET& t1, const TWEET& t2) {
    return t1.timeline > t2.timeline;
}

class Twitter {
    unordered_map<int, USER> users;
    int timeline;
public:
    /** Initialize your data structure here. */
    Twitter() {
        timeline = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(users.find(userId) == users.end()) {
            USER u;
            u.id = userId;
            
            u.tweets.push_back(TWEET(tweetId, timeline++));
            users[userId] = u;
        } else {
            users[userId].tweets.push_back(TWEET(tweetId, timeline++));
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if(users.find(userId) == users.end())
            return vector<int>();
        vector<TWEET> ret;
        int cnt = 0;
        for(unordered_set<int>::iterator u = users[userId].to.begin(); u != users[userId].to.end(); u++) {
            cnt = 0;
            for(int i = users[*u].tweets.size() - 1; i >= 0 && cnt < 10; --i) {
                ret.push_back(users[*u].tweets[i]);
                cnt++;
            }
        }
        cnt = 0;
        for(int i = users[userId].tweets.size() - 1; i >= 0 && cnt < 10; --i) {
            ret.push_back(users[userId].tweets[i]);
            cnt++;
        }
        sort(ret.begin(), ret.end(), compare);
        vector<int> res;
        unordered_set<int> st;
        for(int i = 0; i < ret.size() && res.size() < 10; ++i)
            if(st.find(ret[i].id) == st.end()) {
                st.insert(ret[i].id);
                res.push_back(ret[i].id);
            }
        return res;
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        users[followerId].to.insert(followeeId);
        users[followeeId].from.insert(followerId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        users[followerId].to.erase(followeeId);
        users[followeeId].from.erase(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
