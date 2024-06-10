// HEADERS ---------------------------------------------------------------------
#include <string.h>

#include <fstream>
#include <iostream>

using namespace std;

// STRUTTURE DATI --------------------------------------------------------------
struct Record {
  char* name;
  int grade;
};

struct RecordSet {
  Record* records;
  int size;
};

// FUNZIONI --------------------------------------------------------------------

RecordSet init(int size) { 
  if (size == 0) return {nullptr, 0};
  RecordSet rs;
  rs.size = size;
  rs.records = new Record[size];
  for(int i = 0; i < rs.size; i++) {
    rs.records[i].name = nullptr;
    rs.records[i].grade = 0;
  }
  return rs;
}

void drop(RecordSet& rs) {
  delete[] rs.records;
  rs.size = 0;
}

int insert(RecordSet& rs, const char* name, int grade) { 
  for(int i = 0; i < rs.size; i++) {
    if(rs.records[i].name == nullptr) {
      rs.records[i].name = new char[strlen(name)];
      strcpy(rs.records[i].name, name);
      rs.records[i].grade = grade;
      return i;
    }
  }
  return -1;
}

int search(const RecordSet& rs, const char* name) { 
  for(int i = 0; i < rs.size; i++) {
    if(rs.records[i].name == nullptr) continue;
    if(strcmp(rs.records[i].name, name) == 0) return i; 
  }

  return -1;
}

int update(RecordSet& rs, const char* name, int grade) { 
  int pos = search(rs, name);
  if(pos == -1) return -1;
  rs.records[pos].grade = grade;
  return pos;
}

int remove(RecordSet& rs, const char* name) { 
  int pos = search(rs, name);

  if(pos == -1) return -1;

  delete[] rs.records[pos].name;
  rs.records[pos].name = nullptr;
  rs.records[pos].grade = -2;

  return pos;
}

RecordSet load(const char* filename) { 
  ifstream file(filename);
  if(!file) return {nullptr, 0};
  int iSize;
  file >> iSize;
  RecordSet rs = init(iSize);
  char buf[256];
  int grade;
  for(int i = 0; i < rs.size; i++) {
    file >> buf >> grade;
    if(strcmp(buf, "CANCELLATO") == 0) {
      rs.records[i].name = 0;
      rs.records[i].grade = -2;
    } else {
      rs.records[i].name = new char[strlen(buf) + 1];
      strcpy(rs.records[i].name, buf);
      rs.records[i].grade = grade;
    }
  }
  return rs;
}

int save(const RecordSet& rs, const char* filename) { 
  ofstream file(filename);

  if(!file) return -1;

  file << rs.size << endl;
  for(int i = 0; i < rs.size; i++) {

    if(rs.records[i].name == nullptr) {
      file << "CANCELLATO " << rs.records[i].grade << endl;
    } else {
      file << rs.records[i].name << " " << rs.records[i].grade << endl;
    }

  }

  return 0;
}

#ifndef __TESTS__

int main() {
  // da usare per i vostri tests
  return 0;
}

#endif
