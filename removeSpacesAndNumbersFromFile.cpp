#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string lineFromFile, temp;
    ifstream myFileRead("D:\\input.txt");

    if(!myFileRead.is_open()) {
        cout << "Error opening file" << endl;
    }
    else {
        while (!myFileRead.eof()) {

            getline(myFileRead, temp);

            lineFromFile += temp;

            if (!myFileRead.eof()) {
                lineFromFile += '\n';
            }
        }

        myFileRead.close();

        int i = 0;

        while (i < lineFromFile.length()) {

            if ((int)lineFromFile[i] == (int)' '
                || (int)lineFromFile[i] == (int)'0' 
                || (int)lineFromFile[i] == (int)'1'
                || (int)lineFromFile[i] == (int)'2'
                || (int)lineFromFile[i] == (int)'3'
                || (int)lineFromFile[i] == (int)'4'
                || (int)lineFromFile[i] == (int)'5'
                || (int)lineFromFile[i] == (int)'6'
                || (int)lineFromFile[i] == (int)'7'
                || (int)lineFromFile[i] == (int)'8'
                || (int)lineFromFile[i] == (int)'9') {

                lineFromFile.erase(i, 1);
            }
            else {
                i++;
            }
        }
    }

    ofstream myFileRecord("D:\\input.txt");

    if (!myFileRecord.is_open()) {
        cout << "Error opening file" << endl;
    }
    else {
        myFileRecord << lineFromFile << endl;
        myFileRecord.close();
    }

    return 0;
}