#include <iostream>
using namespace std;
#include<fstream>
class BILL
{
    unsigned short int item_code,quantity;
    char item_name;
    float total,unit_price;
public:
    void getdata()
    {
        cout<<"\nEnter item code\n";
        cin>>item_code;
        cout<<"Enter item name\n";
        cin>>item_name;
        cout<<"\nQuantity\n";
        cin>>quantity;
        cout<<"\nUnit name\n";
        cin>>unit_price;
        total=unit_price*quantity;
    }
    void putdata()
    {
        cout<<item_code<<"\t\t"<<item_name<<"\t\t"<<quantity<<"\t\t"<<unit_price<<"\t\t"<<total;
    }
};
int main() 
{
    BILL b;
    fstream file;
    int s;
    do {
    cout<<"\nCHOOSE\n1.create\n2.display\n";
    cin>>s;
        switch (s)
        {
            case 1:
                file.open("MARKET.DAT",ios::binary|ios::out);
                int n;
                cout<<"\nhow many items purchased\n";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    cout<<"\nEnter details of item "<<endl;
                  b.getdata();
                    file.write((char*)&b,sizeof(b));
                }
                file.close();
                break;
            case 2:
                file.open("MARKET.DAT",ios::binary|ios::in);
                if(!file)
                {
                    cout<<"\nFILE DOESNT EXIST\n";
                }
                else
                {
                    cout<<endl;
                    cout<<"item_code"<<"\t\t"<<"item_name"<<"\t\t"<<"quantity"<<"\t\t"<<"unit_price"<<"\t\t"<<"total";
                    file.read((char*)&b,sizeof(b));
                    while(file)
                    {
                        b.putdata();
                        file.read((char*)&b,sizeof(b));
                    }
                
                }
                file.close();
                break;
            default:
                cout<<"\nEXITED\n";
                
        }
        } while (s<3);
    return 0;
}
