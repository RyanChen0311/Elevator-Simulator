// elevator.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include "assert.h"
using namespace std;

class Elevator {
public:
    int current_floor;
    string name;

    Elevator(string s, int floor = 0) : name(s), current_floor(floor) {}

    void display_floor() {
        cout << "You take the Elevator " << name << " and ";
        cout << "Elevator " << name << " is on floor " << current_floor << endl;
        cout << "============================" << endl;
    }
    void showMoving(int current_floor, int des_floor,int user_current_floor) {
        if (current_floor < user_current_floor) {
            for (int i = current_floor; i <= user_current_floor; i++) {
                cout << i << endl;
            }
        }
        else {
            for (int i = current_floor; i >= user_current_floor; i--) {
                cout << i << endl;
            }
        }        
        current_floor = user_current_floor;
        if (current_floor < des_floor) {
            for (int i = current_floor; i <= des_floor; i++) {
                cout << i << endl;
            }
        }
        else {
            for (int i = current_floor; i >= des_floor; i--) {
                cout << i << endl;
            }
        }
    }
    void move(int floor, int user_current_floor) {
        showMoving(current_floor, floor, user_current_floor);
        current_floor = floor;        
        display_floor();
    }   
};

class UI {
public:
    int current_floor;
    int desired_floor;

    UI() : current_floor(0), desired_floor(0) {}

    int close_elevator(int current_floor, Elevator &e1, Elevator &e2) {
        if (abs(current_floor - e1.current_floor) <= abs(current_floor - e2.current_floor)) {
            return 1;
        } else {
            return 2;
        }
    }
    
    void input(int current_floor, int desired_floor, Elevator &e1, Elevator &e2) {
        if (close_elevator(current_floor, e1, e2) == 1) {
            e1.move(desired_floor, current_floor);
        }
        else {
            e2.move(desired_floor, current_floor);
        }
    }

    int loop() {
        int flag = 1;
        cout << "Press any button to take the elevator or press 0 to go" << endl;
        cin >> flag;
        if (!flag) {
            return 0;
        }
        do {
            cout << "your current floor is:" << endl;
            cin >> current_floor;
            assert(current_floor >= 1 && "wrong current floor input!");
            assert(current_floor <= 10 && "wrong current floor input!");
        } while (current_floor < 1 or current_floor > 10);
        do {
            cout << "your desired floor is:" << endl;
            cin >> desired_floor;
            assert(desired_floor >= 1 && "wrong desired floor input!");
            assert(desired_floor <= 10 && "wrong desired floor input!");
        } while (desired_floor < 1 or desired_floor > 10);   
        return flag;
    }
};

int main()
{
    Elevator elevator1("e1"), elevator2("e2");
    UI u;
    while (u.loop()) {
        u.input(u.current_floor, u.desired_floor, elevator1, elevator2);
    }

    return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
