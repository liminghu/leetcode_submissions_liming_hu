// https://leetcode.com/problems/design-snake-game

class SnakeGame {
private:
    vector<vector<int>> food_stream;
    int game_width, game_height;
    int snake_w, snake_h;
    int game_status;
    int steps;

public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {  //[3,2,[[1,2],[0,1]]]
        game_width = width;
        game_height = height;
        food_stream = food; //[[1,2],[0,1]]
        snake_w = 0;  //snake location
        snake_h = 0;
        steps = 0;
    }
    
    int move(string direction) { //["R"],["D"],["R"],["U"],["L"],["U"]
        if (direction == "R") { //move right.
            if(snake_w+1>game_width-1)
                return -1; //game over because snake collides with border
            snake_w++;
            //if(steps<food_stream.size()) //is there food?
            if(steps<food_stream.size() && food_stream[steps][0]==snake_h && food_stream[steps][1]==snake_w )  {//food[steps][0]   1 (height)  food[steps][1] 2 (width)
                steps++;
                return steps;
            }
           
        } else if (direction == "L") { //left
            if(snake_w-1<0)
                return -1; //game over because snake collides with border
            snake_w--;
            //if(steps<food_stream.size()) //is there food?
            if(steps<food_stream.size() && food_stream[steps][0]==snake_h && food_stream[steps][1]==snake_w )  {//
                steps++;
                return steps;
            }

        } else if (direction == "D") { //up
            if(snake_h+1>game_height-1)
                return -1; //game over because snake collides with border
            snake_h++;
            //if(steps<food_stream.size()) //is there food?
            if(steps<food_stream.size() && food_stream[steps][0]==snake_h && food_stream[steps][1]==snake_w )  {//
                steps++;
                return steps;
            }
            
        } else if (direction == "U") {//down
            if(snake_h-1<0)
                return -1; //game over because snake collides with border
            snake_h--;
            //if(steps<food_stream.size()) //is there food?
            if(steps<food_stream.size() && food_stream[steps][0]==snake_h && food_stream[steps][1]==snake_w )  {//
                steps++;
                return steps;
            }
            
        }
        return steps;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */