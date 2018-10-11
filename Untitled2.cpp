#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int m,n,num=0;
	ifstream test("matrix.data");
	test >> m >> n;
	int A[3*n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			test >> A[n*(i%3)+j];
			int z=n*(i%3)+j
			while(i==1){
				if(A[z-n]>=A[z-n+1] && (z-n)%n==0 && A[z-n]>=A[z])
				else if (A[z-n]>=A[z-n-1] && (z-n)%n==n-1 && A[z-n]>=A[z])
				else (A[z-n]>=A[z-n+1] && A[z-n]>=A[z-n-1] && A[z-n]>=A[z])
			}
			while(i>1){
				if(i%3==0){
					if(A[z+2*n]>=A[z+2*n+1] && (z+2*n)%n==0)
					else if(A[z+2*n]>=A[z+2*n-1] && (z+2*n)%n==n-1)
					else if(A[z+2*n]>=A[z+2*n-1] && A[z+2*n]>=A[z+2*n+1])
				}
				else {
					if(A[z-n]>=A[z-n+1] && (z-n)%n==0)
					else if((z-n)%n==n-1 &&¡@A[z-n]>=A[z-n-1])
					else if(A[z-n]>=A[z-n+1] &&¡@A[z-n]>=A[z-n-1])
					
				}
			}
		}
	
	} 
	
	
