#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
    float score;
};

int main() {
    ifstream fin("data.txt");
    ofstream fout("result.txt");

    Student s[100];
    int count = 0;

    // Read data
    while (fin >> s[count].id >> s[count].name >> s[count].score) {
        count++;
    }

    float sum = 0, max = s[0].score, min = s[0].score;
    int pass = 0, fail = 0;

    // Analysis
    for (int i = 0; i < count; i++) {
        sum += s[i].score;
        if (s[i].score > max) max = s[i].score;
        if (s[i].score < min) min = s[i].score;
        if (s[i].score >= 60) pass++;
        else fail++;
    }

    float mean = sum / count;

    // Output
    cout << "Average Score: " << mean << endl;
    cout << "Highest Score: " << max << endl;
    cout << "Lowest Score: " << min << endl;
    cout << "Pass: " << pass << "  Fail: " << fail << endl;

    fout << "Average Score: " << mean << endl;
    fout << "Highest Score: " << max << endl;
    fout << "Lowest Score: " << min << endl;
    fout << "Pass: " << pass << "  Fail: " << fail << endl;

    fin.close();
    fout.close();

    return 0;
}

