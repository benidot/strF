#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

struct patient {
    char p;
    string pwd;
    int tm;
};

list<patient> qe;
vector<int> waits;
int calls,v,a,d,b,fv,fa,fd,fb = 0;

bool method(const patient &a, const patient &b) {
    return a.tm < b.tm;
}

void final() {
    waits.shrink_to_fit();
    if(waits.empty()) {
        waits.push_back(0);
    }
    cout << "--- RELATÓRIO FINAL ---"
         << "\nTotal atendidos: " << calls
         << "\nPor prioridade: " << fv << " V, " << fa << " A, " << fd << " D, " << fb << " B"
         << "\nPico de lotação: " << waits.size()
         << "\nEspera máxima: " << waits.back() << " min"
         << endl;
}

void current() {
    cout << "V:"  << v
         << " A:" << a
         << " D:" << d
         << " B:" << b
         << " | Atendidos:" << calls
         << endl;
}

void addP() {
    patient temp;
    int temphr;
    cin >> temp.pwd >> temp.p >> temphr >> temp.tm;
    temp.p = toupper(temp.p);
    switch(temp.p) {
        case 'V': v++; break;
        case 'A': a++; break;
        case 'D': d++; break;
        case 'B': b++; break;
    }

    temp.tm += (temphr * 60);
    qe.push_back(temp);
}

void callP() {
    int temphr, tempmin;
    cin >> temphr >> tempmin;
    int thr = temphr; int tmin = tempmin;
    temphr *= 60;
    tempmin += temphr;
    if (!qe.empty()) {
        int wait = tempmin - qe.front().tm;
        waits.push_back(wait); 
        qe.pop_front();
        calls++;

        switch(qe.front().p) {
            case 'V': v--; fv++; break;
            case 'A': a--; fa++; break;
            case 'D': d--; fd++; break;
            case 'B': b--; fb++; break;
        }

    } else {
        cout << setfill('0') << setw(2) << thr << " " << tmin << " Sem pacientes aguardando atendimento" << endl;
    }

}

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