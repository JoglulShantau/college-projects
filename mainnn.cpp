#include<iostream>
#include<math.h>
using namespace std;
// trying to get  gcd
int gcd(int a, int b) 
{
  int t;
  while(1)
  {
    t= a % b;
    if(t==0)
      return b;
    a = b;
    b= t;
  }
}

int main() 
{
  //8 prime numbers that are more than 1,000,000 ,Choose 2 of these one is 1000033 another one is 1000037
  double p = 1000033;
  double q = 1000037;
  double n = p * q;//calculate n
  double track;
  double phi = (p-1)*(q-1);//calculating phi
   //users public key
   //e is for  for encrypt
   //Select a small odd integer e
  double e = 3;
   //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
  while(e < phi) {
    track = gcd(e,phi);
    if(track==1)
      break;
    else
      e++;
   }
   
  //private key
  //d stands for decrypt
  //choosing d such that it satisfies d*e = 1 mod phi
  double d1=1/e;
  double d=fmod(d1,phi);
  double message = 1000;
  double c = pow(message,e); //encrypt the message
  double m = pow(c,d);
  c = fmod(c,n);
  m = fmod(m,n);
  cout<< "Original Message = " << message << "\n";
  cout << "p = "<< p << "\n" ;
  cout << "q = " << q << "\n" ;
  cout << "n = pq = "<< n << "\n";
  cout << "phi = "<< phi << "\n";
  cout <<"e = "<< e << "\n";
  cout << "d = "<< d << "\n";
  cout << "Encrypted message = " << c << "\n";
  cout << "Decrypted message = " << m;
  return 0;
}