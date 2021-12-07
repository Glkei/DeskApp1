#include <iostream>
#include <iomanip>
#include <string> //�����񃉃C�u�����[
#include <vector> //�z�񃉃C�u�����[

//���i���
struct item {
	std::string name; //���i��
	int price; //���z�i�Ŕ����j
	int category; //�J�e�S��
	int quantity; //��
};
//�J�e�S���̓o�^
std::vector<std::string> catName{
	{"�H�i"},{"����"},{"���[��"},{"�{"},{"�G��"}
};
//�����̏��i�o�^
std::vector<item> product{
	//{"���i��",���z,�J�e�S��,��}
	{"���ɂ���(�c�i)",120,0,10},
	{"���ɂ���(��)",120,0,10},
	{"�I�����W�W���[�X",100,1,10},
	{"���M(��)",50,2,100},
	{"�����S���i���j",50,2,10},
};

//���i�ꗗ
void productListView() {
	std::cout << "���i�ꗗ�\��\n";

	for (int i = 0; i < product.size(); i++) {
		std::cout << std::setw(20) << std::left << product[i].name << "";
		std::cout << std::setw(10) << std::right << product[i].price << "�~\t";
		std::cout << catName[product[i].category] << "\t";
		std::cout << product[i].quantity << "��";
		std::cout << "\n";
	}
};

//���i�o�^
void addItem() {
	std::string name; //���i��
	int price; //���z�i�Ŕ����j
	int category; //�J�e�S��
	int quantity; //��

	std::cout << "���i���F";
	std::cin >> name;

	std::cout << "���z�F";
	std::cin >> price;

	//�J�e�S���[�ꗗ�̕\��
	for (int i = 0; i < catName.size(); i++) {
		std::cout << catName[i] << ":" << i << "\n";
	}
	std::cout << "�J�e�S���F";
	std::cin >> category;

	std::cout << "���F";
	std::cin >> quantity;

	//���i�̒ǉ�
	product.push_back(
		{ name,price,category,quantity }
	);

	std::cout << "�o�^����\n";
}

//���i�ҏW
void editItem() {
	int num;
	for (int i = 0; i < product.size(); i++) {
		std::cout << i << product[i].name << "\n";
	}
	std::cout << "�ҏW����ԍ���I���F";
	std::cin >> num;

	//���i��
	std::cout << "���i���F" << product[num].name << "\n";
	std::cin >> product[num].name;

	//���z
	std::cout << "���z�F" << product[num].price << "\n";
	std::cin >> product[num].price;

	//�J�e�S��
	for (int i = 0; i < catName.size(); i++) {
		std::cout << i << ":" << catName[i] << "\n";
	}
	std::cout << "�J�e�S���F" << product[num].category << "\n";
	std::cin >> product[num].category;

	//��
	std::cout << "���F" << product[num].quantity << "\n";
	std::cin >> product[num].quantity;

}

//���i�폜
void deleteItem() {
	//���i�ꗗ�̕\��
	int num;
	std::string conform;
	for (int i = 0; i < product.size(); i++) {
		std::cout << i << product[i].name << "\n";
	}
	std::cout << "�폜����ԍ���I���F";
	std::cin >> num;

	std::cout << "�폜���܂���(y/n)";
	std::cin >> conform;

	//�폜�̎��s
	if (conform == "y" || conform == "Y") {
		product.erase(product.begin() + num);
		std::cout << "�폜���܂���\n";
	}
	else {
		std::cout << "�L�����Z�����܂����B\n";
	}
}


//�J�e�S���ǉ�
void addCategory() {
	std::string name;

	for (int i = 0; i < catName.size(); i++) {
		std::cout << i << ":" << catName[i] << "\n";
	}

	std::cout << "�J�e�S���ǉ��F";
	std::cin >> name;

	//�J�e�S���ɒǉ�
	catName.push_back({ name });
}


//�J�e�S�����̈ꗗ

int main() {
	std::cout << "���i�Ǘ��V�X�e��\n";
	int selector = 0;

	while (selector != 99) {
		std::cout << "�ꗗ:0 �ǉ�:1 �폜:2 �ҏW:3\n";
		std::cout << "�J�e�S���ǉ�:11 \n";
		std::cout << "�I��:99�F";

		std::cin >> selector;
		system("cls");//��ʃN���A

		switch (selector)
		{
		case 0: productListView();  break;
		case 1: addItem();			break;
		case 2: deleteItem();		break;
		case 3: editItem();			break;
		case 11: addCategory();		break;
		default: selector = 99;  break;
		}
	}

	system("pause");
	return 0;
}