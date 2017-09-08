#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>



using namespace std;
using std::cout;
using std::cin;
using std::endl;

FILE* cfPtr;
void printhelp();
int init();
void save_users();
int Administrator_login();
int user_login();
void create_user();
void modify_user();
void search_user();
void delete_user();
void show_info();
void login_help();
int choose;
int flag = 1;
enum  Mainmenu {
	Mainmenu_create = 1,
	Mainmenu_modify = 2,
	Mainmenu_search = 3,
	Mainmenu_delete = 4,
	Mainmenu_login = 5,
	Mainmenu_show = 6,
	Mainmenu_exit = 0,
};
struct user_info {
	char * name;
	char* pwd;
	int age;
	user_info() {
		name = (char *)calloc(1, 256);
		pwd = (char *)calloc(1, 256);
		age = -1;
	}

};
struct ListNode {
	user_info *data;
	struct ListNode *nextPtr;
	ListNode() :data(0), nextPtr(0) {

	}

};
void insertlist(user_info*);


ListNode *headPtr = 0;
ListNode*tailPtr = 0;

static const char* INIT_FILE = "/home/zf/Documents/cpp/user.txt";

int main()
{
	cout << "\n\n\n" << endl;
	cout << "  *********************************************************************" << endl;
	cout << "  *                                                                   *" << endl;
	cout << "  *                           ¡ïWelcone To Use USM¡ï                    *" << endl;
	cout << "  *               Following is some choose for you !                  *" << endl;
	cout << "  *               You must choose according to the following !!       *" << endl;
	cout << "  *********************************************************************" << endl;
	init();
	bool exit = false;

	while (1) {

		printhelp();
		cout << "Enter your choose:";
		cin >> choose;

		switch (choose) {
		case 0: {
					exit = true;
					break;
		}


		case 1: {
					create_user();
		}
			break;

		case 2: {
					search_user();
		}
			break;

		case 3: {
					modify_user();

		}
			break;

		case 4: {
					delete_user();
		}
			break;

		case 5: {
					user_login();
		}
			break;

		case 6: {
					show_info();
		}
			break;

		case 7: {
					Administrator_login();
		}

			default
				:
					break;
		}



		if (exit) {
			save_users();
			return -1;

		}

	}
}






void insertlist(user_info* p_new_user)
{
	if (headPtr != 0 && headPtr->data == 0) {
		headPtr->data = p_new_user;
		return;
	}

	ListNode* newPtr = new ListNode;
	newPtr->data = p_new_user;


	if (headPtr == 0) {
		headPtr = newPtr;
		tailPtr = headPtr;
		return;
	}

	tailPtr->nextPtr = newPtr;
	tailPtr = tailPtr->nextPtr;

}



int init()
{
	FILE* cfPtr;

	if ((cfPtr = fopen(INIT_FILE, "w")) == NULL)
	while (!feof(cfPtr)) {
		user_info *p_new_user = new user_info;
		fscanf(cfPtr, "%s %s %d\n", p_new_user->name, p_new_user->pwd, &p_new_user->age);
		insertlist(p_new_user);
	}

	fclose(cfPtr);
	return 0;
}

void printhelp()
{


	cout << "\n\n\n" << endl;
	cout << "                ***********************************" << endl;
	cout << "                *                                 *" << endl;
	cout << "                *               ¡ïUSM¡ï             *" << endl;
	cout << "                *      Function         Enter     *" << endl;
	cout << "                *       Create           1        *" << endl;
	cout << "                *       Search           2        *" << endl;
	cout << "                *       Modify           3        *" << endl;
	cout << "                *       Delete           4        *" << endl;
	cout << "                *       User_Login       5        *" << endl;
	cout << "                *       show_info        6        *" << endl;
	cout << "                *       Admin_Login      7        *" << endl;
	cout << "                *       Exit             0        *" << endl;
	cout << "                ***********************************" << endl;



}


