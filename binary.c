
#include <stdio.h>
#include <math.h>

int opcount=0;

int main(){
    int n,i,j,key;
    printf("enter the elements: ");
    scanf("%d",&n);
    int a[n];
    printf("enter the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the element to be searched: ");
    scanf("%d",&key);
    int low=0,high=n-1,mid;
    do{
        mid=floor((low+high)/2);
        if(key<a[mid]){
            high=mid-1;
        }
        else if(key>a[mid]){
            low=mid+1;
        }
    }while(key!=a[mid] && low<=high);

    if(key==a[mid]){
        printf("element found at position %d",mid+1);
    }
    else{
        printf("element not found");
    }
}
