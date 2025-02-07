// https://leetcode.com/problems/design-snake-game

/*
https://www.jiakaobo.com/leetcode/353.%20Design%20Snake%20Game.html
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
    unordered_set<int> body_s; //record the snake body locations.
    deque<int> body_q;  //record snake shape. head is the front. tail is the back.
    int game_width;
    int game_height;
    int score;
    vector<vector<int>> food_stream;
    int foodIndex;

public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {  //[3,2,[[1,2],[0,1]]]
        game_width = width;
        game_height = height;
        food_stream = food; //[[1,2],[0,1]]
        score = 0;
        foodIndex = 0;
        body_q.clear();
        body_s.clear();
        body_q.push_front(0);  //(0,0);
        body_s.insert(0);
    }
    
    int move(string direction) { //["R"],["D"],["R"],["U"],["L"],["U"]
        int head = body_q.front();
        int rowHead = head / game_width;
        int colHead = head % game_width;
        switch (direction[0]) { //switch can not use string.
            case 'U': 
                rowHead--;
                break;     
            case 'D': 
                rowHead++;
                break;
            case 'L':
                colHead--;
                break;
            case 'R':
                colHead++;
                break;
            default:
                cout<<"sth wrong!"<<endl;
                break;
        }
        int newhead = rowHead * game_width + colHead;
        body_s.erase(body_q.back()); //remove the old tail.
        if(rowHead<0 || rowHead == game_height || colHead<0 || colHead == game_width) //collides wall.
            return -1;
        if(body_s.contains(newhead)) //run into its old body.
            return -1;
        body_s.insert(newhead);
        body_q.push_front(newhead); //head is at the front.

        if(foodIndex < food_stream.size() && rowHead == food_stream[foodIndex][0] && colHead == food_stream[foodIndex][1]) { //if it eats, it will grow. the tail will be kept.
            foodIndex++;
            score++;
            body_s.insert(body_q.back());
            return score;
        };
        body_q.pop_back(); //remove its old tail from the queue.
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */