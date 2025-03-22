#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> 
using namespace std;


class evaluation;
class game;


class evaluation {
public:
    int evaluateExpression(const string expression) {
        int result = 0;
        char operation = '+';
        int num = 0;
        int i = 0;
        while (i < expression.length()) {
            char ch = expression[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if (operation == '+') {
                    result += num;
                } else if (operation == '-') {
                    result -= num;
                } else if (operation == '*') {
                    result *= num;
                } else if (operation == '/') {
                    if (num != 0) {
                        result /= num;
                    } else {
                        cout << "Error: Division by zero" << endl;
                        return 0; 
                    }
                }
                num = 0;
                operation = ch;
            }
            i++;
        }
       
        if (operation == '+') {
            result += num;
        } else if (operation == '-') {
            result -= num;
        } else if (operation == '*') {
            result *= num;
        } else if (operation == '/') {
            if (num != 0) {
                result /= num;
            } else {
                cout << "Error: Division by zero" << endl;
                return 0; 
            }
        }
        return result;
    }
};


class game {
public:
    void loop(int arr[], int startIdx, char choice) {
        evaluation obj1;
        do {
            cout << "Try to make an equation which is equal to 10 using these '+ - * /' operators and ";
            for (int i = startIdx; i < startIdx + 4; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            string equation;
            cout << "Enter a simple equation: ";
            cin >> equation;


            int result = obj1.evaluateExpression(equation);
            cout << "Result: " << result << endl;
            if (result == 10) {
                cout << "You have won this level" << endl;
                cout << "If you want to play the next level, enter 'y': ";
                cin >> choice;
                if (choice == 'y') {
                    startIdx += 4;
                    if (startIdx >= 8) {
                    
                        return;
                    }
                }
            }
            else {
                cout << "Try again" << endl;
                choice = 'y';
            }
        } while (choice == 'y');
    }

};

    void startGame() {
        game obj2;
        int arr[8] = { 1, 2, 3, 6, 1, 0, 3, 7 };
        int startIdx = 0;
        char choice;
        do {
            obj2.loop(arr, startIdx, choice); 
        } while (startIdx < 8 && choice == 'y');
    }
int main(){
    startGame();
    return 0;
}

