#include <iostream>
#include "windows.h"
using namespace std;


class File {
    string name;
    int size;
    string creationDate;
    int assignCount;
    public: 
        File(): name(""), size(0), creationDate(""), assignCount(0) {}
        File(string n, int s, string c, int a): name(n), size(s), creationDate(c), assignCount(a) {}
        string getName() const { return name;}
        int getSize() const { return size; }
        string getCreationDate() const { return creationDate; }
        int getAssignCount() const { return assignCount; }
        void showFileInfo();
};

void File::showFileInfo() {
    cout << "Файл \"" << name << "\":" << endl;
    cout << "Розмір: " << size << endl;
    cout << "Дата створення: " << creationDate << endl;
    cout << "Кількість звернень: " << assignCount << endl;
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 3;
    File Files[n];
    Files[0] = File("Red.jpg", 220045, "24-04-2024", 2);
    Files[1] = File("Green.jpg", 190760, "30-04-2024", 3);
    Files[2] = File("Blue.jpg", 165478, "04-05-2024", 4);

    cout << "Список файлів: " << endl << endl;
    for (int i = 0; i < n; i++) Files[i].showFileInfo();


    cout << "Список файлів, упорядкований в алфавітному порядку: " << endl << endl;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j < n - 1; j++) {
            if (Files[j].getName() > Files[j + 1].getName()) {
                File tempFile = Files[j];
                Files[j] = Files[j + 1];
                Files[j + 1] = tempFile;
            }
        }
    }
    for (int i = 0; i < n; i++) Files[i].showFileInfo();


    cout << "Список файлів, розмір яких перевищує заданий: " << endl;
    cout << "Введіть розмір файла: ";
    int fileSize;
    cin >> fileSize;
    for (int i = 0; i < n; i++) if (Files[i].getSize() > fileSize) Files[i].showFileInfo();

    cout << "Список файлів, число звернень до яких перевищує ліміт: " << endl;
    cout << "Введіть ліміт звернень: ";
    int assignCount;
    cin >> assignCount;
    for (int i = 0; i < n; i++) if (Files[i].getAssignCount() > assignCount) Files[i].showFileInfo();
}