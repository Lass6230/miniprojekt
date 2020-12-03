#include <iostream>
#include <ros/ros.h>

using namespace std;



int main(int argc, char const *argv[])
{
   cout << "hej :*" << '\n';
   string hej = "he :*";
   cin >> hej;
   if (hej == ":*" || hej == "hehe")
   {
       return 1;
   }
    return 0;
}
