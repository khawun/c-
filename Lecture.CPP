 /* 1-)design class
                                        2-)write dedinition member outer class
                                        3-)practice in main program
                                            A)create list n object
                                                1)initailite an Array or pointer
                                            B)output with condition
                                            C)sort seerch Update*/
#include<conio.h>
#include<string.h>
#include<iostream>
#include<iomanip>
#include<cmath>
  using namespace std;
  class Lecture{
    private: int id;char name[25];float hour;float salary;
    public: void input();
            void output();
           // Lecture(){id=1;strcpy(name,"aaa");hour=1;salary=9}
            Lecture(int id=0,char *name="hhh",float hour=0.0,float salary=0.0);
            Lecture(const Lecture &other);
            //~Lecture();
            float getsalary();
            int getid();
            static void header();
            static void Menu();
            friend void Sort(Lecture st[100],int n);

  };
  //write definition___________________________________________________________________________
  Lecture::Lecture(int id,char *name,float hour,float salary){
    this->id=id;
    strcpy(this->name,name);
    this->hour=hour;
    this->salary=salary;
  }
  Lecture::Lecture(const Lecture &other){
        id=other.id;
        strcpy(name,other.name);
        hour=other.hour;
        salary=other.salary;
  }
  //Lecture::~Lecture(){}
  void Lecture::input(){
    cout<<"Enter value ID    = ";cin>>id;
    cout<<"Enter value Nmae  = ";cin.sync();cin.get(name,25);
    cout<<"Enter value hour  = ";cin>>hour;
    cout<<"Enter value salary= ";cin>>salary;cout<<endl;
  }
  void Lecture::output(){
    cout<<"\t"<<id<<"\t"<<name<<"\t"<<hour<<"\t"<<salary<<endl;
  }
  void Lecture::header(){
  cout<<"\tID\tNmae\thour\tSalary"<<endl;
  }
  void Lecture::Menu(){
    cout<<"option 1 Sort_______________________________"<<endl;
    cout<<"option 2 Seerch_____________________________"<<endl;
    cout<<"option 3 Update_____________________________"<<endl;
  }
  float Lecture::getsalary(){
    return (salary);
  }
  int Lecture::getid(){
    return (id);
  }
  void Sort(Lecture st[100],int n){
      Lecture as;
      int i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
          if(st[i].salary>st[j].salary){
                as=st[i];
                st[i]=st[j];
                st[j]=as;
          }
        for(i=0;i<n;i++){
            st[i].output();
        }
          cout<<endl;
  }
  //________________________________________________________________________________________
  int main(){
      int i,n,option,seerch_id,update,j;
        Lecture tmp;
      Lecture st[4]={Lecture(01,"vandara",12,200),Lecture(02,"sadet",12,320),Lecture(03,"davy",12,240),Lecture(04,"khaw",12,50)};
      for(i=0;i<4;i++){
            st[i].output();
      }
      cout<<endl;
      int num=4;
      Sort(st,num);
      getch();
      Lecture *ptr;
      cout<<"Enter n object= ";cin>>n;
      ptr=new Lecture[n];
      for(i=0;i<n;i++){
        ptr[i].input();
      }
      cout<<endl;
  getch();
  //output data from sreenc
  Lecture::header();cout<<endl;
  for(i=0;i<n;i++){
    ptr[i].output();
  }
  //switch__________________________________________________________________________________
  do{
        Lecture::Menu();
    cout<<"option =";cin>>option;cout<<endl;
    switch(option){
        case 1:
            for(i=0;i<n;i++)
                for(j=i+1;j<n;j++)
                    if(ptr[i].getsalary()>ptr[j].getsalary()){
                        tmp=ptr[i];
                        ptr[i]=ptr[j];
                        ptr[j]=tmp;
                    }
                getch;
                for(i=0;i<n;i++){
                    ptr[i].output();
                }
                cout<<endl;
        break;
        case 2:
            cout<<"seerch ID = ";cin>>seerch_id;
            for(i=0;i<n;i++){
                if(ptr[i].getid()==seerch_id){
                    int b=0;
                    ptr[i].output();
                }
            }
            if(int b=1){
                cout<<"not defind or not found!";
            }
        break;
        case 3:
            cout<<"update in id = ";cin>>update;
            for(i=0;i<n;i++){
                if(ptr[i].getid()==update){
                    int b=0;
                    ptr[i].input();
                    for(i=0;i<n;i++)
                        ptr[i].output();
                }

            }
            if(int b=1){
                cout<<"not found!";
            }
        break;
        case 4:
            cout<<"exite programe";
        break;
    }

  }while(option!=4);
  return 0;

  }
