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
    int v,a,d,b,ate,peak,mins;
    v=a=d=b=ate=peak=mins=0;
    while(cin>>command) {
        patient temp;
        if (command == 'C') {
            cin >> temp.passkey >> temp.priority >> temp.hour >> temp.minute;
            arr.push_back(temp);
        }
        else if (command == 'A') {
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
                 << "Por prioridade: V=" << v << " A=" << a << " D=" << d << " B=" << b << endl
                 << "Pico de lotação: " << peak << endl
                 << "Espera máxima: " << mins << " min" << endl;
            break;
        }
        else if (command == 'D') {
            cout << "V:" << endl;// and the rest
        }
    }

    return 0;
}
