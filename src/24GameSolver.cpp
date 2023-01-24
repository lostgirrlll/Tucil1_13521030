#include <iostream>
#include <string>
#include <vector>
#include <time.h> 
#include <fstream>

using namespace std;

// GLOBAL VARIABLE
float card1, card2, card3, card4;
string input1, input2, input3, input4;
int solusi = 0;

// FUNCTION
void intro()
{
    cout << " --------------------------------------------------------------------------------------- " << endl;
    cout << "|\t                                                                                |" << endl;
    cout << "|\t  $$$$$$   $$    $$          $$$$$                                              |" << endl;
    cout << "|\t $$  __$$ |$$ |  $$ |      $$  __$$$                                            |" << endl;
    cout << "|\t ___/  $$ |$$ |  $$ |      $$ /  ___| $$$$$$   $$$$$$ $$$$$   $$$$$$&           |" << endl;
    cout << "|\t  $$$$$$  |$$$$$$$$ |      $$ |$$$$    ____$$ |$$  _$$  _$$ | $$  __$$|         |" << endl;
    cout << "|\t $$  ____/  _____$$ |      $$ | _$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |         |" << endl;
    cout << "|\t $$ |            $$ |      $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|         |" << endl;
    cout << "|\t $$$$$$$$ |      $$ |       $$$$$$  | $$$$$$$ |$$ | $$ | $$ | $$$$$$$           |" << endl;
    cout << "|\t  ________|       __|        ______/   _______| __|  __|  __|  _______|         |" << endl;
    cout << "|\t                                                                                |" << endl;
    cout << "|\t          $$$$$$             $$                                                 |" << endl;
    cout << "|\t         $$  __$$            $$ |                                               |" << endl;
    cout << "|\t         $$ /   __| $$$$$$   $$ |$$     $$   $$$$$$    $$$$$$                   |" << endl;
    cout << "|\t          $$$$$$   $$  __$$ |$$ | $$   $$  |$$  __$$ |$$  __$$ |                |" << endl;
    cout << "|\t           ____$$  $$ /  $$ |$$ |  $$ $$  / $$$$$$$$ |$$ |   __|                |" << endl;
    cout << "|\t         $$    $$ |$$ |  $$ |$$ |   $$$  /  $$   ____|$$ |                      |" << endl;
    cout << "|\t          $$$$$$  | $$$$$$  |$$ |    $  /    $$$$$$$  $$ |                      |" << endl;
    cout << "|\t           ______/   ______/  __|     _/      _______| __|                      |" << endl;
    cout << "|\t                                                                                |" << endl;
    cout << " --------------------------------------------------------------------------------------- " << endl;
}

float convertCardToFloat(string card)
{
    if (card == "A") {
        return 1;
    }
    else if (card == "J") {
        return 11;
    }
    else if (card == "Q") {
        return 12;
    }
    else if (card == "K") {
        return 13;
    }
    else if (card == "2") {
        return 2;
    }
    else if (card == "3") {
        return 3;
    }
    else if (card == "4") {
        return 4;
    }
    else if (card == "5") {
        return 5;
    }
    else if (card == "6") {
        return 6;
    }
    else if (card == "7") {
        return 7;
    }
    else if (card == "8")  {
        return 8;
    }
    else if (card == "9") {
        return 9;
    }
    else if (card == "10") {
        return 10;
    }
    else {
        return 0;
    }
}

string convertCardToString(int card)
{
    if (card == 1) {
        return "A";
    }
    else if (card == 11) {
        return "J";
    }
    else if (card == 12) {
        return "Q";
    }
    else if (card == 13) {
        return "K";
    }
    else {
        return to_string(card);
    }
}

void intToStr(int num, string &str)
{
    if (num == 1) {
        str = "A";
    }
    else if (num == 11) {
        str = "J";
    }
    else if (num == 12) {
        str = "Q";
    }
    else if (num == 13) {
        str = "K";
    }
    else {
        str = to_string(num);
    }
}

bool isCardValid(string card)
{
    if (card == "A" || card == "J" || card == "Q" || card == "K" || card == "2" || card == "3" || card == "4" || card == "5" || card == "6" || card == "7" || card == "8" || card == "9" || card == "10") {
        return true;
    }
    else {
        return false;
    }
}

