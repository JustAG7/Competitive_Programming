#include<stdio.h>
#include<math.h>
using namespace std;


int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int soLon = -100000, dem = 0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		soLon = fmax(soLon, a[i]);
	}
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
		if(soLon == a[i]) dem++;
	}
	printf("\n%d\n%d",soLon,dem);
}