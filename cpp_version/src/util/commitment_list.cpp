#include <iostream>
#include <fstream>
#include "util/commitment_list.hpp"

CommitmentList::CommitmentList() = default;

CommitmentList::~CommitmentList() = default;

void CommitmentList::addCommitment(Commitment* commitment) {
    commitmentList.addNode(commitment);
}

void CommitmentList::removeCommitment(Commitment* commitment) {
    auto current = commitmentList.getHead();
    while (current) {
        if (current->data == commitment) {
            commitmentList.removeNode(current);
            return;
        }
        current = current->getNext();
    }
}

void CommitmentList::printCommitmentList(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return;
    }
    
    if (commitmentList.isEmpty()) {
        file.close();
        return;
    }
    
    LinkedListTemplate<Commitment>::Node* current = commitmentList.getHead();
    while (current) {
        Commitment* commitment = current->data;
        
        file << commitment->getDayInt() << "/" << commitment->getMonthInt() << "/" << commitment->getYearInt();
        file << " " << commitment->getStartHour() << ":" << commitment->getStartMinute() << std::endl;
        file << commitment->getId() << std::endl;
        file << commitment->getDescription() << std::endl;
        
        current = current->getNext();
    }
    
    file.close();
}

void CommitmentList::printConfirmedList(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return;
    }
    
    if (commitmentList.isEmpty()) {
        file.close();
        return;
    }
    
    LinkedListTemplate<Commitment>::Node* current = commitmentList.getHead();
    while (current) {
        Commitment* commitment = current->data;
        
        file << commitment->getId() << ": " << commitment->getDescription() << std::endl;
        file << "Início: " << commitment->getDayInt() << "/" << commitment->getMonthInt() << "/" << commitment->getYearInt();
        file << " " << commitment->getStartHour() << ":" << commitment->getStartMinute() << std::endl;
        file << "Fim: " << commitment->getDayInt() << "/" << commitment->getMonthInt() << "/" << commitment->getYearInt();
        file << " " << commitment->getFinishHour() << ":" << commitment->getFinishMinute() << std::endl;
        file << "Prioridade: " << commitment->getPriority() << std::endl;
        
        current = current->getNext();
    }
    
    file.close();
}

void CommitmentList::clear() {
    commitmentList.clearWithData();
}

void CommitmentList::clearWithoutData() {
    commitmentList.clear();
}