#include <iostream>
using namespace std;
int mat[10][6];
float wt=0,tat=0;
void swap(int* a, int* b)
{
int temp = *a;
*a = *b;
*b = temp;
}

void arrangeArrival(int num, int mat[][6])
{
for (int i = 0; i < num; i++) {
for (int j = 0; j < num - i - 1; j++) {
if (mat[j][1] > mat[j + 1][1]) {
for (int k = 0; k < 5; k++) {
swap(mat[j][k], mat[j + 1][k]);
}
}
}
}
}

void completionTime(int num, int mat[][6])
{
int temp, val, m=0;
int va = mat [0][2];
for(int i=1; i<num; i++){
if( mat[0][1] == mat[i][1] && va > mat[i][2] ){
va = mat[i][2];
m = i;

}
}
if (m!=0){
for(int k=0;k<3;k++){
 swap( mat[m][k], mat[0][k] );
}
}
mat[0][3] = mat[0][1] + mat[0][2];
mat[0][5] = mat[0][3] - mat[0][1];
mat[0][4] = mat[0][5] - mat[0][2];

for (int i = 1; i < num; i++) {
temp = mat[i - 1][3];
int low = mat[i][2];
for (int j = i; j < num; j++) {
if (temp >= mat[j][1] && low >= mat[j][2]) {
low = mat[j][2];
val = j;
}
}
mat[val][3] = temp + mat[val][2];
mat[val][5] = mat[val][3] - mat[val][1];
mat[val][4] = mat[val][5] - mat[val][2];
for (int k = 0; k < 6; k++) {
swap(mat[val][k], mat[i][k]);
}
}
}

int main()
{
int num, temp;

cout << "Enter number of Process: ";
cin >> num;
cout << "\n";
for (int i = 0; i < num; i++) {
cout << "Enter Process Id: ";
cin >> mat[i][0];
cout << "Enter Arrival Time: ";
cin >> mat[i][1];
cout << "Enter Burst Time: ";
cin >> mat[i][2];
cout << "\n";
}
cout << "\n";
cout << "Before Arrange...\n";
cout << "Process ID\tArrival Time\tBurst Time\n";
for (int i = 0; i < num; i++) {
cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
<< mat[i][2] << "\n";
}

arrangeArrival(num, mat);
completionTime(num, mat);
cout << "\n";
cout << "Final Result...\n";
cout << "Process ID " << " Arrival Time " << " Burst Time"
<< " Completion Time "<< " Turnaround Time "
<< " Waiting Time \n";
for (int i = 0; i < num; i++) {
cout << " " << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
<< mat[i][2] << "\t\t" << mat[i][3] << "\t\t"
<< mat[i][5] << "\t\t" << mat[i][4] << endl;
}
for (int i = 0; i < num; i++){
wt=wt+mat[i][4];
}
cout << "\nAverage Waiting Time: ";
cout << wt/num;
for (int i = 0; i < num; i++){
tat=tat+mat[i][5];
}
cout << "\nAverage Turn Around Time: ";
cout << tat/num;
}



