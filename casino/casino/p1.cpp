#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(0, "");

    int balance = 100;
    int playerBet = 0;

    cout << "Добро пожаловать в Казино!" << endl;

    while (true) {
        if (balance <= 0) {
            cout << "У вас недостаточно средств для продолжения игры. Игра окончена!" << endl;
            break;
        }

        srand((time(0))); // Инициализация генератора случайных чисел
        int secretNumber = rand() % 10 + 1; // Секретное число от 1 до 100
        int playerGuess = 0; // Предполагаемое число
        cout << "Ваш баланс: " << balance << endl << endl;
        cout << "Я загадал число от 1 до 10. Попробуйте угадать его." << endl << endl;

        cout << "Введите вашу ставку: ";
        cin >> playerBet;

        if (playerBet > balance) {
            cout << "Недостаточно средств для ставки!" << endl << endl;
            continue; // Пропускаем итерацию, если ставка слишком велика
        }

        balance -= playerBet;
        cout << "Введите ваше предположение: ";
        cin >> playerGuess;

        if (playerGuess != secretNumber) {
            cout << "Ваша ставка не сыграла.\nБаланс: " << balance << endl;
        }
        else {
            balance += playerBet * 10; 
            cout << "Ваша ставка сыграла! А вы удачливый...\nБаланс: " << balance << endl;
        }

        char choice;
        cout << "Хотите сыграть ещё раз? (y/n): ";
        cin >> choice;

        // Убедимся, что введено только 'y' или 'n'
        if (choice != 'y' && choice != 'Y') {
            break; // Завершает игру, если игрок не хочет продолжать
        }
    }

    cout << "Спасибо за игру! Ваш финальный баланс: " << balance << endl;
    return 0;
}

