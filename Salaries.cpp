#include <bits/stdc++.h>
#include <iomanip>
#define endl '\n'

using namespace std;

const int Maxn=1005;

void printline (int t, char c)
{
    for(int i=0; i<t; i++)
    cout<<c;
    cout<<endl;
}



int main()
{
    cout<<"Name: Andrew Awni"<<endl;
    cout<<"Class: G1 / Sec(4)"<<endl;
    printline(47,'=');
    cout<<setw(37)<<"PRESS ENTER KEY TO START";
    string s;
    getline(cin,s);
    printline(47,'=');

    /*********************************** INPUT **************************************/

    retry:
    cout<<"Enter the data of 10 employees"<<endl;
    printline(47,'=');

    int information[1000][1000];                   // a 2D array holding the information of the ith employee
                                                  // information[i][0] -> num of hours // information[i][1] -> num of dependents
    for(int i=0; i<10; i++)
    {
        int num_hours,num_dependents;
        cout<<setw(27)<<"EMPLOYEE "<<i+1<<endl;
        cout<<setw(19);
        printline(11,'*');
        while(true)
        {
            cout<<"Enter the number of hours worked this week: ";
            cin>>num_hours;
            if(num_hours>=7*24 || num_hours<0)
              {
                cout<<"Invalid input! please try again"<<endl;
                continue;
              }

          break;
        }

        while(true)
        {
          cout<<"Enter the number of dependents: ";
          cin>>num_dependents;
          if(num_dependents<0)
          {
            cout<<"Invalid input! please try again"<<endl;
            continue;
          }

          break;

        }


        information[i][0]=num_hours;
        information[i][1]=num_dependents;
        printline(47,'-');

    }
    printline(47,'=');
    cout<<endl;

  /********************************************************************************************/


  /**************************************** CALCULATIONS **************************************/

    float gross_salary = 0, norm_rate = 16.78, ovrtime_rate = norm_rate*1.5;


    for(int i = 0; i<10; i++)
    {
        int num_hours = information[i][0];
        int num_dependents = information[i][1];

        if(num_hours>40)
        {
            int ovr_time = num_hours-40;
            gross_salary += 40*norm_rate;
            gross_salary += ovr_time*ovrtime_rate;

        }
        else
        {
            gross_salary += num_hours*norm_rate;
        }

        float social_security_tax=0.06*gross_salary;
        float federal_income_tax=0.14*gross_salary;
        float state_income_tax=0.05*gross_salary;
        float union_dues=10;
        float health_insurance;
          if(num_dependents>=3)
              health_insurance=35;
          else
              health_insurance=0;
     /**************************************************************************************************/


     /***************************************** OUTPUT *************************************************/

        cout<<setw(27)<<"EMPLOYEE "<<i+1<<endl;
        cout<<setw(19);
        printline(11,'*');
        cout<<"Withdraws: "<<endl;
        printline(47,'-');

        cout<<'\t'<< "Social security tax: "<<setw(8)<<'$'<<fixed<<setprecision(2)<<social_security_tax<<endl;
        cout<<'\t'<< "Federal income tax: "<<setw(9)<<'$'<<fixed<<setprecision(2)<<federal_income_tax<<endl;
        cout<<'\t'<< "State income tax: "<<setw(11)<<'$'<<fixed<<setprecision(2)<<state_income_tax<<endl;
        cout<<'\t'<< "Union dues: "<<setw(17)<<'$'<<fixed<<setprecision(2)<<union_dues<<endl;
        cout<<'\t'<< "Health insurance: "<<setw(11)<<'$'<<health_insurance<<endl;

        printline(47,'-');

        float withdraws=(0.25*gross_salary)+10.0;
        if(num_dependents>=3)
            withdraws+=35.0;


        cout<<'\t'<<"Total withdraws: " <<setw(12)<<'$'<<fixed<<setprecision(2)<<withdraws<<endl;
        cout<<'\t';
        printline(39,'-');
        cout<<'\t'<<"Gross salary: "<<setw(15)<<'$'<<fixed<<setprecision(2)<<gross_salary<<endl;
        cout<<'\t'<<"Net salary: "<<setw(17)<<'$'<<fixed<<setprecision(2)<<gross_salary-withdraws<<endl;
        printline(47,'=');
        cout<<endl;
    }
    /************************************************************************************************************/





    cout<<"Do you want to try again? (y/n)"<<endl;
    char c;
    cin>>c;
    if(c=='y')
        goto retry;                           //returns to the very first line of main
    else
        return 0;








    return 0;
}