void randomCard()
{
    int c1, c2, c3, c4;
    srand(time(NULL));
    c1 = rand() % 13 + 1;
    c2 = rand() % 13 + 1;
    c3 = rand() % 13 + 1;
    c4 = rand() % 13 + 1;
    intToStr(c1, input1);
    intToStr(c2, input2);
    intToStr(c3, input3);
    intToStr(c4, input4);
    card1 = convertCardToFloat(convertCardToString(c1));
    card2 = convertCardToFloat(convertCardToString(c2));
    card3 = convertCardToFloat(convertCardToString(c3));
    card4 = convertCardToFloat(convertCardToString(c4));
    cout << " " << endl;
    cout << " --------------------------------------------------------------------------------------- " << endl;
    cout << "|\t" << "Kartu yang terpilih adalah " << input1 << ", " << input2 << ", " << input3 << ", dan " << input4 << "  \t\t\t\t\t|"<< endl;
}

void cardInput()
{
    string pilihan;

    cout << "  " << endl;
    cout << " \t" << "Pilih input dari keyboard atau random:" << endl;
    cout << " \t" << "1. Keyboard" << endl;
    cout << " \t" << "2. Random" << endl;
    cout << "  " << endl;
    cout << " \t" << "Masukkan pilihan : ";
    cin >> pilihan;

    while (pilihan != "1" && pilihan != "2") {
        cout << "  " << endl;
        cout << " \t" << "Input tidak valid. Masukkan pilihan (1/2): ";
        cin >> pilihan;
    }

    if (pilihan == "1") {
        cout << "  " << endl;
        cout << " \t" << "Masukkan 4 kartu: " << endl;
        cout << " \t" << "(angka 2-10 atau huruf A, J, Q, dan K) " << endl;
        cout << "  " << endl;
        cout << " \t" << "Masukkan kartu : ";
        cin >> input1 >> input2 >> input3 >> input4;
        card1 = convertCardToFloat(input1);
        card2 = convertCardToFloat(input2);
        card3 = convertCardToFloat(input3);
        card4 = convertCardToFloat(input4);

        while (!isCardValid(input1) || !isCardValid(input2) || !isCardValid(input3) || !isCardValid(input4)) {
            cout << "  " << endl;
            cout << " \t" << "Kartu tidak valid. Masukkan kembali 4 kartu. " << endl;
            cout << " \t" << "(angka 2-10 atau huruf A, J, Q, dan K)" << endl;
            cout << "  " << endl;
            cout << " \t" << "Masukkan 4 kartu: ";
            cin >> input1 >> input2 >> input3 >> input4;
            card1 = convertCardToFloat(input1);
            card2 = convertCardToFloat(input2);
            card3 = convertCardToFloat(input3);
            card4 = convertCardToFloat(input4);
        }
        cout << " " << endl;
        cout << " --------------------------------------------------------------------------------------- " << endl;
        cout << "|\t" << "Kartu yang anda pilih adalah " << input1 << ", " << input2 << ", " << input3 << ", dan " << input4 << "\t\t\t\t\t|"<< endl;
    }
    else if (pilihan == "2") {
        randomCard();
    }
}

float operation(float cardA, float cardB, int sign)
{
    if (sign == 1) {
        return cardA + cardB;
    }
    else if (sign == 2) {
        return cardA - cardB;
    }
    else if (sign == 3) {
        return cardA * cardB;
    }
    else if (sign == 4) {
        return cardA / cardB;
    }
    else {
        return 0;
    }
}

string sign(int op)
{
    if (op == 1) {
        return "+";
    }
    else if (op == 2) {
        return "-";
    }
    else if (op == 3) {
        return "*";
    }
    else if (op == 4) {
        return "/";
    }
    else {
        return 0;
    }
}
bool checkDouble (vector<string> hasil, string temp)
{
    for (int i = 0; i < hasil.size(); i++) {
        if (hasil[i] == temp) {
            return true;
        }
    }
    return false;
}

