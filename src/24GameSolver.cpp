#include <iostream> // input dan output
#include <string>   // string
#include <vector>   // vector
#include <time.h>   // waktu
#include <fstream>  // file

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
// Mengubah kartu dari string menjadi float
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
// Mengubah kartu dari integer menjadi string
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
// Mengubah int menjadi string
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
// Mengecek apakah kartu valid
{
    if (card == "A" || card == "J" || card == "Q" || card == "K" || card == "2" || card == "3" || card == "4" || card == "5" || card == "6" || card == "7" || card == "8" || card == "9" || card == "10") {
        return true;
    }
    else {
        return false;
    }
}

void randomCard()
// Membuat 4 kartu secara acak
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
// Membaca keempat kartu untuk permainian 24
{
    string pilihan;

    //pilih input dari keyboard atau random
    cout << "  " << endl;
    cout << " \t" << "Pilih input dari keyboard atau random:" << endl;
    cout << " \t" << "1. Keyboard" << endl;
    cout << " \t" << "2. Random" << endl;
    cout << "  " << endl;
    cout << " \t" << "Masukkan pilihan : ";
    cin >> pilihan;

    // Mengecek apakah input valid
    while (pilihan != "1" && pilihan != "2") {
        cout << "  " << endl;
        cout << " \t" << "Input tidak valid. Masukkan pilihan (1/2): ";
        cin >> pilihan;
    }

    // Input dari keyboard
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

        // Mengecek apakah input kartu valid
        while (!isCardValid(input1) || !isCardValid(input2) || 
        !isCardValid(input3) || !isCardValid(input4)) {
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
    // Input random
    else if (pilihan == "2") {
        randomCard();
    }
}

float operation(float cardA, float cardB, int sign)
// Menghitung operasi cardA dan cardB
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
// Mengubah angka menjadi operator
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
// Mengecek apakah hasil sudah ada di vector hasil
{
    for (int i = 0; i < hasil.size(); i++) {
        if (hasil[i] == temp) {
            return true;
        }
    }
    return false;
}

void check24(float card1, float card2, float card3, float card4, vector<string> *hasil)
// Mengecek apakah ada kombinasi kartu yang hasil perhitungannya 24
{
    int op1, op2, op3;
    float calculate;
    string result = "";

    for (op1 = 1; op1 <= 4; op1++) {
        for (op2 = 1; op2 <= 4; op2++) {
            for (op3 = 1; op3 <= 4; op3++) {
                // ((card1 op1 card2) op2 card3) op3 card4
                calculate = operation(operation(operation(card1, card2, op1), card3, op2), card4, op3);
                if (calculate == 24) {
                    result = "((" + to_string((int)card1) + " " + sign(op1) + " " + to_string((int)card2) + ") " + sign(op2) + " " + to_string((int)card3) + ") " + sign(op3) + " " + to_string((int)card4) + " = " + to_string((int)calculate);
                    if (!checkDouble(*hasil, result)) {
                        (*hasil).push_back(result);
                        solusi++;
                    }
                }
                // (card1 op1 card2) op2 (card3 op3 card4)
                calculate = operation(operation(card1, card2, op1), operation(card3, card4, op3), op2);
                if (calculate == 24) {
                    result = "(" + to_string((int)card1) + " " + sign(op1) + " " + to_string((int)card2) + ") " + sign(op2) + " (" + to_string((int)card3) + sign(op3) + " " + to_string((int)card4) + ") = " + to_string((int)calculate);
                    if (!checkDouble(*hasil, result)) {
                        (*hasil).push_back(result);
                        solusi++;
                    }
                }
                // card1 op1 ((card2 op2 card3) op3 card4)
                calculate = operation(card1, operation(operation(card2, card3, op2), card4, op3), op1);
                if (calculate == 24) {
                    result = to_string((int)card1) + " " + sign(op1) + " ((" + to_string((int)card2) + sign(op2) + " " + to_string((int)card3) + ") " + sign(op3) + " " + to_string((int)card4) + ") = " + to_string((int)calculate);
                    if (!checkDouble(*hasil, result)) {
                        (*hasil).push_back(result);
                        solusi++;
                    }
                }
                // (card1 op1 (card2 op2 card3)) op3 card4
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

void cardPosition(float card1, float card2, float card3, float card4, vector<string> *hasil)
// Mengecek semua kemungkinan dalam menyusun 4 kartu dengan posisi yang berbeda-beda
{
    check24(card1, card2, card3, card4, hasil);
    check24(card1, card2, card4, card3, hasil);
    check24(card1, card3, card2, card4, hasil);
    check24(card1, card3, card4, card2, hasil);
    check24(card1, card4, card2, card3, hasil);
    check24(card1, card4, card3, card2, hasil);
    check24(card2, card1, card3, card4, hasil);
    check24(card2, card1, card4, card3, hasil);
    check24(card2, card3, card1, card4, hasil);
    check24(card2, card3, card4, card1, hasil);
    check24(card2, card4, card1, card3, hasil);
    check24(card2, card4, card3, card1, hasil);
    check24(card3, card1, card2, card4, hasil);
    check24(card3, card1, card4, card2, hasil);
    check24(card3, card2, card1, card4, hasil);
    check24(card3, card2, card4, card1, hasil);
    check24(card3, card4, card1, card2, hasil);
    check24(card3, card4, card2, card1, hasil);
    check24(card4, card1, card2, card3, hasil);
    check24(card4, card1, card3, card2, hasil);
    check24(card4, card2, card1, card3, hasil);
    check24(card4, card2, card3, card1, hasil);
    check24(card4, card3, card1, card2, hasil);
    check24(card4, card3, card2, card1, hasil);
}

void printSolution(vector<string> hasil)
// Menampilkan solusi
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

void saveFile(vector<string> hasil)
// Menyimpan solusi ke file
{
    ofstream file;
    string namaFile, namaPath, pilihan;
    int number = 0;

    cout << " \t" << "Apakah ingin menyimpan solusi? (y/n) : ";
    cin >> pilihan;
    while (pilihan != "y" && pilihan != "n") {
        cout << " " << endl;
        cout << " \t" << "Input salah, masukkan kembali (y/n) : ";
        cin >> pilihan;
    }
    if (pilihan == "y") {
        cout << " " << endl;
        namaPath = "../test/";
        file.open(namaPath + "solusi_" + input1 + "_" + input2 + "_" + input3 + "_" + input4 + ".txt");
        file << " ---------------------------------------" << endl;
        file << "\t" << input1 << " " << input2 << " " << input3 << " " << input4 << endl;
        file << " ---------------------------------------" << endl;
        file << "\t" << solusi << " solusi ditemukan" << endl;
        file << " ---------------------------------------" << endl;
        if (solusi == 0) {
            file << "\t" << "Tidak ada solusi" << endl;
        }
        else {
            for (int i = 0; i < hasil.size(); i++) {
                number++;
                file << "\t" << number << ".  \t" << hasil[i] << endl;
            }
        }
        file << " ---------------------------------------" << endl;
        file.close();
        cout << " \t" << "File berhasil disimpan" << endl;
        cout << " --------------------------------------------------------------------------------------- " << endl;
    }
    else if (pilihan == "n") {
        cout << " " << endl;
        cout << " \t" << "Tidak ada file yang disimpan" << endl;
        cout << " --------------------------------------------------------------------------------------- " << endl;
    }
}

// MAIN PROGRAM
int main() 
{
    vector<string> hasil;
    
    intro();
    cardInput();
    
    clock_t start = clock();

    cardPosition(card1, card2, card3, card4, &hasil);
    printSolution(hasil);

    double end = clock();
    cout << " " << endl;
    cout << " \t" << "Waktu eksekuksi : " << (float)(clock() - start)/CLOCKS_PER_SEC << " detik" << endl;   // menghitung dan menampilkan waktu eksekusi
    cout << "  " << endl;

    saveFile(hasil);
}