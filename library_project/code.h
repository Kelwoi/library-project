#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int SIZE = 50;

enum Type {
	BOOK = 1, MAGAZINE, NEWSPAPER
};

struct Source {
	Type type;
	char name[SIZE]{};
	char author[SIZE]{};
	char genre[SIZE]{};
	int year;
};
void fillDB();
void editSource(Source& source);
void save(Source source, string fname = "data.dat");
Source* read(int& size, string fname = "data.dat");
void clear(Source*& sources, int& size);
void printAll(Source* sources, const int& size, bool numeric = false);
void print(Source source, int index = -1);
void remove_(Source* sources, const size_t& size, const int& id, string fname = "data.dat");
void swap(Source& a, Source& b);
void sortBooks(Source* sources, int size, int choice);
void count_of(Source* sources, int size);
void find(Source* source, int size, string name, string author);