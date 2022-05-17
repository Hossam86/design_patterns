#include <iostream>
// Scenario

struct BankAccount {
    int balance = 0;
    int overDraft_limit = -500;

    void deposit(int amount) {
        balance += amount;
        std::cout << " amount deposited in to account " << amount << "  and the balance now is " << balance
                  << std::endl;

    }

    void withdraw(int amount) {
        if ((balance - amount) >= overDraft_limit) {
            balance -= amount;
            std::cout << "amount withdrawn from the account is" << amount << " and the balance now is " << balance
                      << std::endl;
        } else {
            std::cout << " not enough balance " << std::endl;
        }
    }
};

// Now we can call the member functions directly, of course, but let us suppose that, for audit purposes,
// we need to make a record of every deposit and withdrawal made and we cannot do it right inside BankAccount.

// here is how?
// define an interface
struct Command {
    virtual void call() const = 0;
};

// Having made the interface, we can now use it to define a BankAccountCommand that will encapsulate information
// about what to do with a bank account:

struct BankAccountCommand : Command {
    BankAccount &account;
    enum Action {
        DEPOSIT, WITHDRAW
    } action;

    int amount;

    BankAccountCommand(BankAccount &account, Action action, int amount) : account(account), action(action),
                                                                          amount(amount) {}

    void call() const override {
        switch (action) {
            case DEPOSIT:
                account.deposit(amount);
                break;
            case WITHDRAW:
                account.withdraw(amount);
                break;
        }

    }
};

//With this approach, we can create the command and then perform modifications of the account right on the command

int main() {
    BankAccount ba;
    BankAccountCommand cmd{ba, BankAccountCommand::DEPOSIT, 500};
    cmd.call();
}