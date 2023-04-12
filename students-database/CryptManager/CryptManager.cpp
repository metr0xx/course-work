#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

#pragma once

using namespace std;

class CryptManager {

    char *pass;

    char *generatePass() {
        srand(time(nullptr));
        char *password = new char[64];
        for (int i = 0; i < 64; ++i) {
            switch (rand() % 3) {
                case 0:
                    password[i] = rand() % 10 + '0';
                    break;
                case 1:
                    password[i] = rand() % 26 + 'A';
                    break;
                case 2:
                    password[i] = rand() % 26 + 'a';
            }
        }

        return password;
    }

public:

    CryptManager() {
        this->pass = generatePass();
    }

    ~CryptManager() {
        delete this->pass;
    }

    void Crypt() {
        string command = R"(OpenSSL-Win64\bin\openssl.exe aes-256-cbc -salt -e -a -in C:\StudentsDB\NEW.txt -out C:\StudentsDB\NEW.txt.enc -pass pass:)";
        command += this->pass;
        system(command.c_str());

        cout << "from aboba1\n";

        if (remove("C:/StudentsDB/NEW.txt") != 0) {
            cout << "[ERROR] - deleting file" << endl;
        }

        ofstream file("key.txt", ios::binary);

        file.write(pass, 65);
        file.close();

        command = R"(OpenSSL-Win64\bin\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc)";
        system(command.c_str());
        cout << "from aboba2\n";

        if (remove("key.txt") != 0) {
            cout << "[ERROR] - deleting file" << endl;
        }
    }

    void Decrypt() {
        string command = R"(OpenSSL-Win64\bin\openssl.exe rsautl -decrypt -inkeyrsa.private -in key.txt.enc -out key.txt)";
        system(command.c_str());

        if (remove("key.txt.enc") != 0) {
            cout << "[ERROR] - deleting file" << endl;
        }

        ifstream file("key.txt", ios::binary);
        file.read(this->pass, 65);
        file.close();

        if (remove("key.txt") != 0) {
            cout << "[ERROR] - deleting file" << endl;
        }

        command = R"(OpenSSL-Win64\bin\openssl.exe enc -aes-256-cbc -d -in C:\StudentsDB\NEW.txt.enc -out C:\StudentsDB\NEW.txt -pass pass:)";
        command += this->pass;
        system(command.c_str());

        if (remove("C:/StudentsDB/NEW.txt.enc") != 0) {
            cout << "[ERROR] - deleting file" << endl;
        }
    }
};