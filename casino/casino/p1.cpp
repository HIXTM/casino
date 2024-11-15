#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(0, "");

    int balance = 100;
    int playerBet = 0;

    cout << "����� ���������� � ������!" << endl;

    while (true) {
        if (balance <= 0) {
            cout << "� ��� ������������ ������� ��� ����������� ����. ���� ��������!" << endl;
            break;
        }

        srand((time(0))); // ������������� ���������� ��������� �����
        int secretNumber = rand() % 10 + 1; // ��������� ����� �� 1 �� 100
        int playerGuess = 0; // �������������� �����
        cout << "��� ������: " << balance << endl << endl;
        cout << "� ������� ����� �� 1 �� 10. ���������� ������� ���." << endl << endl;

        cout << "������� ���� ������: ";
        cin >> playerBet;

        if (playerBet > balance) {
            cout << "������������ ������� ��� ������!" << endl << endl;
            continue; // ���������� ��������, ���� ������ ������� ������
        }

        balance -= playerBet;
        cout << "������� ���� �������������: ";
        cin >> playerGuess;

        if (playerGuess != secretNumber) {
            cout << "���� ������ �� �������.\n������: " << balance << endl;
        }
        else {
            balance += playerBet * 10; 
            cout << "���� ������ �������! � �� ���������...\n������: " << balance << endl;
        }

        char choice;
        cout << "������ ������� ��� ���? (y/n): ";
        cin >> choice;

        // ��������, ��� ������� ������ 'y' ��� 'n'
        if (choice != 'y' && choice != 'Y') {
            break; // ��������� ����, ���� ����� �� ����� ����������
        }
    }

    cout << "������� �� ����! ��� ��������� ������: " << balance << endl;
    return 0;
}

