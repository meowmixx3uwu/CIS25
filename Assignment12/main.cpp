#include "Datasets.h"

int main(){ //main
ReadCSV readCSV("LoL_champion_data.csv");
readCSV.readFromFile();
return 0;
}