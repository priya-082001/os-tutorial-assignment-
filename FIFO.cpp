#include<iostream>
using namespace std;
int main(){
int reference_string[100],page_faults=0,m,n,s,pages,frames;
cout<<"Enter the number of pages : ";
cin>>pages;
cout<<"\nEnter the reference string values : \n";
for(m=0;m<pages;m++){
	cout<<"Value no.["<<m+1<<"]: \t";
	cin>>reference_string[m];
}	
cout<<"\nEnter the total number of frames : ";
cin>>frames;
int temp[frames];
for(m=0;m<frames;m++){
	temp[m]=-1;
}
for(m=0;m<pages;m++){
	s=0;
	for(n=0;n<frames;n++){
		if(reference_string[m]==temp[n]){
			s++;
			page_faults--;
		}
	}
	page_faults++;
	if((page_faults<=frames)&&(s==0)){
		temp[m]=reference_string[m];
	}
	else if(s==0){
		temp[(page_faults-1)%frames]=reference_string[m];
	}
	cout<<"\n";
	for(n=0;n<frames;n++){
		cout<<temp[n]<<"\t";
	}
}
int hits=(pages-page_faults);
int mr=((page_faults*1.0)/pages)*100;
int hr=((hits*1.0)/pages)*100;
cout<<"\n\nTotal page faults : "<<page_faults<<"\n";
cout<<"Total Hits : "<<hits<<"\n";
cout<<"Miss Ratio : "<<mr<<"%\n";
cout<<"Hits Ratio : "<<hr<<"%\n";
return 0;
}
