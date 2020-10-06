#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int b_size = board.size();
    stack<int> s;
    for (int i = 0; i < moves.size(); i++) {
        int x = moves[i]-1;
        for (int y = 0; y < b_size; y++) {
            if (board[y][x] != 0) {
                if (!s.empty()) {
                    if (s.top() == board[y][x]) {
                        s.pop();
                    }
                    else { s.push(board[y][x]); }
                }
                else { s.push(board[y][x]); }
                board[y][x] = 0;
                break;
            }
        }
    }
    answer = s.size();
    return answer;
}

int main() {
    vector<vector<int>> board = { {0, 0, 0, 0, 0
}, { 0, 0, 1, 0, 3
}, { 0, 2, 5, 0, 1
}, { 4, 2, 4, 4, 2
}, { 3, 5, 1, 3, 1 } };
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4
};
    solution(board, moves);
    return 0;
}