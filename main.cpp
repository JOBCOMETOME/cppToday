#include <iostream>
#include <cstdlib>

#define Max 1000

using namespace std;
struct Person {
    string name;
    int gender;
    int age;
    string phone;
    string address;

};
struct AddressBook {
    struct Person personArray[Max];
    int size;
};

void addPerson(AddressBook *abs) {
    if (abs->size == Max) {
        cout << "通讯录已满" << endl;
        return;
    } else {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[abs->size].name = name;

        int sex;
        cout << "请输入性别" << endl;
        cout << "0 ---- 女" << endl;
        cout << "1 ---- 男" << endl;

        while (true) {
            cin >> sex;
            if (sex == 0 || sex == 1) {
                abs->personArray[abs->size].gender = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }


        int ageValue = 0;
        cout << "请输入年龄" << endl;
        cin >> ageValue;
        abs->personArray[abs->size].age = ageValue;

        cout << "请输入联系电话" << endl;
        string phoneNumber;
        cin >> phoneNumber;
        abs->personArray[abs->size].phone = phoneNumber;

        cout << "请输入家庭地址" << endl;
        string homeAddress;
        cin >> homeAddress;
        abs->personArray[abs->size].address = homeAddress;

        abs->size++;
        cout << "添加成功" << endl;
        system("reset");
    }
}

void showPerson(AddressBook *abs) {
    if (abs->size == 0) {
        cout << "当前记录为空" << endl;
    } else {
        for (int i = 0; i < abs->size; i++) {
            cout << i + 1 << ". " << "姓名： " << abs->personArray[i].name << "\t";
            cout << "性别： " << (abs->personArray[i].gender == 1 ? "男" : "女") << "\t";
            cout << "年龄： " << abs->personArray[i].age << "\t";
            cout << "电话： " << abs->personArray[i].phone << "\t";
            cout << "住址： " << abs->personArray[i].address << endl;
        }
        cout << "已经显示全部记录" << endl;
    }
    system("clear");
}

int isExist(AddressBook *abs, const string &name) {
    for (int i = 0; i < abs->size; i++) {
        if (abs->personArray[i].name == name) {
            return i;
        }
    }
    return -1;
}

void deletePerson(AddressBook *abs) {
    cout << "请输入想要删除人员的姓名" << endl;
    string name;
    cin >> name;
    int res = isExist(abs, name);
    if (res == -1) {
        cout << "查无此人" << endl;
    } else {
        abs->personArray[res] = abs->personArray[abs->size - 1];
        abs->size--;
    }
    cout << "此人已经删除" << endl;

}

void findPerson(AddressBook *abs) {
    cout << "请输入想要查找的人员姓名" << endl;
    string name;
    cin >> name;
    if (isExist(abs, name) != -1) {
        cout << "姓名： " << abs->personArray[isExist(abs, name)].name << "\t";
        cout << "性别： " << (abs->personArray[isExist(abs, name)].gender == 1 ? "男" : "女") << "\t";
        cout << "年龄： " << abs->personArray[isExist(abs, name)].age << "\t";
        cout << "电话： " << abs->personArray[isExist(abs, name)].phone << "\t";
        cout << "住址： " << abs->personArray[isExist(abs, name)].address << endl;
    } else {
        cout << "查无此人" << endl;
    }
}

void updatePerson(AddressBook *abs) {
    cout << "请输入想要修改的人员姓名" << endl;
    string name;
    cin >> name;
    int res = isExist(abs, name);
    if (res != -1) {
        string name;
        cout << "请输入修改姓名" << endl;
        cin >> name;
        abs->personArray[res].name = name;

        cout << "请输入修改性别" << endl;
        cout << "0 ----- 女" << endl;
        cout << "1 ----- 男" << endl;
        int gender;
        cin >> gender;
        while (true) {
            if (gender == 1 || gender == 0) {
                abs->personArray[res].gender = gender;
                break;
            } else {
                cout << "请重新输入" << endl;
            }
        }

        int ageValue = 0;
        cout << "请输入年龄" << endl;
        cin >> ageValue;
        abs->personArray[res].age = ageValue;

        cout << "请输入联系电话" << endl;
        string phoneNumber;
        cin >> phoneNumber;
        abs->personArray[res].phone = phoneNumber;

        cout << "请输入家庭地址" << endl;
        string homeAddress;
        cin >> homeAddress;
        abs->personArray[res].address = homeAddress;

        cout << "修改成功" << endl;

    } else {
        cout << "查无此人" << endl;
    }
}

void clear(AddressBook *abs) {
    abs->size = 0;
    cout << "信息已经清空" << endl;

}

void showMenu() {
    cout << "***** 1. 添加联系人 *****" << endl;
    cout << "***** 2. 显示联系人 *****" << endl;
    cout << "***** 3. 删除联系人 *****" << endl;
    cout << "***** 4. 查找联系人 *****" << endl;
    cout << "***** 5. 修改联系人 *****" << endl;
    cout << "***** 6. 清空联系人 *****" << endl;
    cout << "***** 0. 退出通讯录 *****" << endl;

}

int main() {
    int select = 0;
    AddressBook addressBook;
    addressBook.size = 0;

    while (true) {
        showMenu();

        cin >> select;
        switch (select) {
            case 1:
                addPerson(&addressBook);
                break;
            case 2:
                showPerson(&addressBook);
                break;
            case 3: {
                deletePerson(&addressBook);
                break;
            }
            case 4:
                findPerson(&addressBook);
                break;
            case 5:
                updatePerson(&addressBook);
                break;
            case 6:
                clear(&addressBook);
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                return 0;

            default:
                break;
        }
    }
}
