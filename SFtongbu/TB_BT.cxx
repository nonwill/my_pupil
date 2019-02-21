#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

class TB_BT
{
public:
    TB_BT(int x, int y) : _x(x), _y(y)
    {
        _xy = x * y;
    }
    ~TB_BT()
    {}

    int _x;
    int _y;
    int _xy;
};

void exercise_tb_bt()
{
    // 出题
    std::vector<TB_BT> tb_bt_list;
    for (int a = 1; a < 10; ++a)
    {
        for (int b = 1; b < 6; ++b)
        {
            int ab = a * 10 + b;
            int ac = a * 10 + (10 - b);
            tb_bt_list.push_back(TB_BT(ab, ac));
            int ba = b * 10 + a;
            int da = (10 - b) * 10 + a;
            tb_bt_list.push_back(TB_BT(ba, da));
        }
    }

    // 打乱题的顺序
    srand(time(0));
    int count = tb_bt_list.size();
    while (count)
    {
        int idx = rand() % count--;
        tb_bt_list.push_back(tb_bt_list.at(idx));
        tb_bt_list.erase(tb_bt_list.begin() + idx);
    }

    //
    int idx = 0;
    ofstream of_test, of_answer;
    of_test.open("./tb_bt_test.txt", ios_base::out);
    of_answer.open("./tb_bt_answer.txt", ios_base::out);
    for (vector<TB_BT>::const_iterator it = tb_bt_list.begin(); it != tb_bt_list.end(); ++it)
    {
        ++idx;
        of_test   << setw(3) << idx << ".\t" << it->_x << " x " << it->_y << " = " << endl;
        of_answer << setw(3) << idx << ".\t" << it->_xy << endl;
    }
    of_test.close();
    of_answer.close();
}

int main()
{
    exercise_tb_bt();
    return 0;
}
