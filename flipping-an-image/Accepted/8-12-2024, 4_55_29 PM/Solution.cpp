// https://leetcode.com/problems/flipping-an-image

/*
Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
*/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        int sz = image.size();
        //(i, j) -> (n-1-i, j)
        for(int i=0; i<sz; i++) {
            for(int j=0; j<sz/2; j++) {
                swap(image[i][j], image[i][sz-1-j]);
            }
        }

       for(int i=0; i<sz; i++) {
            for(int j=0; j<sz; j++) {
                image[i][j] = 1- image[i][j];
            }
        }

        return image;
        
    }
};