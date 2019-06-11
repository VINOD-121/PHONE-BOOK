#include <iostream.h>//basic input and output services
#include <fstream.h>//acess the file
#include <string.h>//macro definations
#include <iomanip.h>
#include <conio.h>

class phoneBook{
    char name[20],phno[15];
    public:
    void getdata();//input function
    void showdata();//display function
char *getname(){ return name; }
    char *getphno(){ return phno; }
    void update(char *nm,char *telno){
	strcpy(name,nm);
	strcpy(phno,telno);
    }
};

void phoneBook :: getdata(){
    cout<<"\nEnter Name : ";
    cin>>name;
    cout<<"Enter Phone No. : ";
    cin>>phno;
}

void phoneBook :: showdata(){
    cout<<"\n";
    cout<<setw(20)<<name;
    cout<<setw(15)<<phno;
}   void main(){
    clrscr();
    int u,p;
    cout<<"\t\t\tenter the username:"<<endl;
    cout<<"\t\t\t";
cin>>u;
    cout<<"\n\n";
    cout<<"\t\t\tenter the password:"<<endl;
    cout<<"\t\t\t";
    cin>>p;
    if(u==12345 && p==12345)
    {
    phoneBook rec;
    fstream file;//helps to read or write a file
    file.open("phone.txt", ios::ate | ios::in | ios::out | ios::binary);

/*ate=add data at the end of the file,in=to input operations,out=to output operations,to open in binary mode*/

    char ch,nm[20],telno[6];
    int choice,found=0;
    while(1){
	clrscr();
	cout<<"\n*****Phone Book*****\n";
	cout<<"1) Add New Record\n";
	cout<<"2) Display All Records\n";
	cout<<"3) Search Telephone No.\n";
	cout<<"4) Search Person Name\n";
	cout<<"5) Update Telephone No.\n";
cout<<"6) Exit\n";
	cout<<"Choose your choice : ";
	cin>>choice;
	switch(choice){
	    case 1 : //New Record
		 rec.getdata();
		 cin.get(ch);
		 file.write((char *) &rec, sizeof(rec));
		 break;

	    case 2 : //Display All Records
		 file.seekg(0,ios::beg);/*helps to find the function location of the key word*/
		 cout<<"\n\nRecords in Phone Book\n";
		 while(file){
		    file.read((char *) &rec, sizeof(rec));/*reading the file data*/
		    if(!file.eof())//if it is not end of file
			rec.showdata();
		 }
		 file.clear();//clears the dat ainside the text file

		 getch();
		 break;
	    case 3 : //Search Tel. no. when person name is known.
 cout<<"\n\nEnter Name : ";
		 cin>>nm;
		 file.seekg(0,ios::beg);
		 found=0;
		 while(file.read((char *) &rec, sizeof(rec)))
		 {
		    if(strcmp(nm,rec.getname())==0)
/*comparing the entered name and the names in the text file*/
		    {
			found=1;
			rec.showdata();
		    }
		 }
		 file.clear();
		 if(found==0)
		    cout<<"\n\n---Record Not found---\n";
		 getch();
		 break;

	    case 4 : //Search name on basis of tel. no
		 cout<<"\n\nEnter Telephone No : ";
		 cin>>telno;
		 file.seekg(0,ios::beg);
		 found=0;
 while(file.read((char *) &rec, sizeof(rec)))

		 {
		    if(strcmp(telno,rec.getphno())==0)
/*comparing the entered phone no and the numbers  in the text file*/
		    {
			found=1;
			rec.showdata();
		    }
		 }
		 file.clear();
		 if(found==0)
		    cout<<"\n\n---Record Not found---\n";
		 getch();
		 break;

	    case 5 : //Update Telephone No.
		 cout<<"\n\nEnter Name : ";
		 cin>>nm;
		 file.seekg(0,ios::beg);
		 found=0;
		 int cnt=0;
		 while(file.read((char *) &rec, sizeof(rec)))
 {
		    cnt++;
		    if(strcmp(nm,rec.getname())==0)
		    {
			found=1;	 }
		 break;
	    case 6 : goto out;
	}
    }
out:
file.close();
}
else
{
cout<<"\t\tusername and password missatch!!"<<endl<<"\t\t\ttry angain";
getch();
}                   
}

			break;
		    }
		 }
		 file.clear();
		 if(found==0)
		    cout<<"\n\n---Record Not found---\n";
		 else
		 {
		    int location = (cnt-1) * sizeof(rec);
		    cin.get(ch);
		    if(file.eof())
			file.clear();

		    cout<<"Enter New Telephone No : ";
		    cin>>telno;
		    file.seekp(location);
		    rec.update(nm,telno);
		    file.write((char *) &rec, sizeof(rec));
		    file.flush();
