#include "KnapsackSolver.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

// Constructor: creates the solver and prepares vectors used during the search
KnapsackSolver::KnapsackSolver(std::vector<Item> items, int capacity)
    : items(std::move(items)),
      capacity(capacity),
      bestProfit(0),
      bestWeight(0),
      currentChoice(this->items.size(), 0),
      bestChoice(this->items.size(), 0),
      nodeCounter(0)
{}


void KnapsackSolver::writeSeparator(){
    output << "------------------------------------------------------------" << std::endl;
}


void KnapsackSolver::sortItemsByRatio(){
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b){
        return a.ratio() > b.ratio();
    });
}


double KnapsackSolver::calculateBound(int level, int currentProfit, int currentWeight) const{
    if(currentWeight >= capacity) return currentProfit;
    
    double bound = currentProfit;
    int totalWeight = currentWeight;

    for(int i = level; i < items.size(); i++){
        if(totalWeight + items[i].weight <= capacity){
            totalWeight += items[i].weight;
            bound += items[i].profit;
        }
        else{
            int freeCapacity = capacity - totalWeight;
            bound += freeCapacity * items[i].ratio();
            break;
        }
    }
    return bound;
}


bool KnapsackSolver::isPromising(int currentWeight, double bound) const{
    return currentWeight < capacity && bound > bestProfit;
}


void KnapsackSolver::updateBestSolution(int currentProfit, int currentWeight){
    if(currentWeight <= capacity && currentProfit > bestProfit){
        bestProfit = currentProfit;
        bestWeight = currentWeight;
        bestChoice = currentChoice;

        output << "Nowe najlepsze rozwiazanie: bestProfit = " << bestProfit
               << ", bestWeight = " << bestWeight << std::endl;
    }
}


void KnapsackSolver::writeFinalResult(){
    writeSeparator();
    output << "WYNIK KONCOWY" << std::endl;
    output << "Maksymalny zysk: " << bestProfit << std::endl;
    output << "Waga wybranych przedmiotow: " << bestWeight << std::endl;
    output << "Wybrane przedmioty: " << choiceToText(bestChoice) << std::endl;
    output << "Pozostala pojemnosc: " << capacity - bestWeight << std::endl;
    writeSeparator();
}


std::string KnapsackSolver::choiceToText(const std::vector<int>& choice) const{
    std::ostringstream text;
    bool anyItemSelected = false;
    text << "{";
    for(int i = 0; i < static_cast<int>(choice.size()); i++){
        if(choice[i] == 1){
            if(anyItemSelected){
                text << ", ";
            }
            text << items[i].id;
            anyItemSelected = true;
        }
    }
    if(!anyItemSelected){
        text << "brak";
    }
    text << "}";
    return text.str();
}

                               
void KnapsackSolver::backtrack(int level, int currentProfit, int currentWeight){
    ++nodeCounter;

    output << "Wezel " << nodeCounter << " | poziom = " << level
           << " | profit = " << currentProfit
           << " | weight = " << currentWeight << std::endl;

    output << "Wybrane przedmioty: " << choiceToText(currentChoice) << std::endl;

    updateBestSolution(currentProfit, currentWeight);

    if(level == items.size()){
        output << "Osiagnieto lisc drzewa - nie ma wiecej przedmiotow do sprawdzenia" << std::endl;
        writeSeparator();
        return;
    }
    double bound = calculateBound(level, currentProfit, currentWeight);
    output << "Granica (bound) = " << std::fixed << std::setprecision(2) << bound << std::endl;

    if(!isPromising(currentWeight, bound)){
        if(currentWeight >= capacity){
            output << "Wezel nieobiecujacy: waga osiagnela lub przekroczyla pojemnosc plecaka." << std::endl;
        }
        else{
            output << "Wezel nieobiecujacy: bound <= bestProfit ("
                   << bound << " <= " << bestProfit << ")." << std::endl;
        }
        writeSeparator();
        return;
    }

    const Item& nextItem = items[level];

    output << "Decyzja 1: dodajemy przedmiot " << nextItem.id
           << " (p = " << nextItem.profit << ", w = " << nextItem.weight << ")." << std::endl;

    currentChoice[level] = 1;
    backtrack(level + 1,
              currentProfit + nextItem.profit,
              currentWeight + nextItem.weight);

    output << "Decyzja 2: Nie dodajemy przedmiotu " << nextItem.id << "." << std::endl;
    currentChoice[level] = 0;
    backtrack(level + 1, currentProfit, currentWeight);
}


void KnapsackSolver::solve(const std::string& outputFileName){
    output.open(outputFileName);

    if(!output.is_open()){
        std::cerr << "Cannot open output file: " << outputFileName << std::endl;
        return;
    }
    sortItemsByRatio();

    output << "PROGRAM - Problem plecakowy 0/1" << std::endl;
    output << "Metoda: algorytm z powrotami + ograniczenie (branch and bound)" << std::endl;
    output << "Pojemnosc plecaka W = " << capacity << std::endl << std::endl;

    output << "Przedmioty po uporzadkowaniu wedlug p/w malejaco:" << std::endl;
    output << "id\tp\tw\tp/w" << std::endl;
    for(const Item& item : items){
        output << item.id << "\t" << item.profit << "\t" << item.weight << "\t"
               << std::fixed << std::setprecision(2) << item.ratio() << std::endl;
    }

    writeSeparator();
    output << "Start: profit = 0, weight = 0, bestProfit = 0" << std::endl;
    writeSeparator();

    backtrack(0, 0, 0);
    writeFinalResult();

    output.close();
}







