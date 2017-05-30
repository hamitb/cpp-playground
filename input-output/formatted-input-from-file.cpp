#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

/*void getTrainerCount(string line) {
  string delim = "Trainer Count:";

  int start = delim.length();
  int end = line.length();
  
  cout << line.substr(start,end) << endl;
}*/
class Pokemon {
public:
  Pokemon(int id, const string& name, string type)
    : id(id), name(name), type(type) {}
  
  void Info() {
    cout << "[" << id << ", " << name << ", " << type << "]" << endl;
  }
  int id;
  string name;
  string type;
};

class Trainer {
public:
  Trainer(int id, string name, string favArea, vector<Pokemon *> pokemons)
    : id(id), name(name), favArea(favArea), pokemons(pokemons) {}
  void Info() {
    cout << "**" << id << ", " << name << ", " << favArea << "**" << endl;
    for(int i = 0; i < pokemons.size(); i ++) {
      pokemons[i]->Info();
    }
  }
  int id;
  string name;
  string favArea;
  vector<Pokemon *> pokemons;
};

int parsePokemonCount(string line) {
  int result;
  char * cstr = new char [line.length()+1];

  strcpy(cstr, line.c_str());

  sscanf(cstr, "Pokemon Count:%d", &result);

  delete[] cstr;

  return result;
}

Trainer* parseTrainer(string line, vector<Pokemon *> pokemons) {
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
  trainer = new Trainer(id, name, favArea, pokemons);

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
  pokemon = new Pokemon(id, name, type);

  delete[] cstr;

  return pokemon;
}

int parseTrainerCount(string line) {
  int result;
  int some = 2;

  switch(some){
    case 1:
      cout << "some1" << endl;
      break;
    case 0:
      cout << "some0" << endl;
      break;
  }
  char * cstr = new char [line.length()+1];

  strcpy(cstr, line.c_str());

  sscanf(cstr, "Trainer Count:%d", &result);

  delete[] cstr;
  
  return result;
}

int main() {
  string fileLocation = "2Trainers.txt";
  string line;
  vector<Trainer *> trainers;

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
    string tstring;
    string pstring;
    vector<Pokemon *> pokemons;
    getline(sampleFile, tstring);
    
    for(int j = 0; j < pokemonCount; j++) {
      getline(sampleFile, pstring);
      Pokemon* pokemon = parsePokemon(pstring);
      pokemons.push_back(pokemon);
    }

    Trainer* trainer = parseTrainer(tstring, pokemons);
    trainers.push_back(trainer);
    getline(sampleFile, line);    
  }

  for(int i = 0; i < trainers.size(); i++) {
    if(trainers[i]->id == 0){
      trainers[i]->Info();
      break;
    }
  }
  return 0;
}
