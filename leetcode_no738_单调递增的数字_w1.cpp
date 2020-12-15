/* ------------------------------------------------------------------|
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10
输出: 9
示例 2:

输入: N = 1234
输出: 1234
示例 3:

输入: N = 332
输出: 299

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotone-increasing-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：6.1 MB, 在所有 C++ 提交中击败了42.23%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isIncreasingDigits(int N) {
    int pre = N % 10;
    N /= 10;
    while (N) {
        if (pre >= (N % 10)) {
            pre = N % 10;
            N /= 10;
        }
        else {
            return false;
        }
    }
    return true;
}

int monotoneIncreasingDigits(int N) {
    if (isIncreasingDigits(N)) {
        return N;
    }
    string num = to_string(N);
    int flag = 0;

    for (int i = 1; i < num.size(); i++) {
        if (num[i] < num[i - 1]) {
            flag = i - 1;
            while (num[flag] == num[flag - 1]) {
                flag--;
            }
            num[flag]--;
            break;
        }
    }
    for (int i = flag + 1; i < num.size(); i++) {
        num[i] = '9';
    }
    return stoi(num);
}

