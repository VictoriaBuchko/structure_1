#include <iostream>
using namespace std;


//перечислимый тип данных «Живая сущность»
enum Type  //пользовательский тип данных( по умолчанию тип данных int)
{
	BIRD,    //=0
	ANIMAL,  //=1
	HUMAN    //=2
};

//объединение для характеристики
union Characteristic {

	float flightSpeed;   // Для птицы( 
	bool artiodactyls;   // Для скота(парнокопытное)
	int iqLevel;         // Для человека
};


//структура «Живая сущность»
struct Essence
{
	double speed;    //скорость 
	Type type;       //(птица, скот, человек)
	char color[50];  // Массив символов для цвета
	Characteristic сharacteristic;   //характиристика
};

void InputEssence(Essence& essense);//Функция которая реализует ввод значений для полей структуры 
void PrintEssense(Essence& essense);//Функция которая реализует вывод значений для полей структуры
void EditEssence(Essence& essence); //Функция для редактирования определенной сущности 
void Search(Essence essence[], int essenceNum);//Функция для поиска сущности по характеристике 



int main() {
	setlocale(LC_ALL, "Ukrainian");

	const int essenceNum = 5;
	Essence essence[essenceNum];

	for (int i = 0; i < essenceNum; i++) {
		cout << "\nВвод информации о сущности " << i + 1 << endl;
		InputEssence(essence[i]);
	}

	while (true) {
		cout << "\nМеню:\n";
		cout << "1. Печать всего списка\n";
		cout << "2. Редактировать данные\n";
		cout << "3. Поиск по характеристике\n";
		cout << "4. Выход\n";

		int choice;
		cout << "Выберите действие (1-4): ";
		cin >> choice;

		switch (choice) {
		case 1://Печать всего списка
			for (int i = 0; i < essenceNum; i++) {
				cout << "\nСущность " << i + 1 << ":" << endl;
				PrintEssense(essence[i]);
				cout << "------------------------------------" << endl;
			}
			break;

		case 2://Редактировать данные
			int editIndex;
			cout << "Введите номер сущности для редактирования (1-" << essenceNum << "): ";
			cin >> editIndex;

			if (editIndex >= 1 && editIndex <= essenceNum) {

				EditEssence(essence[editIndex - 1]);

				cout << "\nИнформация о сущности " << editIndex << " после редактирования:" << endl;
				PrintEssense(essence[editIndex - 1]);
			}
			else {
				cout << "Недопустимый номер сущности" << endl;
			}
			break;

		case 3://Поиск по характеристике

		    Search(essence, essenceNum);
			break;

		case 4:
			return 0;

		default:
			cout << "Недопустимый выбор. Пожалуйста, выберите снова\n";
		}
	}

	return 0;
}



void InputEssence(Essence& essence) {//Функция для записи значений для структуры 

	cout << "Введите скорость передвижения: ";//ввод для заполнения поля структуры скорость 
	cin >> essence.speed;


	//ввод для заполнения поля структуры тип 
	int essenceType;
	cout << "Введите тип (0 - птица, 1 - скот, 2 - человек): ";
	cin >> essenceType;
	essence.type = (Type)essenceType;


	//ввод для заполнения поля структуры тип 
	cout << "Введите цвет: ";
	cin >> essence.color;

	if (essence.type == BIRD)
	{
		cout << "Введите скорость полета:";
		cin >> essence.сharacteristic.flightSpeed;// в структуре сущность обращаемся к полю характеристика( подхарактеристика(обьединение))
	}
	else if (essence.type == ANIMAL) {

		cout << "Является ли парнокопытным (0 - нет, 1 - да): ";
		cin >> essence.сharacteristic.artiodactyls;
	}
	else if (essence.type == HUMAN) {

		cout << "Введите IQ: ";
		cin >> essence.сharacteristic.iqLevel;
	}
}



void PrintEssense(Essence& essence) {

	cout << "Скорость передвижения: " << essence.speed << endl;
	cout << "Тип: " << essence.type << endl;
	cout << "Цвет: " << essence.color << endl;

	if (essence.type == BIRD) {

		cout << "Скорость полета: " << essence.сharacteristic.flightSpeed << endl;
	}
	else if (essence.type == ANIMAL) {

		cout << "Парнокопытное: " << (essence.сharacteristic.artiodactyls ? "Да" : "Нет") << endl;
	}
	else if (essence.type == HUMAN) {

		cout << "Уровень IQ: " << essence.сharacteristic.iqLevel << endl;
	}
}


void EditEssence(Essence& essence) {

	cout << "\nРедактирование информации о сущности:\n";
	InputEssence(essence);
}


void Search(Essence essence[], int essenceNum) {

	int searchType;
	cout << "Введите характеристику для поиска (0 - скорость полета, 1 - парнокопытное, 2 - уровень IQ): ";
	cin >> searchType;

	bool found = false;

	if (searchType >= 0 && searchType <= 2) {

		switch (searchType) {

		case 0: //поиск по скорости полета
			float searchSpeed;
			cout << "Введите скорость полета для поиска: ";
			cin >> searchSpeed;

			cout << "Результаты поиска по скорости полета " << searchSpeed << ":\n";
			for (int i = 0; i < essenceNum; i++) {

				if (searchType == 0 && essence[i].type == BIRD) {

					cout << "Сущность " << i + 1 << ":\n";
					PrintEssense(essence[i]);
					cout << "------------------------------------\n";
					found = true;
				}
			}

			break;

		case 1: //поиск по парнокопытным
			bool searchArtiodactyls;
			cout << "Ищем парнокопытных (0 - нет, 1 - да): ";
			cin >> searchArtiodactyls;

			cout << "Результаты поиска по парнокопытным\n";
			for (int i = 0; i < essenceNum; i++) {

				if (searchType == 1 && essence[i].type == ANIMAL) {

					cout << "Сущность " << i + 1 << ":\n";
					PrintEssense(essence[i]);
					cout << "------------------------------------\n";
					found = true;
				}
			}


			break;

		case 2: //поиск по уровню IQ
			int searchIQ;
			cout << "Введите уровень IQ для поиска: ";
			cin >> searchIQ;

			cout << "Результаты поиска по уровню IQ " << searchIQ << ":\n";
			for (int i = 0; i < essenceNum; i++) {

				if (searchType == 2 && essence[i].type == HUMAN) {

					cout << "Сущность " << i + 1 << ":\n";
					PrintEssense(essence[i]);
					cout << "------------------------------------\n";
					found = true;
				}
			}

			break;
		}

		if (!found) {
			cout << "Сущностей с указанной характеристикой не найдено\n";
		}

	}
	else {
		cout << "Недопустимая характеристика для поиска\n";
	}
}


