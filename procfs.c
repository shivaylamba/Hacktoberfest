#include<iostream>
#include<string>
using namespace std;
int main(int argc ,char* argv[])
{
  int i;
  if (argc<2)
  {
    cout<<"\nInsufficient Arguments!!\n\n";
    cout<<"\n1.Print Kernel Version";
    cout<<"\n2.Print CPU info";
    cout<<"\n3.Print memory info";
    cout<<"\n\nExample: 'Progname 1/2/3' will display the kernel version, CPU info and memory info.";
    return -1;
  }
  for(i=1;i<argc;i++)
  {
   int ch= stoi(argv[i]);
   switch(ch)
   {
    case 1:
	    cout<<"\n\n*KERNEL VERSION*\n";
        system("cat /proc/version|awk '{print $1,$2,$3}'");
    break;
    case 2:
	    cout<<"\n*CPU INFO*\n";
        cout<<"\nCPU TYPE: \n";
        system("cat /proc/cpuinfo|awk 'NR==3'");// CPU family
        system("cat /proc/cpuinfo|awk 'NR==8'");// CPU MHz
        system("cat /proc/cpuinfo|awk 'NR==13'");//number of cores
        cout<<"\n\nCPU MODEL: \n";
        system("cat /proc/cpuinfo|awk 'NR==5'");
    break;
    case 3:
	    cout<<"\n*MEMORY INFO*\n";
        cout<<"\nCONFIGURED MEMORY: \n";
        system("cat /proc/meminfo|awk 'NR==1'| awk '{print $2,$3}'");
        cout<<"\nFREE MEMORY:\n";
        system("cat /proc/meminfo|awk 'NR==2'| awk '{print $2,$3}'");
    break;
    default:cout<<"\n*INVALID OPTION!!!*";
   }
  }
  return -1;
}

