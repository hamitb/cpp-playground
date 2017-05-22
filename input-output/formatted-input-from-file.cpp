#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

/*void getTrainerCount(string line) {
  string delim = "Trainer Count:";

  int start = delim.length();
  int end = line.length();
  
  cout << line.substr(start,end) << endl;
}*/
class Pokemon {
public:
  Pokemon(int id, string name, string type)
    : id(id), name(name), type(type) {}

  int id;
  string name;
  string type;
};

class Trainer {
public:
  Trainer(int id, string name, string favArea)
    : id(id), name(name), favArea(favArea) {}
  
  int id;
  string name;
  string favArea;
};


int parsePokemonCount(string line) {
  int result;
  char * cstr = new char [line.length()+1];

  strcpy(cstr, line.c_str());

  sscanf(cstr, "Pokemon Count:%d", &result);

  delete[] cstr;

  return result;
}

Trainer* parseTrainer(string line) {
  Trainer* trainer;
  char * cstr = new char [line.length()];
  int id;
  char name[100];
  char favArea[100];
  string find = "--";
  string replace = " ";

  for(string::size_type i = 0; (i = line.find(find, i)) != string::npos;){
        line.replace(i, find.length(), replace);
        i += replace.length();
  }

  strcpy(cstr, line.c_str());

  sscanf(cstr, "%d %s %s", &id, name, favArea);
  cout << id << ", " << name << ", " << favArea << endl;
  trainer = new Trainer(id, name, favArea);

  delete[] cstr;

  return trainer;

}

Pokemon* parsePokemon(string line) {
  Pokemon* pokemon;
  char * cstr = new char [line.length()];
  int id;
  char name[100];
  char type[100];
  string find = "::";
  string replace = " ";

  for(string::size_type i = 0; (i = line.find(find, i)) != string::npos;){
        line.replace(i, find.length(), replace);
        i += replace.length();
  }

  strcpy(cstr, line.c_str());

  sscanf(cstr, "%d %s %s", &id, name, type);
  cout << id << ", " << name << ", " << type << endl;
  pokemon = new Pokemon(id, name, type);

  delete[] cstr;

  return pokemon;
}

int parseTrainerCount(string line) {
  int result;
  char * cstr = new char [line.length()+1];

  strcpy(cstr, line.c_str());

  sscanf(cstr, "Trainer Count:%d", &result);

  delete[] cstr;
  
  return result;
}

int main() {
  string fileLocation = "2Trainers.txt";
  string line;

  int trainerCount;
  int pokemonCount;

  ifstream sampleFile;

  sampleFile.open(fileLocation);

  getline(sampleFile, line);
  trainerCount = parseTrainerCount(line);

  getline(sampleFile, line);
  pokemonCount = parsePokemonCount(line);

  getline(sampleFile, line);

  for(int i = 0; i < trainerCount; i++) {
    getline(sampleFile, line);
    Trainer* trainer = parseTrainer(line);
    
    for(int j = 0; j < pokemonCount; j++) {
      getline(sampleFile, line);
      Pokemon* pokemon = parsePokemon(line);
    }

    getline(sampleFile, line);    
  }

  return 0;

}
