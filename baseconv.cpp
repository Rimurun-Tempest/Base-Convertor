/*Doesn't work when alphabets kick in :P*/

#include<iostream>
using namespace std;

long long num_to_dec(long long num,long long base);
long long log(long long num,long long base,const long long ans=-1);
long long bin_pow(long long base,long long exponent);
long long dec_to_base(long long num,long long n_b);

int main(){
    long long old_base,new_base,num,temp;
    cout<<"Input Number and Base"<<endl;
    cin>>num>>old_base;    

    temp=num_to_dec(num,old_base);
    if(temp==-1){
        cout<<"Error: Inconsistent Base";
        return 0;
    }        
    cout<<"Input Base to convert to"<<endl;
    cin>>new_base;

    cout<<"Output"<<endl;            
    cout<<dec_to_base(temp,new_base);
}
long long num_to_dec(long long num,long long base){
    long long iterator,i=0,rem,dec_num=0;

    iterator=log(num,base);
    if(base==10)
        return num;
    if(iterator==-1)
        return -1;
    while(i<=iterator){
        rem=num%10;
        if(rem>=base)
            return -1;
        dec_num+=rem*bin_pow(base,i++);
        num=(num-rem)/10;
    }
    return dec_num;
}
long long dec_to_base(long long num,long long base){
    long long iterator,i=0,rem,res=0;   

    iterator=log(num,base);

    while(i<=iterator){
        rem=num%base;

        if(rem>base)
            return -1;
        num/=base;
        
        res+=rem*bin_pow(10,i++);
    }
    return res;
}
long long bin_pow(long long base,long long exponent){
    long long ans;    
    if(exponent==0)
        return 1;

    ans=bin_pow(base,exponent/2);
    if(exponent%2)
        return ans*ans*base;   
    else
        return ans*ans;    
}
long long log(long long num,long long base,const long long ans){
    if(base<=0||num<0||base==1)
        return -1;
    if(num==0)
        return ans;
    else
		return log(num/base,base,ans+1);   
}
