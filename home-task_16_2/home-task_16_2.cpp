#include <iostream>

using namespace std;

//Есть некоторый текст.Используя стандартные
//строковые функции из библиотеки языка C :
//■ Найдите и замените вхождение некоторого слова на
// пользователем слово.
void Replace_Word(char* str, char* word, char* word1) {
	int n = 0;
	char* p = str;
	while (p = strstr(p, word))
	{
		n++;
		p += strlen(word);
	}
	int length = strlen(str) - n * strlen(word) + n * strlen(word1) + 1;
	char* res_str = new char[length] {};

	char* p2 = str;
	while (p = strstr(p2, word)) {
		strncat_s(res_str, length, p2, strlen(p2) - strlen(p));
		strcat_s(res_str, length, word1);
		p2 = p + strlen(word);
	}
	if (strlen(p2) > 0) strcat_s(res_str, length, p2);
	puts(res_str);
}
//■ Изменить текст таким образом, чтобы каждое предложение начиналось с большой буквы.
void Upper_Case(char* str)
{
	if (str[0] > 'а' && str[0] < 'я')
	{
		str[0] = (char)((int)str[0] - 32);
	}

	for (int i = 2; str[i] != '\0'; i++)
	{
		if (str[i - 2] == '.' && str[i] > 'а' && str[i] < 'я')
		{
			str[i] = (char)((int)str[i] - 32);
		}
	}
	cout << str << endl;
}
//■ Посчитайте сколько раз каждая буква встречается в тексте.
void Count_All_Letter(char* str)
{
	int count = 0;
	int newLine = 1;
	for (int i = int('А'); i != int('я') + 1; i++, count = 0, newLine++) {
		for (int j = 0; str[j] != '\0'; j++) {
			if (str[j] == (char)i) {
				count++;
			}
		}
		cout << (char)i << " = " << count << "\t";
		if (i == int('\0')) {
			i = int('а') - 1;
		}
		if (newLine % 7 == 0) {
			cout << endl;
		}
	}
	cout << endl;
}
//■ Посчитайте сколько раз цифры встречаются в тексте.
void Count_Numbers(char* str) {
	int alpha = 0, digit = 0, other = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (isdigit(str[i]))digit++;
	}
	cout << digit;
}

int main()
{
	setlocale(LC_ALL, "");
	char* str = new char[100] { "в мешке для фруктов лежало 50 яблок, положили ещё 30 яблок. убрали 20 яблок. сколько осталось?" };
	char* word1 = new char[10] { "яблок" };
	char* word2 = new char[10] { "груш" };

	Replace_Word(str, word1, word2);
	Upper_Case(str); 
	Count_All_Letter(str);
	Count_Numbers(str);
}