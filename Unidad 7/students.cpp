#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX = 50;
typedef struct
{
    string name;
    string surname;
    string dni;
    int age;
    int studentMark;
} Student;

typedef Student Students[MAX];

typedef struct
{
    Students students;
    int counter;
} StudentList;

int i;

void loadFile(StudentList &studentList);
void saveFile(StudentList &studentList);
void addStudent(StudentList &studentList);
void deleteStudent(StudentList &studentList, string name, string surname);
void gradeStudent(StudentList &studentList);
void showStudentMarks(StudentList &studentList);

int main()
{
    StudentList studentList;
    string name,surname;
    int option;
    studentList.counter = 0;
    loadFile(studentList);
    do 
    {
        cout << "1 - Añadir un nuevo alumno" << endl;
        cout << "2 - Eliminar un alumno" << endl;
        cout << "3 - Calificar alumnos" << endl;
        cout << "4 - Listado de notas" << endl;
        cout << "0 - Salir" << endl;
        cin >> option;

        switch(option)
        {
            case 1:
                //Añadir alumnos
                addStudent(studentList);
                break;
            case 2:
                //Eliminar alumno
                cout << "Ingrese el nombre del alumno que desee eliminar: ";
                cin >> name;
                cout << "Ingrese el apellido del alumno que desee eliminar: ";
                cin >> surname;
                deleteStudent(studentList, name, surname);
                break;
            case 3:
                //Calificar alumnos
                gradeStudent(studentList);
                break;
            case 4:
                //Listado de notas alumnos
                showStudentMarks(studentList);
                break;
            case 0:
                //Guardamos y salimos
                saveFile(studentList);
                break;
            default:
                cout << "Opcion desconocida!" << endl;
                break;
        }
    } while (option != 0);
    
    return 0;
}

void loadFile(StudentList &studentList)
{
    ifstream file;
    file.open("AyED.txt", ios::in);
    if(file.is_open())
    {
        while (!file.eof())
        {
            file >> studentList.students[studentList.counter].name;
            file.get();
            file >> studentList.students[studentList.counter].surname;
            file.get();
            file >> studentList.students[studentList.counter].dni;
            file >> studentList.students[studentList.counter].age;
            file >> studentList.students[studentList.counter].studentMark;

            if((!studentList.students[studentList.counter].name.empty())&&(!studentList.students[studentList.counter].surname.empty())&&(!studentList.students[studentList.counter].dni.empty())&&(studentList.students[studentList.counter].age != 0)&&(studentList.students[studentList.counter].studentMark >= 0))
            {
                studentList.counter++;
            }
        }
    }
    file.close();
}

void saveFile(StudentList &studentList)
{
    ofstream file;
    file.open("AyED.txt", ios::out);
    if(file.is_open())
    {
        for(i = 0; i < studentList.counter; i++)
        {
             file << studentList.students[i].name<< " " << studentList.students[i].surname << " " <<studentList.students[i].dni << " " << studentList.students[i].age << " " << studentList.students[i].studentMark <<endl;
        }
    }
    file.close();
}

void addStudent(StudentList &studentList)
{
    if(studentList.counter < MAX)
    {
        cout << "Ingrese el nombre del alumno: ";
        cin.ignore();
        getline(cin,studentList.students[studentList.counter].name);
        cout << "Ingrese el apellido del alumno: ";
        getline(cin,studentList.students[studentList.counter].surname);
        cout << "Ingrese el DNI del alumno: ";
        getline(cin,studentList.students[studentList.counter].dni);
        cout << "Ingrese la edad del alumno: ";
        cin >> studentList.students[studentList.counter].age;
        studentList.students[studentList.counter].studentMark = 0;
        studentList.counter = (studentList.counter + 1);

    }
    else
    {
        cout << "Maximo de archivos alcanzados (50)!" << endl;
    }
}

void deleteStudent(StudentList &studentList, string name, string surname)
{
    int pos = 0;
    for(i = 0; i < studentList.counter; i++)
    {
        if((studentList.students[i].name == name)&&(studentList.students[i].surname == surname))
        {
            pos = i;
            for(i = pos; i < studentList.counter - 1; i++)
            {
                studentList.students[i] = studentList.students[i+1];
            }
            studentList.counter = (studentList.counter - 1);
            cout << "Alumno eliminado correctamente!" << endl;
        }
        //i = studentList.counter;
    }

}

void gradeStudent(StudentList &studentList)
{
    int studentMark;
    for(i=0; i < studentList.counter; i++)
    {
        cout << "Nombre del alumno: " << studentList.students[i].name << endl;
        cout << "Apellido del alumno: " << studentList.students[i].surname << endl;
        cout << "Ingrese nota del alumno: ";
        cin >> studentMark;
        if((studentMark>=1)&&(studentMark <=10))
        {
            studentList.students[i].studentMark = studentMark;
        } 
        else 
        {
            cout << "Nota no valida!" << endl;
            cout << "Reingrese la nota de: " << studentList.students[i].name << " " << studentList.students[i].surname << endl;
            cin >> studentMark;
            studentList.students[i].studentMark = studentMark;
        }
    }
}

void showStudentMarks(StudentList &studentList)
{
    double average = 0;
    int total, highestMark = 0;
    string name, surname;

    cout << "Listado de notas:" << endl;
    for(i = 0; i < studentList.counter; i++)
    {
        cout << studentList.students[i].studentMark << endl;
        if(studentList.students[i].studentMark >= highestMark)
        {
            highestMark = studentList.students[i].studentMark;
            name = studentList.students[i].name;
            surname = studentList.students[i].surname;
        }
        average = average + studentList.students[i].studentMark;
        total = i;
    }
    average = (average/i);
    cout << "La nota mas alta pertenece a: " << name << " " << surname << " y es: " << highestMark << endl;
    cout << "La nota media es: " << average << endl;
}
