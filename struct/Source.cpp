#define _CRT_SECURE_NO_WARNINGS
#include <iostream>;
#include <stdio.h>;
struct Book
{
	long id;
	char name[255];
	char author[255];
	char publishHouse[255];
	int pageNum;
	char genre[100];
	float price;

	void toString() {
		printf("Book: %d,%s, %s, %s, %d,%s, %.2f\n", id, name, author, publishHouse, pageNum, genre, price);
	}

};

bool sortBooks(Book* books, int size, const char* option);
void printBooks(Book* books, int size);

int main() {
	Book books[] = {
				   { 1, "Metro2033",                        "Dmitry Glykhovsky",   "Rainbow",   350,  "Sci-fi",    125.50 },
				   { 2, "The Da - Vinci Code",              "Den Brown",           "Sunshine",  450,  "Detective",  200.00    },
				   { 3, "Sherlock Holmse",                  "Arthur Conan Doyle",  "twilling",  189,  "Detective",  350.50 },
				   { 4, "Harry Potter and Death Hellows",   "J.K.Rowling",         "Moonlight", 500,  "Fantasy",    415.75 },
	};
	printf("Books before sorting: \n");
	printBooks(books, 4);
	printf("Pleas, input sort options (name,  page or price): ");
	char* sortOption = new char[20];
	scanf("%s", sortOption);
	if (sortBooks(books, 4, sortOption) == true) {
		printf("Books after sorting \n");
	printBooks(books, 4);
 }
}

bool sortBooks(Book* books, int size, const char* option)
{
	if (strcmp(option, "name") == 0) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (strcmp(books[j].name, books[j + 1].name) > 0) {
					std::swap(books[j], books[j + 1]);
				}
			}
		}
		return true;
	}

	else if (strcmp(option, "pages") == 0) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (books[j].pageNum > books[j +
					1].pageNum) {
					std::swap(books[j], books[j + 1]);
				}
			}
		}
		return true;
	}

	else if (strcmp(option, "price") == 0) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - 1; j++) {
				if (books[j].price > books[j + 1].price) {
					std::swap(books[j], books[j + 1]);
				}
			}
		}
		return true;
  }
	else {
		printf("Unknown sort option!!!");
		return false;
	
	}
}

	void printBooks(Book * books, int size)
	{
		for (int i = 0; i < size; i++) {
			books[i].toString();
		}
	}

