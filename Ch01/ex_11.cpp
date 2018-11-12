#include "std_lib_facilities.h"
#include "helpers.h"

string noun(string, int);
string adjective(string, int);

int main()
{
	int coins_1 = 0;
	int coins_5 = 0;
	int coins_10 = 0;
	int coins_25 = 0;
	int coins_50 =0;
	int dollars = 0;

	coins_1 = getint("Количество одноцентовых монет: ");
	coins_5 = getint("Количество 5-центовых монет: ");
	coins_10 = getint("Количество 10-центовых монет: ");
	coins_25 = getint("Количество 25-центовых монет: ");
	coins_50 = getint("Количество 50-центовых монет: ");
	dollars = getint("Количество долларовых монет: ");

	cout << "--------------------------" << endl;
	cout << "У вас " << coins_1 << " одно" << adjective("центовая", coins_1) << ' '
		 << noun("монета", coins_1) << ',' << endl;
	cout << coins_5 << " 5-" << adjective("центовая", coins_5) << ',' << endl;
	cout << coins_10 << " 10-" << adjective("центовая", coins_10) << ',' << endl;
	cout << coins_25 << " 25-" << adjective("центовая", coins_25) << ',' << endl;
	cout << coins_50 << " 50-" << adjective("центовая", coins_50) << endl;
	cout << "и " << dollars << ' ' << adjective("долларовая", dollars) << '.' << endl;
	double full_value = dollars + (coins_50 / 2.0) + (coins_25 / 4.0) + 
					 (coins_10 / 10.0) + (coins_5 / 20.0) + (coins_1 / 100.0);
	int full_value_dollars = int(full_value);
	int full_value_cents = int(100*full_value) % 100;
	cout << "Полная стоимость ваших монет: " << full_value_dollars << ' '
		 << noun("доллар", full_value_dollars) << ", "
	 	 << full_value_cents << ' ' << noun("цент", full_value_cents) << endl;
}

string noun(string n, int qty)
{
	if (qty % 10 == 1 && qty != 11) {
		return n;
	}
	else if ((qty % 10 == 2 || qty % 10 == 3 || qty % 10 == 4) && 
			 !(qty == 12 || qty == 13 || qty == 14))
		if (n == "монета")
			return "монеты";
		else if (n == "доллар")
			return "доллара";
		else if (n == "цент")
			return "цента";
		else
			return n;
	else
		if (n == "монета")
			return "монет";
		else if (n == "доллар")
			return "долларов";
		else if (n == "цент")
			return "центов";
		else
			return n;
}

string adjective(string adj, int qty)
{
	if (qty % 10 == 1 && qty != 11) {
		return adj;
	}
	else
		if (adj == "центовая")
			return "центовых";
		else if (adj == "долларовая")
			return "долларовых";
		else
			return adj;
}

// string grammar_aware(int qty, string noun, string adj = "", string prefix = "")
// {
// 		return to_string(qty) + " " + 
// 			   (prefix == "" ? "" : prefix + '-') + 
// 			   (adj == "" ? "" : (grammar_aware_adjective(qty, adj) + " ")) + 
// 			   grammar_aware_noun(qty, noun);
// }