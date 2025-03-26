 #include<stdio.h>
void minmax(int a[10],int l,int r,int *max,int *min){
    int mid;
    if(l==r){
        *max=*min=a[l];
    }
    else{
        if(l==(r-1)){
            if(a[l]>a[r]){
                *max=a[l];
                *min=a[r];
            }
            else{
                *max=a[r];
                *min=a[l];
            }
        }
        else{
            mid=(l+r)/2;
            int max1=0,min1=0;
            minmax(a,l,mid-1,&max1,&min1);
            minmax(a,mid,r,&max1,&min1);
            if(*max<max1){
                *max=max1;
            }
            if(*min>min1){
                *min=min1;
            }
        }
    }
}
    int main(){
      int n,a[10],min,max;
      printf("Enter number of elements:");
      scanf("%d",&n);
      printf("Enter array elements:");
      for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
      }
      max=a[0];
      min=a[0];
      minmax(a,0,n-1,&max,&min);
      printf("maximum element in the array:%d\n",max);
      printf("minimum element in the array:%d\n",min);
      return 0;
    }