int  Administrator_login()
{

	cout << "\n\n\n" << endl;
	cout << "                *****************************************" << endl;
	cout << "                *                                       *" << endl;
	cout << "                *       ¡ïAdministrator Login System¡ï    *" << endl;
	cout << "                *              user name                *" << endl;
	cout << "                *              user password            *" << endl;
	cout << "                *****************************************" << endl;
	user_info* p_new_user = new user_info;
	strcpy(p_new_user->name, "admin");
	strcpy(p_new_user->pwd, "666666");
	char *name = (char *)calloc(1, 256);
	char  *pwd = (char *)calloc(1, 256);
	char flag = 0;
	int error = 0;


	while (1) {

		if (error >= 3) {
			cout << "         Login Failed !";
			return -1;
		}

		cout << "super user:";
		cin >> name;
		cin.sync();

		if (strcmp(p_new_user->name, name) == 0) {
			flag = 1;
			cout << " super password:";

			system("stty -echo");
			cin >> pwd;
			system("stty echo");
			cin.sync();

			if (strcmp(p_new_user->pwd, pwd) == 0) {
				cout << " \n   Successful Login !!";
				return 0;
			}
			else {
				error++;
				cout << "\n password is error,please enter again!\n";
			}
		}


		if (!flag) {
			cout << "the user don`t exist!";
			return flag;
		}
	}

}
int  user_login()
{
	cout << "\n\n\n" << endl;
	cout << "                ***********************************" << endl;
	cout << "                *                                 *" << endl;
	cout << "                *       ¡ïUser Login System¡ï       *" << endl;
	cout << "                *        user name                *" << endl;
	cout << "                *        user password            *" << endl;
	cout << "                ***********************************" << endl;
	ListNode* temPtr = headPtr;
	char *name = (char *)calloc(1, 256);
	char  *pwd = (char *)calloc(1, 256);
	char flag = 0;
	int error = 0;
	cout << " user name:";
	cin >> name;
	cin.sync();


	while (temPtr) {
		while (1) {
			if (error >= 3) {
				cout << "Login Failed !";
				return -1;
			}

			if (strcmp(temPtr->data->name, name) == 0) {
				flag = 1;
				cout << "  user password:";
				system("stty -echo");
				cin >> pwd;
				system("stty echo");
				cin.sync();

				if (strcmp(temPtr->data->pwd, pwd) == 0) {
					cout << "\n   successful login";
					return 0;
				}
				else {
					error++;
					cout << "\n    password is error,please enter again!";
				}
			}


			else {
				temPtr = temPtr->nextPtr;
			}

		}

	}

	if (!flag) {
		cout << "the user don`t exist!";
		return 0;
	}

	return 0;
}

void save_users()
{
	remove(INIT_FILE);
	cfPtr = fopen(INIT_FILE, "w+");
	ListNode *temPtr = headPtr;

	if (cfPtr == 0) {
		return;
	}

	while (temPtr) {
		user_info* p_new_user = temPtr->data;
		fprintf(cfPtr, "%s %s %d\n", p_new_user->name, p_new_user->pwd, p_new_user->age);
		temPtr = temPtr->nextPtr;
	}

	fclose(cfPtr);
}

void save_user(user_info* p_new_user)
{
	ListNode *temPtr = headPtr;
	cfPtr = fopen(INIT_FILE, "w+");

	while (temPtr) {
		user_info* p_new_user = temPtr->data;
		fprintf(cfPtr, "%s %s %d\n", p_new_user->name, p_new_user->pwd, p_new_user->age);
		temPtr = temPtr->nextPtr;
	}

	fclose(cfPtr);
}

void create_user()
{
	char *name = (char*)calloc(1, 20);
	cout << "Enter your name:";
	cin >> name;

	if (strcmp(name, "admin") == 0) {
		cout << "\n\n\n" << endl;
		cout << "                ***********************************" << endl;
		cout << "                *        ¡ïCreate User¡ï            *" << endl;
		cout << "                *        user name                *" << endl;
		cout << "                *        user password            *" << endl;
		cout << "                *        user age                 *" << endl;
		cout << "                ***********************************" << endl;

		user_info *p_new_user = new user_info;
		ListNode *temPtr = headPtr;
		cout << "input user name:" << endl;
		cin >> p_new_user->name;
		cout << "input user pwd:\n" << endl;
		system("stty -echo");
		cin >> p_new_user->pwd;
		system("stty echo");
		cout << "input user age:" << endl;
		cin >> p_new_user->age;
		insertlist(p_new_user);
		save_user(p_new_user);
		cout << "\n\n\ncreated!";


	}

	else {
		cout << "no power!";
		return;
	}
}

