#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

struct patient {
    char p;
    string pwd;
    int tm;
};

bool method(const patient &a, const patient &b) {
    return &a.tm < &b.tm;
}

void final() {
    cout << "--- RELATÓRIO FINAL ---"
         << "\nTotal atendidos: "
         << "\nPor prioridade: "
         << "\nPico de lotação: "
         << "\nEspera máxima: " << waits[0] << " min"
         << endl;
}

void current() {
    cout << "V:"
         << " A:"
         << " D:"
         << " B:"
         << " | Atendidos:"
         << endl;
}

void addP() {
    patient temp;
    int temphr;
    cin >> temp.pwd >> temp.p >> temphr >> temp.tm;
    temp.tm += (temphr * 60);
    qe.push_back(temp);
    sort(qe.begin(), qe.end(), method);
}

void callP() {
    int temphr,tempmin;
    cin >> temphr >> tempmin;
    temphr *= 60;
    tempmin += temphr;
    int wait = qe[0].tm - tempmin;
    waits.push_back(wait);
}

vector<patient> qe;
vector<int> waits;

int main() {

    while(true) {
        char command;
        cin >> command;
        command = tolower(command);

        if (command == 'q') {
            final();
            break;
        }
        else if (command == 'd') {
            current();
        }
        else if (command == 'c') {
            addP();
        }
        else if (command == 'a') {
            callP();
        }
    }

    return 0;
}