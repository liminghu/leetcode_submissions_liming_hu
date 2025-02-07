// https://leetcode.com/problems/design-snake-game

/*
Design a Snake game that is played on a device with screen size height x width. Play the game online if you are not familiar with the game.
The snake is initially positioned at the top left corner (0, 0) with a length of 1 unit.
You are given an array food where food[i] = (ri, ci) is the row and column position of a piece of food that the snake can eat. When a snake 
eats a piece of food, its length and the game's score both increase by 1.
Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the snake eats the first piece of food.
When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body occupies after moving (i.e. a snake 
of length 4 cannot run into itself).
Implement the SnakeGame class:
SnakeGame(int width, int height, int[][] food) Initializes the object with a screen of size height x width and the positions of the food.
int move(String direction) Returns the score of the game after applying one direction move by the snake. If the game is over, return -1.
1 <= width, height <= 104
1 <= food.length <= 50
food[i].length == 2
0 <= ri < height
0 <= ci < width
direction.length == 1
direction is 'U', 'D', 'L', or 'R'.
At most 104 calls will be made to move.
*/
class SnakeGame {
private:
    vector<vector<int>> food_stream;
    int game_width, game_height;
    int snake_w, snake_h;
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