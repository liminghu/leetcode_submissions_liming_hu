// https://leetcode.com/problems/design-video-sharing-platform

/*
You have a video sharing platform where users can upload and delete videos. Each video is a string of digits, 
where the ith digit of the string represents the content of the video at minute i. 
For example, the first digit represents the content at minute 0 in the video, 
the second digit represents the content at minute 1 in the video, and so on. 
Viewers of videos can also like and dislike videos. Internally, the platform 
keeps track of the number of views, likes, and dislikes on each video.

When a video is uploaded, it is associated with the smallest available integer videoId starting from 0. 
Once a video is deleted, the videoId associated with that video can be reused for another video.

Implement the VideoSharingPlatform class:
*/
struct videoST {
    int videoId;
    string video;
    int like;
    int dislike;
    int views;
};
unordered_map<int, videoST> videos;
int current_id;
priority_queue<int, vector<int>, greater<>> recycled_videoid_set; //min.

class VideoSharingPlatform {
public:
    //VideoSharingPlatform() Initializes the object.
    VideoSharingPlatform() { 
        current_id = 0;     
        videos.clear();   
        recycled_videoid_set = priority_queue<int, vector<int>, greater<>>();
    }
    
    //int upload(String video) The user uploads a video. Return the videoId associated with the video.
    int upload(string video) {
        int id = 0;
        if (!recycled_videoid_set.empty()) {
            id = recycled_videoid_set.top();
            recycled_videoid_set.pop();
        } else {
            id = current_id;
            current_id++;
        };
        videoST cur_video;
        cur_video.videoId = id;
        cur_video.video = video;
        cur_video.like = 0;
        cur_video.dislike = 0;
        cur_video.views = 0;
        videos[id] = cur_video;
        return id;
    }
    
    //void remove(int videoId) If there is a video associated with videoId, remove the video.
    void remove(int videoId) {
        if(videos.find(videoId)!=videos.end()) {
            recycled_videoid_set.push(videoId);
            videos.erase(videoId);
        };
        
    }
    
    //If there is a video associated with videoId, increase the number of views 
    //on the video by 1 and return the substring of the video string starting at 
    //startMinute and ending at min(endMinute, video.length - 1) (inclusive). Otherwise, return "-1".
    string watch(int videoId, int startMinute, int endMinute) {
        if(videos.find(videoId)!=videos.end()) {
            videoST cur_video = videos[videoId];
            string video = cur_video.video;
            cur_video.views++;
            videos[videoId] = cur_video;
            int video_size = video.size()-1;
            return video.substr(startMinute, min(endMinute,video_size) - startMinute + 1 );
        }
        return "-1";
        
    }

    //Increases the number of likes on the video associated with 
    //videoId by 1 if there is a video associated with videoId.
    void like(int videoId) {
        if(videos.find(videoId)!=videos.end()) {
            videoST cur_video = videos[videoId];
            cur_video.like++;
            videos[videoId] = cur_video;
        }
    }

    //Increases the number of dislikes on the video associated with videoId by 
    //1 if there is a video associated with videoId.
    void dislike(int videoId) {
        if(videos.find(videoId)!=videos.end()) {
            videoST cur_video = videos[videoId];
            cur_video.dislike++;
            videos[videoId] = cur_video;
        }
        
    }

    //Return a 0-indexed integer array values of length 2 where 
    //values[0] is the number of likes and values[1] is the number of dislikes on the video associated 
    //with videoId. If there is no video associated with videoId, return [-1].
    vector<int> getLikesAndDislikes(int videoId) {
        if( videos.find(videoId) != videos.end() ) {
            videoST cur_video = videos[videoId];
            return {cur_video.like, cur_video.dislike};
        } else
            return {-1};
        
    }

    //Return the number of views on the video associated with videoId, if there is no video 
    //associated with videoId, return -1.    
    int getViews(int videoId) {
        int res;
        if(videos.find(videoId)!=videos.end()) {
            videoST cur_video = videos[videoId];
            return cur_video.views;
        }
        return -1;
    }
};

/**
 * Your VideoSharingPlatform object will be instantiated and called as such:
 * VideoSharingPlatform* obj = new VideoSharingPlatform();
 * int param_1 = obj->upload(video);
 * obj->remove(videoId);
 * string param_3 = obj->watch(videoId,startMinute,endMinute);
 * obj->like(videoId);
 * obj->dislike(videoId);
 * vector<int> param_6 = obj->getLikesAndDislikes(videoId);
 * int param_7 = obj->getViews(videoId);
 */