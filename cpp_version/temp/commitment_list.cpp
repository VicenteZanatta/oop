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

void CommitmentList::printList() const {
    std::cout << "=== COMMITMENTS LIST ===" << std::endl;
    commitmentList.printList([](Commitment* commitment) {
        commitment->printDefenition();
    });
    std::cout << "========================" << std::endl;
}

Commitment* CommitmentList::findCommitmentById(const std::string& id) const {
    auto current = commitmentList.getHead();
    while (current) {
        if (current->data->getId() == id) {
            return current->data;
        }
        current = current->getNext();
    }
    return nullptr;
}

bool CommitmentList::isEmpty() const {
    return commitmentList.isEmpty();
}

void CommitmentList::clear() {
    commitmentList.clearWithData();
}

void CommitmentList::clearWithoutData() {
    commitmentList.clear();
}