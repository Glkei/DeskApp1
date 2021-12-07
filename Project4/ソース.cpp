#include <iostream>
#include <iomanip>
#include <string> //文字列ライブラリー
#include <vector> //配列ライブラリー

//商品情報
struct item {
	std::string name; //商品名
	int price; //金額（税抜き）
	int category; //カテゴリ
	int quantity; //個数
};
//カテゴリの登録
std::vector<std::string> catName{
	{"食品"},{"飲料"},{"文房具"},{"本"},{"雑貨"}
};
//初期の商品登録
std::vector<item> product{
	//{"商品名",金額,カテゴリ,個数}
	{"おにぎり(ツナ)",120,0,10},
	{"おにぎり(鮭)",120,0,10},
	{"オレンジジュース",100,1,10},
	{"鉛筆(黒)",50,2,100},
	{"消しゴム（小）",50,2,10},
};

//商品一覧
void productListView() {
	std::cout << "商品一覧表示\n";

	for (int i = 0; i < product.size(); i++) {
		std::cout << std::setw(20) << std::left << product[i].name << "";
		std::cout << std::setw(10) << std::right << product[i].price << "円\t";
		std::cout << catName[product[i].category] << "\t";
		std::cout << product[i].quantity << "個";
		std::cout << "\n";
	}
};

//商品登録
void addItem() {
	std::string name; //商品名
	int price; //金額（税抜き）
	int category; //カテゴリ
	int quantity; //個数

	std::cout << "商品名：";
	std::cin >> name;

	std::cout << "金額：";
	std::cin >> price;

	//カテゴリー一覧の表示
	for (int i = 0; i < catName.size(); i++) {
		std::cout << catName[i] << ":" << i << "\n";
	}
	std::cout << "カテゴリ：";
	std::cin >> category;

	std::cout << "個数：";
	std::cin >> quantity;

	//商品の追加
	product.push_back(
		{ name,price,category,quantity }
	);

	std::cout << "登録完了\n";
}

//商品編集
void editItem() {
	int num;
	for (int i = 0; i < product.size(); i++) {
		std::cout << i << product[i].name << "\n";
	}
	std::cout << "編集する番号を選択：";
	std::cin >> num;

	//商品名
	std::cout << "商品名：" << product[num].name << "\n";
	std::cin >> product[num].name;

	//金額
	std::cout << "金額：" << product[num].price << "\n";
	std::cin >> product[num].price;

	//カテゴリ
	for (int i = 0; i < catName.size(); i++) {
		std::cout << i << ":" << catName[i] << "\n";
	}
	std::cout << "カテゴリ：" << product[num].category << "\n";
	std::cin >> product[num].category;

	//個数
	std::cout << "個数：" << product[num].quantity << "\n";
	std::cin >> product[num].quantity;

}

//商品削除
void deleteItem() {
	//商品一覧の表示
	int num;
	std::string conform;
	for (int i = 0; i < product.size(); i++) {
		std::cout << i << product[i].name << "\n";
	}
	std::cout << "削除する番号を選択：";
	std::cin >> num;

	std::cout << "削除しますか(y/n)";
	std::cin >> conform;

	//削除の実行
	if (conform == "y" || conform == "Y") {
		product.erase(product.begin() + num);
		std::cout << "削除しました\n";
	}
	else {
		std::cout << "キャンセルしました。\n";
	}
}


//カテゴリ追加
void addCategory() {
	std::string name;

	for (int i = 0; i < catName.size(); i++) {
		std::cout << i << ":" << catName[i] << "\n";
	}

	std::cout << "カテゴリ追加：";
	std::cin >> name;

	//カテゴリに追加
	catName.push_back({ name });
}


//カテゴリ毎の一覧

int main() {
	std::cout << "商品管理システム\n";
	int selector = 0;

	while (selector != 99) {
		std::cout << "一覧:0 追加:1 削除:2 編集:3\n";
		std::cout << "カテゴリ追加:11 \n";
		std::cout << "終了:99：";

		std::cin >> selector;
		system("cls");//画面クリア

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