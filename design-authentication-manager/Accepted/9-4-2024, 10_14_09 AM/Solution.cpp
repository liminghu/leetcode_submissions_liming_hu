// https://leetcode.com/problems/design-authentication-manager

/*
There is an authentication system that works with authentication tokens. For each session, 
the user will receive a new authentication token that will expire timeToLive seconds after the 
currentTime. If the token is renewed, the expiry time will be extended to expire timeToLive 
seconds after the (potentially different) currentTime.
Implement the AuthenticationManager class:
AuthenticationManager(int timeToLive) constructs the AuthenticationManager and sets the timeToLive.
generate(string tokenId, int currentTime) generates a new token with the given tokenId at the given
 currentTime in seconds.
renew(string tokenId, int currentTime) renews the unexpired token with the given tokenId at the given
 currentTime in seconds. If there are no unexpired tokens with the given tokenId, the request is ignored, 
 and nothing happens.
countUnexpiredTokens(int currentTime) returns the number of unexpired tokens at the given currentTime.
Note that if a token expires at time t, and another action happens on time t (renew or countUnexpiredTokens), 
the expiration takes place before the other actions.
*/
/*
1 <= timeToLive <= 108
1 <= currentTime <= 108
1 <= tokenId.length <= 5
tokenId consists only of lowercase letters.
All calls to generate will contain unique values of tokenId.
The values of currentTime across all the function calls will be strictly increasing.
At most 2000 calls will be made to all functions combined.
*/
class AuthenticationManager {
private:
    int timeToLive_;
    unordered_map<string, int> mp_; //key, created time.
public:
    AuthenticationManager(int timeToLive) {
        timeToLive_ = timeToLive;
        mp_.clear();
        
    }
    
    void generate(string tokenId, int currentTime) {
        mp_[tokenId] = currentTime;
        
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp_.find(tokenId)!=mp_.end()) {
            if(currentTime - mp_[tokenId] >= timeToLive_)
                return;
            else
                mp_[tokenId] = currentTime;
        };
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ret = 0;
        for(auto item:mp_) {
            if(currentTime-item.second >= timeToLive_)
                continue;
            ret++;
        };
        return ret;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */