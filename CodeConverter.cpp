///bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dl double
#define st string
#define ch char
#define cn(n) cin>>n
#define cll(n) long long n; cin>>n
#define cdl(n) double n; cin>>n
#define cch(c) char c; cin>>c
#define cst(s) string s; cin>>s
#define ct(n) cout<<n
#define w(n) while(n>0)
#define elif else if
#define wh(n) long long n; cin>>n; while(n--)
#define a(m, n) long long a[n]; for(int i=m; i<n; i++) cin>>a[i]
#define b(m, n) long long b[n]; for(int i=m; i<=n; i++) b[i]=0
#define f(m, i, n) for(int i=m; i<n; i++)
#define fr(m, i, n) for(int i=m-1; i>=n; i--)
#define pb push_back
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define bye cout<<endl

st from, to;
bool valid=true;

int to_bcd_xs3(st number) {
    ll temp, k = 0;
    ll decimal[500];
    f(0, i, number.size()) {
        temp = number[i] - '0';
        if (to == "xs3") temp += 3;
        fr(4, j, 0) {
            if (temp >= pow(2, j)) {
                temp -= pow(2, j);
                decimal[k++] = 1;
            } else {
                decimal[k++] = 0;
            }
        }
    }
    f(0, i, k) ct(decimal[i]);
}


int from_bcd_xs3(st number)
{
    ll decimal[500], k=0;
    f(0, i, number.size()){
        ll temp=0, l=4;
        f(i, j, i+4){
            l--;
            if(number[j]=='1') temp+=pow(2, l);;
        }
        i+=3;
        if(from=="xs3") temp-=3;
        if(temp<10) decimal[k++]=temp;
        else{
            ct("Invalid.");
            return 0;
        }
    }
    ct("Ans: ");
    f(0, i, k) ct(decimal[i]);
}

int to_gray(st number)
{
    ll k=0, l=0, copy_number[500], temporary;
    if(from=="dec"){
        ll decimal=0, power=0;
        stringstream temp(number);
        temp>>decimal;
        f(0, i, 500){
            if(decimal<=pow(2, i)){
               power=i;
               break;
            }
        }
        fr(power+1, i, 0){
            if(decimal>=pow(2, i)){
                decimal-=pow(2, i);
                copy_number[k++]=1;
            }
            else copy_number[k++]=0;
        }
    }
    if(from=="bin"){
        f(0, i, number.size()) copy_number[k++]=number[i]-'0';
    }
    if(copy_number[0]==1) ct(1);
    f(0, i, k-1){
        temporary=copy_number[i]^copy_number[i+1];
        ct(temporary);
    }
}

int from_gray(st number)
{
    ll temp, decimal=0;
    ll binary[500];
    binary[0]=number[0]-'0';
    f(1, i, number.size()){
        temp=(number[i]-'0')^binary[i-1];
        binary[i]=temp;
    }
    if(to=="bin") f(0, i, number.size()) ct(binary[i]);
    if(to=="dec"){
        f(0, i, number.size()){
            decimal+=binary[i]*pow(2, number.size()-(i+1));
        }
        cout<<decimal;
    }
}

int main()
{
    ct("This program can convert:"<<endl);
    ct("\t- ascii value to character"<<endl);
    ct("\t- character to ascii value"<<endl);
    ct("\t- decimal to BCD"<<endl);
    ct("\t- BCD to decimal"<<endl);
    ct("\t- decimal to XS3"<<endl);
    ct("\t- XS3 to decimal"<<endl);
    ct("\t- decimal to gray"<<endl);
    ct("\t- gray code to decimal"<<endl);
    ct("\t- binary to gray code"<<endl);
    ct("\t- gray code to binary");
    bye;
    ct("(Only for integer numbers)");
    bye, bye;
    ct("# Use"<<endl);
    ct("   - char for character,"<<endl);
    ct("   - asc for ascii,"<<endl);
    ct("   - dec for decimal,"<<endl);
    ct("   - bin for binary,"<<endl);
    ct("   - bcd for BCD,"<<endl);
    ct("   - xs3 for XS3"<<endl);
    ct("   - gray for gray code.");
    bye, bye;
    ll t=0;
    w(1){
        t++;
        valid=true;
        ct("Case-"<<t);
        bye;
        ct("From: ");
        cn(from);
        if(from=="char" || from=="asc" || from=="dec" ||  from=="bin" || from=="bcd" || from=="xs3" || from=="gray"){
            ct("To: ");
            cn(to);
            if(from=="char" && to=="asc"){
                ct("Enter character: ");
                cch(character);
                ct("Ans: ");
                ct((ll)character);
            }
            elif(from=="asc" && to=="char"){
                ct("Enter ascii value: ");
                cll(ascii_value);
                ct("Ans: ");
                if(ascii_value>=0 && ascii_value<=127) ct((ch)ascii_value);
                else ct("Invalid.");
            }
            elif(from=="dec" && (to=="bcd" || to=="xs3")){
                ct("Enter number: ");
                cst(number);
                ct("Ans: ");
                to_bcd_xs3(number);
            }
            elif((from=="bcd" || from=="xs3") && to=="dec"){
                ct("Enter number: ");
                cst(number);
                from_bcd_xs3(number);
            }
            elif((from=="dec" || from=="bin") && to=="gray"){
                ct("Enter number: ");
                cst(number);
                ct("Ans: ");
                to_gray(number);
            }
            elif(from=="gray" && (to=="dec" || to=="bin")){
                ct("Enter number: ");
                cst(number);
                ct("Ans: ");
                from_gray(number);
            }
            else ct("Invalid.");
        }
        else ct("Invalid.");
        bye, bye;
    }
}
