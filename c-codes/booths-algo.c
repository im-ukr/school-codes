#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int acc[4]={0};
void right_shift(int a[],int q[],int*q_1)
{
  int i;
  *q_1=q[3];
  for(i=2;i>=0;i--)
  q[i+1]=q[i];

  q[0]=a[3];
  for(i=2;i>=0;i--)
  a[i+1]=a[i];
}
void swap(int a[],int b[])
{
  int i,temp;
  for(i=0;i<4;i++)
  {
    temp=a[i];
    a[i]=b[i];
    b[i]=temp;
  }
}

void add(int a[],int b[])
{
  int carry[4];
  int i;
  for(i=3;i>=0;i--)
  {
    if(i==3)
    {
    carry[i]=a[i]&b[i];
    a[i]=a[i]^b[i];
    }
    else
    {

      carry[i]=(a[i]&carry[i+1])||(b[i]&carry[i+1])||(a[i]&b[i]);
      a[i]=a[i]^b[i]^carry[i+1];
    }
  }
}
void twoscomp(int a[],int n)
{
    int i;
  for(i=0;i<n;i++)
  {
    if(a[i]==1)
      a[i]=0;
    else
      a[i]=1;
  }
  int r;
  for(i=n-1;i>0;i--)
  {
    if(i==n-1)
    {
      r=a[i]&1;
      a[i]=a[i]^1;
      continue;
    }
    if(r==1)  
    {
      int t=a[i]&r;
      a[i]=a[i]^r;
      r=t;
    }
  }
}
void print(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("%d",a[i]);
  }
}
int main()
{
    int n1,n2,i,j;
    printf("\nEnter the multiplicand: ");
    scanf("%d",&n1);
    printf("\nEnter the multiplier: ");
    scanf("%d",&n2);
    int a=n1,b=n2;

    int n1b[4],n2b[4],n1c[4],n2c[4];

    for(i=4;i>=1;i--)
    {
        n1c[i-1]=n1b[i-1]=abs(a%2);
        a=a/2;
    }

      for(j=4;j>=1;j--)
      {
        n2c[j-1]=n2b[j-1]=abs(b%2);
        b=b/2;
      }
    twoscomp(n1c,4);
    printf("\nCompliments of +ve nos:");
    print(n1c,4);
    if(n1<0)
    swap(n1b,n1c);

    twoscomp(n2c,4);
    printf("\nCompliments of +ve nos:");
    print(n2c,4);
    if(n2<0)
    swap(n2b,n2c);

    printf("\nIn binary:\n");
    printf("\nn1:");
    print(n1b,4);
    printf("\n");
    printf("\nn2:");
    print(n2b,4);

    printf("\n\n");
    int c,t=0;
    printf("\n A    Q   Q(-1) count\n");
    for(c=4;c>=1;c--)
    {
      if(c==4){
      print(acc,4);
      printf(" ");
      print(n2b,4);
      printf("   ");
      printf("%d    %d\n",t,c);
      }
      if(n2b[3]==1&&t==0)
      {
      add(acc,n1c);
      printf("\n");
      print(acc,4);
      printf(" ");
      print(n2b,4);
      printf("   ");
      printf("%d    %d\n",t,c);
      }
      else if(n2b[3]==0&&t==1)
      {
      add(acc,n1b);
      printf("\n");
      print(acc,4);
      printf(" ");
      print(n2b,4);
      printf("   ");
      printf("%d    %d\n",t,c);
      }
      right_shift(acc,n2b,&t);
      printf("\n");
      print(acc,4);
      printf(" ");
      print(n2b,4);
      printf("   ");
      printf("%d    %d\n",t,c);
    }
    printf("\n");
    int fin[8];
    for(i=8,j=0;i>0;i--,j++)
    {
      if(j<4)
      fin[i-1]=n2b[3-j];
      else fin[i-1]=acc[3-j+4];
    }
    print(fin,8);
    if((n1<0&&n2>0)||(n1>0&&n2<0))
    {
    twoscomp(fin,8);
    printf("\n");
    print(fin,8);
    }
    int sum=0;
    for(i=0;i<8;i++)
    {
      sum=sum+fin[7-i]*pow(2,i);
    }
    printf("\nEquivalent positive answer:%d",sum);
    if((n1<0&&n2>0)||(n1>0&&n2<0))
    sum=-sum;
    printf("\nFinal answer:%d",sum);
    return 0;
}
