// https://leetcode.com/problems/design-twitter

/*Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to 
see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. 
Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. 
Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets 
must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
*/
class Twitter {
public:
    int timestamp;
    unordered_map<int, vector<pair<int,int>>> tweets; //userid, <timestamp, twitterid>
    unordered_map<int, unordered_set<int>> friends;
//Twitter() Initializes your twitter object.
    Twitter() {
        timestamp = 0;
    }
//void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
//List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who 
//the user followed or by the user themself. Tweets must be ordered from most recent to least recent.    
    vector<int> getNewsFeed(int userId) {
       set<pair<int,int>> news; //<timestamp, twitterid>
       for(auto f: friends[userId]) {
            for(int j=tweets[f].size()-1; j>=0; j--) {
                if(news.size() < 10) {
                    news.insert(tweets[f][j]);
                } else if(tweets[f][j].first > news.begin()->first) {
                    news.erase(news.begin());
                    news.insert(tweets[f][j]);
                } else 
                    break;
 
            }
       }
       vector<int> res;
       for(auto n: news) {
            res.push_back(n.second);
       }
       reverse(res.begin(), res.end());
       return res; 
    }
//void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
//void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.    
    void unfollow(int followerId, int followeeId) {
        if(friends[followerId].find(followeeId)!= friends[followerId].end())
            friends[followerId].erase(followeeId);
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