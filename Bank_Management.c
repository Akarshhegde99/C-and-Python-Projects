#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

struct BankAccount {
    int accountNumber;
    char accountHolderName[50];
    double balance;
};

struct BankAccount createAccount(int accountNumber, const char* accountHolderName, double initialBalance);
int findAccountIndex(struct BankAccount accounts[], int numAccounts, int accountNumber);
void deposit(struct BankAccount accounts[], int numAccounts, int accountNumber, double amount);
void withdraw(struct BankAccount accounts[], int numAccounts, int accountNumber, double amount);
void displayAccountInfo(struct BankAccount accounts[], int numAccounts, int accountNumber);

struct Transaction {
    int accountNumber;
    char type; // 'C' for credit, 'D' for debit
    double amount;
    time_t timestamp;
};

int displayMainMenu();

int main() {
    
    int choice;
    float balance = 0.0;
    struct Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = 0;
    
    do {
        printf("\nMain Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit Funds\n");
        printf("3. Withdraw Funds\n");
        printf("4. Check Balance\n");
        printf("5. View Transaction History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Account created successfully!\n");
                break;
            case 2: {
                float amount;
                printf("Enter the amount to deposit: ");
                scanf("%f", &amount);
                balance += amount;
                transactions[numTransactions].type = 'D';
                transactions[numTransactions].amount = amount;
                numTransactions++;
                printf("Deposit successful!\n");
                break;
            }
            case 3: {
                float amount;
                printf("Enter the amount to withdraw: ");
                scanf("%f", &amount);
                if (amount <= balance) {
                    balance -= amount;
                    transactions[numTransactions].type = 'W';
                    transactions[numTransactions].amount = amount;
                    numTransactions++;
                    printf("Withdrawal successful!\n");
                } else {
                    printf("Insufficient funds!\n");
                }
                break;
            }
            case 4:
                printf("Your current balance: Rs %.2f\n", balance);
                break;
            case 5:
                printf("Viewing transaction history:\n");
                for (int i = 0; i < numTransactions; i++) {
                    printf("Transaction %d: %c %.2f\n", i + 1, transactions[i].type, transactions[i].amount);
                }
                break;
            case 6:
                printf("\n (: THANK YOU VISIT OUR BANK ONCE AGAIN :) \n\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 6);


    return 0;
}

int displayMainMenu() {
    int choice;
    printf("Main Menu:\n");
    printf("1. Create Account\n");
    printf("2. Deposit Funds\n");
    printf("3. Withdraw Funds\n");
    printf("4. Check Balance\n");
    printf("5. View Transaction History\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Implement the rest of the functions as per your requirements
