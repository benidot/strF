#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

struct patient {
    string color;
    char priority;
    string passkey;
    int hour;
    int minute;
};

int main() {

    char command;
    vector<patient> arr,V,A,D,B;
    int v,a,d,b,ate,peak,mins,aV,aA,aD,aB;
    v=a=d=b=ate=peak=mins=aV=aA=aD=aB=0;
    while(cin>>command) {
        patient temp;
        if (command == 'C') {
            cin >> temp.passkey >> temp.priority >> temp.hour >> temp.minute;
            if (temp.priority == 'V') {
                V.push_back(temp);
                v++;
            } else if (temp.priority == 'A') {
                A.push_back(temp);
                a++;
            } else if (temp.priority == 'D') {
                D.push_back(temp);
                d++;
            } else if (temp.priority == 'B') {
                B.push_back(temp);
                b++;
            }
        }
        else if (command == 'A') { // okay i gotta redo all this
            int temphr; int tempmin;
            cin >> temphr >> tempmin;
            for(auto i:arr) {
                if(i.hour == temphr && i.minute == tempmin) {
                    ate++;
                    break;
                }
            }
            cout << temphr << " " << tempmin << " " << "Sem pacientes aguardando atendimento\n";
        }
        else if (command == 'Q') {
            cout << "--- RELATÓRIO FINAL ---" << endl
                 << "Total atendidos: " << ate << endl
                 << "Por prioridade: V=" << aV << " A=" << aA << " D=" << aD << " B=" << aB << endl
                 << "Pico de lotação: " << peak << endl
                 << "Espera máxima: " << mins << " min" << endl;
            break;
        }
        else if (command == 'D') {
            cout << "V:" << v << " A:" << a << " D:" << d << " B:" << b << " | Atendidos: " << ate << endl;
        }
    }

    return 0;
}
