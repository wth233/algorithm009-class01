/*
机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：

-2：向左转 90 度
-1：向右转 90 度
1 <= x <= 9：向前移动 x 个单位长度
在网格上有一些格子被视为障碍物。

第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])

机器人无法走到障碍物上，它将会停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。

返回从原点到机器人所有经过的路径点（坐标为整数）的最大欧式距离的平方。

 

示例 1：

输入: commands = [4,-1,3], obstacles = []
输出: 25
解释: 机器人将会到达 (3, 4)
示例 2：

输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
输出: 65
解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/walking-robot-simulation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        // map存储某个方向(key)对应的 {x方向移动，y方向移动，当前方向的左侧，当前方向的右侧} (val)
        unordered_map<string, vector<string>> mymap = {{"up", {"0", "1", "left", "right"}},{"down", {"0", "-1", "right", "left"}},{"left", {"-1", "0", "down", "up"}},{"right", {"1", "0", "up", "down"}}};

        unordered_set<string> obstacles_set;
        for(int i = 0; i < obstacles.size(); ++i){
            obstacles_set.insert(to_string(obstacles[i][0]) + " " + to_string(obstacles[i][1]));
        }

        int x = 0, y = 0;
        string dir = "up";
        int res = 0;

        for(auto command : commands){
            if(command > 0){
                for(int i = 0; i < command; ++i){
                    int temp_x = x + stoi(mymap[dir][0]);
                    int temp_y = y + stoi(mymap[dir][1]);

                    string temp = to_string(temp_x) + " " + to_string(temp_y);

                    if(obstacles_set.find(temp) == obstacles_set.end()){
                        x += stoi(mymap[dir][0]);
                        y += stoi(mymap[dir][1]);
                        res = max(res, x * x + y * y);
                    }
                    else
                        break;
                }
            }
            else{
                if(command == -2){
                    dir = mymap[dir][2];
                }
                if(command == -1){
                    dir = mymap[dir][3];
                }
            }
        }
        return res;
    }
};