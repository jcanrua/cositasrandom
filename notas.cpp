#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
using namespace std;

class Estudiante{
    private:
        string name;
        string surname;
        float nota;
    public:
        void definir_name(const string& name){
            this->name = name;
        }
        void definir_surname(const string& surname){
            this->surname = surname;
        }
        void definir_nota(float nota){
            this->nota = nota;
        }
        float obtener_nota() const {
            return nota;
        }
        string obtener_nombre() const {
            return name;
        }
        string obtener_apellidos() const {
            return surname;
        }
        void imprimir() const{
            cout << "Nota: " << nota << " Apellidos: " << surname << " Nombre: " << name << endl;
        }
    };

void readInput(vector<Estudiante>& estudiantes) {
    string line;
    while (getline(cin, line)) {
        Estudiante estudiante;
        int commaPos = line.find(',');
        int lastSpacePos = line.find_last_of(" ");

        string surname = line.substr(0, commaPos);
        string name = line.substr(commaPos + 2, lastSpacePos - commaPos - 2);
        float nota = stof(line.substr(lastSpacePos + 1));
        
        estudiante.definir_surname(surname);
        estudiante.definir_name(name);
        estudiante.definir_nota(nota);

        estudiantes.push_back(estudiante);
    }
}

void calcular(float& media, float& alta, float& baja, vector<Estudiante>& estudiantes, vector<string>& notaAlta, vector<string>& notaBaja){
    for (const auto& estudiante : estudiantes) {
        if(estudiante.obtener_nota() > alta){
            alta = estudiante.obtener_nota();
            notaAlta.clear();
            notaAlta.push_back(estudiante.obtener_nombre() + " " + estudiante.obtener_apellidos());
        }
        else if(estudiante.obtener_nota() == alta){
            notaAlta.push_back(estudiante.obtener_nombre() + " " + estudiante.obtener_apellidos());
        }

        if(estudiante.obtener_nota() < baja){
            baja = estudiante.obtener_nota();
            notaBaja.clear();
            notaBaja.push_back(estudiante.obtener_nombre() + " " + estudiante.obtener_apellidos());
        }
        else if(estudiante.obtener_nota() == baja){
            notaBaja.push_back(estudiante.obtener_nombre() + " " + estudiante.obtener_apellidos());
        }

        media += estudiante.obtener_nota();  
    }
    media /= estudiantes.size();
}

void imprimir(float& media, float& alta, float& baja, vector<string>& notaAlta, vector<string>& notaBaja){
    cout << "Nota media = " << media << endl;
    cout << endl;
    cout << "Nota más alta = " << alta << endl;
    cout << "Obtenida por: " << endl;
    for(int i = 0; i < notaAlta.size();i++){
        cout << "   " << notaAlta[i] << endl;
    }
    cout << endl;
    cout << "Nota más baja = " << baja << endl;
    cout << "Obtenida por: " << endl;
    for(int i = 0; i < notaBaja.size();i++){
        cout << "   " << notaBaja[i] << endl;
    }
}

int main(){
    vector<Estudiante> estudiantes;
    float media = 0, alta = 0, baja = 10;
    vector<string> notaAlta, notaBaja;
    string line;
    readInput(estudiantes);
    calcular(media, alta, baja, estudiantes, notaAlta, notaBaja);
    imprimir(media, alta, baja, notaAlta, notaBaja);
}

