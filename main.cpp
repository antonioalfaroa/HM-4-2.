#include <iostream>
#include <iomanip>

using namespace std;

class Polynomial{
private: 
int expo[100];
int coef[100];

public:
Polynomial(){
for ( int i=0;i<100;i++) {
    coef[i] = 0;
    expo[i] = 0;
  }
}
Polynomial operator+(const Polynomial& x)const{
Polynomial pol;
bool existEx;
int i;
pol.coef[0] = coef[0] + x.coef[0];
for(i=1;(i<100)&&(x.expo[i] != 0);i++){
pol.coef[i] = x.coef[i];
pol.expo[i] = x.expo[i];
}
for(int j=1;j<100;j++){
existEx = false;
for(int t=1;(t<100)&&(!existEx);t++)
if(expo[j] == pol.expo[t]){
pol.coef[t] += coef[j];
existEx = true;
}
if(!existEx){
pol.expo[i] = expo[j];
pol.coef[i] += coef[j];
i++;
    }
  }
return pol;
}

Polynomial operator-( const Polynomial& d) const{
Polynomial temp;
bool exponentExists;
temp.coef[0] = coef[0] - d.coef[0];
  int i;
for (i=1;(i<100)&&(expo[i]!= 0); i++){
temp.coef[i] = coef[i];
temp.expo[i] = expo[i];
}
for ( int x = 1; x < 100; x++) {
exponentExists = false;
for ( int t = 1; ( t < 100 ) && ( !exponentExists ); ++t )
if ( d.expo[ x ] == temp.expo[ t ] ) {
temp.coef[ t ] -= d.coef[ x ];
exponentExists = true;
}
if ( !exponentExists ) {
temp.expo[i] = d.expo[ x ];
temp.coef[i] -= d.coef[ x ];
i++;
}
}
return temp;
}

Polynomial operator=(const Polynomial& x){
expo[0] = x.expo[0];
coef[0] = x.coef[0];
for(int i= 1; (i<100);i++){
if(x.expo[i] != 0){

  coef[i] = x.coef[i];
  expo[i] = x.expo[i];
}else{
if(expo[i] == 0 )
  break;
  expo[i] = 0;
  coef[i] = 0;
    }
  }
return *this;
}


void printPolynomial( void ) const{
  {
int start;
bool ze = false;
if (coef[0]){
cout<<coef[0];
ze = true;
start = 1;

}else{
if (coef[1]){
cout<<coef[1]<<"x";
if ((expo[1] != 0)&&(expo[1] != 1))
cout<<"^"<<expo[1];
ze = true;
}
  start = 2;
}
for(int x=start;x<100;x++){
if(coef[x] != 0){
cout<<setiosflags(ios::showpos)<<coef[x]<<resetiosflags(ios::showpos)<<"x";
if((expo[x] != 0)&&(expo[x] != 1))
cout<<"^"<<expo[x];

ze = true;
}
}
if(!ze)
cout<<"0";
cout<<endl;
}
  }
void enterTerms( void ){
bool found = false;
int numTerm;
  int a,b;
cout << "\nEnter number of polynomial terms: ";
cin >> numTerm;
for ( int n = 1; n <= numTerm; ++n ) {
cout << "\nEnter coefficient: ";
cin >> a;
cout << "Enter exponent: ";
cin >> b;
if ( a != 0 ) {
if ( b == 0 ) {
coef[0] += a;
continue;
}
  int term;
for(term=1;(term<100)&&(coef[term]!= 0);term++)
if(b==expo[term]){
coef[term] += a;
expo[term] = b;
found = true;
}
if(!found){
coef[term]+=a;
expo[term]=b;
      }
    }
  }
}







};

int main()
{
Polynomial inta, intb, result, newres;
inta.enterTerms();
intb.enterTerms();
result = inta;
cout << "First polynomial: "<<endl;
inta.printPolynomial();
cout << "Second polynomial:"<<endl;
intb.printPolynomial();
cout << "Adding the polynomials: "<<endl;
newres = inta + intb;
result.printPolynomial();

cout << "Subtracting the polynomials yields : "<<endl;
inta = result;
newres = inta - intb;
newres.printPolynomial();

return 0;
  }
