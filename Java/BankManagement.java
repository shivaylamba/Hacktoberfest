import java.util.Scanner;
class Account{
    String name;
    double accNo;
    String type;
    double balance;

    Account(String name, double accNo, String type, double balance){
        this.name = name;
        this.accNo = accNo;
        this.type = type;
        this.balance = balance;
    }

    void deposit(double amount){
        balance += amount;
        System.out.println("Deposited amount: " + amount);
    }

    void displayBal(){
        System.out.println("Balance present: " + balance);
    }

    void withdraw(double amount){
        if(balance >= amount){
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        }
        else{
            System.out.println("Insufficient balance!")
        }
    }
}
class SavingAccount extends Account{
    SavingAccount(String name, int accNo, double balance) {
        super(name, accNo, "Savings", balance);
    }
    void compInterest(double rate, int time, int n){
        double interest = balance * Math.pow((1 + rate / n), n * time) - balance;
        balance += interest;
        System.out.println("Interest added: " + interest);
    }

    @Override
    void withdraw(double amount){
        if (balance >= amount) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
        } else {
            System.out.println("Insufficient balance!");
        }
    }
}
class CurrentAccount extends Account{
    double min_balance = 1000;
    double penalty = 200;
    CurrentAccount(String name, int accNo, double balance) {
        super(name, accNo, "Current", balance);
    }
    @Override
    void withdraw(double amount){
        if (balance >= amount){
            balance -= amount;
            System.out.println("Withdrawn: " + amount);
            if (balance < min_balance){
                balance -= penalty;
                System.out.println("Penalty imposed: " + penalty);
            }
        } else {
            System.out.println("Insufficient balance!");
        }
    }

}

public class BankManagement {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        SavingAccount sav = new SavingAccount("Ishika", 12345, 5000);
        CurrentAccount curr = new CurrentAccount("Ishika", 12345, 2000);

        while (true) {
            System.out.println("\n--- BANK MENU ---");
            System.out.println("1. Deposit (Savings)");
            System.out.println("2. Withdraw (Savings)");
            System.out.println("3. Compute Interest (Savings)");
            System.out.println("4. Display Balance (Savings)");
            System.out.println("5. Deposit (Current)");
            System.out.println("6. Withdraw (Current)");
            System.out.println("7. Display Balance (Current)");
            System.out.println("8. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter amount: ");
                    sav.deposit(sc.nextDouble());
                    break;

                case 2:
                    System.out.print("Enter amount: ");
                    sav.withdraw(sc.nextDouble());
                    break;

                case 3:
                    System.out.print("Enter rate (e.g., 0.05 for 5%): ");
                    double rate = sc.nextDouble();
                    System.out.print("Enter time in years: ");
                    int time = sc.nextInt();
                    System.out.print("Enter compounding frequency (n): ");
                    int n = sc.nextInt();
                    sav.compInterest(rate, time, n);
                    break;

                case 4:
                    sav.displayBal();
                    break;

                case 5:
                    System.out.print("Enter amount: ");
                    curr.deposit(sc.nextDouble());
                    break;

                case 6:
                    System.out.print("Enter amount: ");
                    curr.withdraw(sc.nextDouble());
                    break;

                case 7:
                    curr.displayBal();
                    break;

                case 8:
                    System.out.println("Thank you for using the bank system!");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice! Try again.");
            }
        }
    }
}
