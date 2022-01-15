#include <iostream>
#include <vector>
#include <string>

using namespace std;

class person
{
public:

private:
int id_sys;
int id_per;

};

class casebase
{
public:

private:

};

int main()
{
   vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

   for (const string& word : msg)
   {
      cout << word << " ";
   }
   cout << endl;
}