void delete_user()
{
	cout << "\n\n\n" << endl;
	cout << "                ************************************" << endl;
	cout << "                *        ¡ïDelete User¡ï             *" << endl;
	cout << "                *         user name                *" << endl;
	cout << "                ************************************" << endl;

	char *name = (char*)calloc(1, 20);
	cout << "Enter your name:";
	cin >> name;

	if (strcmp(name, "admin") == 0) {

		char *user_name = (char *)calloc(1, 256);
		ListNode *tempPtr;
		char flag = 0;
		cout << "\nEnter the need delete user name:";
		cin >> user_name;

		while (headPtr) {
			if (strcmp(headPtr->data->name, user_name) == 0) {
				tempPtr = headPtr;
				headPtr = headPtr->nextPtr;
				free(tempPtr);
				flag = 1;

				cout << "\nDelete sucessful!";
				break;
			}

			headPtr = headPtr->nextPtr;

		}



		if (!flag) {
			cout << "the user don`t exist!";
		}


	}
	else {
		cout << "No Power !";
		return;
	}
}





void modify_user()
{

	cout << "\n\n\n" << endl;
	cout << "                ************************************" << endl;
	cout << "                *        ¡ïModify User¡ï             *" << endl;
	cout << "                *        user name                 *" << endl;
	cout << "                *        user new password         *" << endl;
	cout << "                *        user new age              *" << endl;
	cout << "                ************************************" << endl;
	char *user_name = (char *)calloc(1, 20);
	char *pwd = (char *)calloc(1, 16);
	char *Name = (char *)calloc(1, 20);

	int age;

	char flag = 0;
	cout << "Enter the need modify user name:";
	cin >> user_name;
	cout << "Enter your name :";
	cin >> Name;

	if ((strcmp(Name, user_name) == 0) || strcmp(Name, "admin") == 0) {

		ListNode*temPtr = headPtr;

		while (temPtr) {
			if (strcmp(temPtr->data->name, user_name) == 0) {
				cout << "Enter the new password:";
				system("stty -echo");
				cin >> pwd;
				system("stty echo");
				cout << "Enter the age:";
				cin >> age;
				strcpy(temPtr->data->pwd, pwd);
				temPtr->data->age = age;
				flag = 1;
				break;
			}
			else {
				temPtr = temPtr->nextPtr;
			}
		}

		if (!flag) {
			cout << "the user don`t exist!";
			return;
		}

		cout << "modify sucessful!";

	}
}

void search_user()
{

	cout << "\n\n\n" << endl;
	cout << "                ***********************************" << endl;
	cout << "                *        ¡ïSearch User¡ï            *" << endl;
	cout << "                *         user name               *" << endl;
	cout << "                ***********************************" << endl;
	ListNode *temPtr = headPtr;
	char *user_name = (char *)calloc(1, 256);
	char flag = 0;
	cout << "Enter the need search user name:  \n\n";
	cin >> user_name;

	while (temPtr) {
		if (strcmp(temPtr->data->name, user_name) == 0) {
			cout << "The user name is:  ";
			cout << temPtr->data->name;
			cout << "\nThe user age is:";
			cout << temPtr->data->age << endl;
			flag = 1;
			break;
		}

		temPtr = temPtr->nextPtr;

	}

	if (!flag) {
		cout << "the user don`t exist!";
		return;
	}

	cout << "search sucessful!";

}
void show_info()
{
	ListNode *temPtr = headPtr;
	cout << "\n\n\n" << endl;
	cout << "                **************************************" << endl;
	cout << "                *        ¡ïShow_Info¡ï                 *" << endl;
	cout << "                *         user name                  *" << endl;
	cout << "                *         user age                   *" << endl;
	cout << "                **************************************" << endl;
	cout << "                user_name              user_age\n";

	while (temPtr) {
		cout << "              " << temPtr->data->name << "                  " << temPtr->data->age << endl;
		temPtr = temPtr->nextPtr;
	}

	return;
}