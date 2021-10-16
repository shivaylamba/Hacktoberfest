#include <map>
#include <iostream>
#include <string>

struct Student
{
    std::string name;
    std::string surname;
    float average_grade;
} student;

void print_menu()
{
    std::cout << "\t1. Enter a new student\n";
    std::cout << "\t2. Delete a student\n";
    std::cout << "\t3. Print all students\n";
    std::cout << "\t4. Lookup a student\n";
    std::cout << "\t5. Exit\n\n";
}

short get_option(short max_option_number)
{
    short option;
    do
    {
        std::cout << "Enter your selected option: ";
        std::cin >> option;
        if (option < 1 || option > max_option_number)
        {
            std::cout << "\nYou entered an invalid option! Please try again.\n";
        }
    } while (option < 1 || option > max_option_number);

    return option;
}

int main()
{
    std::map<int, Student> student_database;
    int index_number;

    bool is_running = true;
    std::cout << "Welcome to my student management application!\n\n";
    while (is_running)
    {
        print_menu();
        switch (get_option(5))
        {
        case 1:
            std::cout << "Enter the student's index number: ";
            std::cin >> index_number;
            if (student_database.count(index_number) == 0)
            {
                std::cout << "Enter the student's name: ";
                std::cin >> student.name;
                std::cout << "Enter the student's surname: ";
                std::cin >> student.surname;
                std::cout << "Enter the student's average grade: ";
                std::cin >> student.average_grade;

                const auto [iterator, successfully_inserted] = student_database.insert(std::pair(index_number, student));

                std::cout << (successfully_inserted ? "\nStudent successfully inserted!\n" : "\nThere was an error while inserting the student!\n");
            }
            else
            {
                std::cout << "\nThere is no student with the entered index number in the database!\n";
            }
            break;

        case 2:
            std::cout << "Enter the student's index number: ";
            std::cin >> index_number;
            if (student_database.count(index_number) == 0)
            {
                std::cout << "\nThere is no student with the specified index number inside the database!\n\n";
            }
            else
            {
                std::cout << "Index number: " << index_number << std::endl;
                std::cout << "Student name: " << student_database.at(index_number).name << std::endl;
                std::cout << "Student surname: " << student_database.at(index_number).surname << std::endl;
                std::cout << "Student average grade: " << student_database.at(index_number).average_grade << std::endl;
                std::cout << "Are you sure you want to delete this user? (1. Yes / 2. No)\n";

                if (get_option(2) == 1)
                {
                    bool successfully_deleted = student_database.erase(index_number);
                    std::cout << (successfully_deleted ? "\nStudent successfully deleted!\n" : "\nThere was an error while deleting the student!\n");
                }
            }
            break;

        case 3:
            if (student_database.empty())
                std::cout << "\nThere are no users inside the database!\n\n";

            for (const auto &[index_number, student] : student_database)
            {
                std::cout << "Index number: " << index_number << std::endl;
                std::cout << "Student name: " << student.name << std::endl;
                std::cout << "Student surname: " << student.surname << std::endl;
                std::cout << "Student average grade: " << student.average_grade << std::endl
                          << std::endl;
            }
            break;

        case 4:
            std::cout << "\t1. Search by index number\n";
            std::cout << "\t2. Search by full name\n";
            if (get_option(2) == 1)
            {
                std::cout << "Enter the student's index number: ";
                std::cin >> index_number;
                const auto &student = student_database.find(index_number);
                if (student == student_database.end())
                {
                    std::cout << "\nThere is no student with the specified index number inside the database!\n\n";
                }
                else
                {
                    std::cout << "Student's full name: " << student->second.name + " " + student->second.surname << std::endl;
                    std::cout << "Student average grade: " << student->second.average_grade << std::endl
                              << std::endl;
                }
            }
            else
            {
                bool found = false;
                std::cout << "Enter the student's full name: ";
                std::cin >> student.name >> student.surname;
                for (const auto &[index_number, other] : student_database)
                {
                    if (student.name == other.name && student.surname == other.surname)
                    {
                        std::cout << "Index number: " << index_number << std::endl;
                        std::cout << "Student average grade: " << other.average_grade << std::endl
                                  << std::endl;
                        found = true;
                    }
                }
                if (!found)
                {
                    std::cout << "\nThere is no student with the specified full name inside the database!\n\n";
                }
            }
            break;

        case 5:
            is_running = false;
            break;
        }
    }
}