void check24(float card1, float card2, float card3, float card4, vector<string> *hasil)
{
    int op1, op2, op3;
    float calculate;
    string result = "";

    for (op1 = 1; op1 <= 4; op1++) {
        for (op2 = 1; op2 <= 4; op2++) {
            for (op3 = 1; op3 <= 4; op3++) {
                calculate = operation(operation(operation(card1, card2, op1), card3, op2), card4, op3);
                if (calculate == 24) {
                    result = "((" + to_string((int)card1) + " " + sign(op1) + " " + to_string((int)card2) + ") " + sign(op2) + " " + to_string((int)card3) + ") " + sign(op3) + " " + to_string((int)card4) + " = " + to_string((int)calculate);
                    if (!checkDouble(*hasil, result)) {
                        (*hasil).push_back(result);
                        solusi++;
                    }
                }
                calculate = operation(operation(card1, card2, op1), operation(card3, card4, op3), op2);
                if (calculate == 24) {
                    result = "(" + to_string((int)card1) + " " + sign(op1) + " " + to_string((int)card2) + ") " + sign(op2) + " (" + to_string((int)card3) + sign(op3) + " " + to_string((int)card4) + ") = " + to_string((int)calculate);
                    if (!checkDouble(*hasil, result)) {
                        (*hasil).push_back(result);
                        solusi++;
                    }
                }
                calculate = operation(card1, operation(operation(card2, card3, op2), card4, op3), op1);
                if (calculate == 24) {
                    result = to_string((int)card1) + " " + sign(op1) + " ((" + to_string((int)card2) + sign(op2) + " " + to_string((int)card3) + ") " + sign(op3) + " " + to_string((int)card4) + ") = " + to_string((int)calculate);
                    if (!checkDouble(*hasil, result)) {
                        (*hasil).push_back(result);
                        solusi++;
                    }
                }
                calculate = operation(operation(card1, operation(card2, card3, op2), op1), card4, op3);
                if (calculate == 24) {
                    result = "(" + to_string((int)card1) + " " + sign(op1) + " (" + to_string((int)card2) + sign(op2) + " " + to_string((int)card3) + ")) " + sign(op3) + " " + to_string((int)card4) + " = " + to_string((int)calculate);
                    if (!checkDouble(*hasil, result)) {
                        (*hasil).push_back(result);
                        solusi++;
                    }
                }
            }
        }
    }
}


void printSolution(vector<string> hasil)
{
    int number = 0;
    cout << " --------------------------------------------------------------------------------------- " << endl;
    cout << "|\t" << solusi <<" solusi ditemukan   " << "\t\t\t\t\t\t\t\t|"<< endl;
    cout << " --------------------------------------------------------------------------------------- " << endl;
    if (solusi == 0) {
        cout << "|\t" << "Tidak ada solusi                                                                |" << endl;
    }
    else {
        for (int i = 0; i < hasil.size(); i++) {
            number++;
            cout << " \t" << number << ".\t" << hasil[i] << endl;
        }
    }
    cout << " --------------------------------------------------------------------------------------- " << endl;
}

// MAIN PROGRAM
int main() 
{    
    vector<string> hasil;

    intro();
    cardInput();

    check24(card1, card2, card3, card4, &hasil);
    check24(card1, card2, card4, card3, &hasil);
    check24(card1, card3, card2, card4, &hasil);
    check24(card1, card3, card4, card2, &hasil);
    check24(card1, card4, card2, card3, &hasil);
    check24(card1, card4, card3, card2, &hasil);
    check24(card2, card1, card3, card4, &hasil);
    check24(card2, card1, card4, card3, &hasil);
    check24(card2, card3, card1, card4, &hasil);
    check24(card2, card3, card4, card1, &hasil);
    check24(card2, card4, card1, card3, &hasil);
    check24(card2, card4, card3, card1, &hasil);
    check24(card3, card1, card2, card4, &hasil);
    check24(card3, card1, card4, card2, &hasil);
    check24(card3, card2, card1, card4, &hasil);
    check24(card3, card2, card4, card1, &hasil);
    check24(card3, card4, card1, card2, &hasil);
    check24(card3, card4, card2, card1, &hasil);
    check24(card4, card1, card2, card3, &hasil);
    check24(card4, card1, card3, card2, &hasil);
    check24(card4, card2, card1, card3, &hasil);
    check24(card4, card2, card3, card1, &hasil);
    check24(card4, card3, card1, card2, &hasil);
    check24(card4, card3, card2, card1, &hasil);

    printSolution(hasil);

}