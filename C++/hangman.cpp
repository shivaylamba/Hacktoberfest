#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
using namespace std;

string Words_Array[100] = {"algorithm", "array", "bit", "binary", "boolean", "bug", "class", "code",
    "compiler", "condition", "const", "constructor", "database", "debug",
    "deque", "encapsulation", "exception", "expression", "float", "function",
    "hash", "inheritance", "input", "instance", "integer", "interface",
    "iteration", "java", "javascript", "kernel", "library", "linux", "linkedlist",
    "loop", "method", "module", "mutex", "namespace", "null", "object",
    "oop", "operator", "output", "overflow", "parameter", "pointer",
    "polymorphism", "private", "process", "program", "public", "python",
    "queue", "recursion", "reference", "register", "runtime", "scope",
    "search", "segment", "selection", "shell", "socket", "software",
    "sort", "stack", "statement", "string", "struct", "switch", "syntax",
    "system", "template", "thread", "token", "tree", "type", "typedef",
    "union", "unsigned", "variable", "vector", "virtual", "void", "volatile",
    "while", "windows", "xor", "yaml", "zend", "zip", "access", "agile",
    "backend", "binarytree", "bitwise", "blockchain", "cloud", "client",
    "server"};

bool check_char(char input,string word)
{
    bool ans = false;
    for(int i=0;i<word.length();i++)
    {
        if(word[i]==input)
        ans = true;
    }
    return ans;
}

void draw_hangman(int incorrect) {
    switch (incorrect) {
    case 0:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "__|__\n";
        break;

    case 1:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |   |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "__|__\n";
        break;

    case 2:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |   |\n";
        cout << "  |   O\n";
        cout << "  |\n";
        cout << "  |\n";
        cout << "__|__\n";
        break;

    case 3:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |   |\n";
        cout << "  |   O\n";
        cout << "  |   |\n";
        cout << "  |\n";
        cout << "__|__\n";
        break;

    case 4:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |   |\n";
        cout << "  |   O\n";
        cout << "  |  /|\n";
        cout << "  |\n";
        cout << "__|__\n";
        break;

    case 5:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |   |\n";
        cout << "  |   O\n";
        cout << "  |  /|\\\n";
        cout << "  |\n";
        cout << "__|__\n";
        break;

    case 6:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |   |\n";
        cout << "  |   O\n";
        cout << "  |  /|\\\n";
        cout << "  |  /\n";
        cout << "__|__\n";
        break;

    case 7:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |   |\n";
        cout << "  |   O\n";
        cout << "  |  /|\\\n";
        cout << "  |  / \\\n";
        cout << "__|__\n";
        break;

    case 8:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |   |\n";
        cout << "  |   O\n";
        cout << "  | _/|\\_\n";
        cout << "  |  / \\\n";
        cout << "__|__\n";
        break;

    case 9:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |   |\n";
        cout << "  |   O\n";
        cout << "  | _/|\\_\n";
        cout << "  | _/ \\_\n";
        cout << "__|__\n";
        break;

    case 10:
        cout << "\n";
        cout << "  _____\n";
        cout << "  |   |\n";
        cout << "  |   X\n";
        cout << "  | _/|\\_\n";
        cout << "  | _/ \\_\n";
        cout << "__|__\n";
        cout << "  | GAME OVER\n";
        break;
    }
}

int main()
{
   //string res;
    char input;
    int incorrect = 0;
    bool won = false;
    bool lost = false;

    srand(time(0));  
    
    cout<<"\nWELCOME TO HANGMAN!!!!!"<<endl;
    cout<<"Enter 'Q' to continue : "<<endl;
    char choice;
    cin>>choice;

    if(choice == 'Q' || choice == 'q')
    {
        cout<<endl;
        cout<<"WORD : ";

        int random = rand() % 100;
        string word = Words_Array[random];
        int len = word.length();

        //cout<<"The word is : "<<word<<endl;

        string res(len,'_');
        cout<<res;
        cout<<"\n";

        while(true)
        {
            cout<<"\nEnter a character : ";
            cin>>input;
            if(isalnum(input) == false)
            {
                cout<<"Wrong Input!";
                continue;
            }
            input = tolower(input);

            if(check_char(input,word) == true)
            {
                for(int i=0;i<len;i++)
                {
                    if(word[i] == input)
                    res[i] = input;
                }
            cout<<res<<endl;
            }
            else if(check_char(input,word) == false)
            {
                incorrect++;
                draw_hangman(incorrect);
                cout<<"No. of attempts left = "<<(10-incorrect)<<endl;
                cout<<res<<endl;
            }

            if(res == word)
            {
                won = true;
                break;
            }

            if(incorrect == 10)
            {
                lost = true;
                break;
            }
        }

        if(won)
        {
            cout<<"\n\nCONGRATULATIONS!!!!"<<endl;
        }
        if(lost)
        {
            cout<<"\n\nFAILURE!!!"<<endl;
            cout<<"The word is : "<<word<<endl;
        }
    }
    else
    {
        cout<<"Terminated!"<<endl;
        exit(0);
    }
    return 0;
}