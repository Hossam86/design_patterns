#include <iostream>
// Scenario
// imagine u want at add support for undo operation
struct BankAccount {
    int balance = 0;
    int overDraft_limit = -500;

    void deposit(int amount) {
        balance += amount;
        std::cout << " amount deposited in to account " << amount << "  and the balance now is " << balance
                  << std::endl;

    }

//   return changed to bool to save a record for successful withdraw operation
    bool withdraw(int amount) {
        if ((balance - amount) >= overDraft_limit) {
            balance -= amount;
            std::cout << "amount withdrawn from the account is" << amount << " and the balance now is " << balance
                      << std::endl;
            return true;
        } else {
            std::cout << " not enough balance " << std::endl;
            return false;
        }
    }
};

struct Command {
    virtual void call() = 0;

    virtual void undo() = 0;
};

struct BankAccountCommand : Command {
    BankAccount &account;
    enum Action {
        DEPOSIT, WITHDRAW
    } action;

    int amount;
    // log
    bool withdrawSuccecded;

    BankAccountCommand(BankAccount &account, Action action, int amount) : account(account), action(action),
                                                                          amount(amount) {}

    void call() override {
        switch (action) {
            case DEPOSIT:
                account.deposit(amount);
                break;
            case WITHDRAW:
                withdrawSuccecded = account.withdraw(amount);
                break;

        }
    }

    void undo() override {
        switch (action) {
            case WITHDRAW:
                if (withdrawSuccecded)
                    account.withdraw(amount);

        }

    }
};

