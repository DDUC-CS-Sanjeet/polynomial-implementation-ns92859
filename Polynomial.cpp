/*
  	By : Neeraj Sharma
   	Roll no. : 19HCS4037
   	Description : A program to perform operator overloading on Polynomials class
*/
#include<iostream>
using namespace std;

class Polynomial
{
  private:
  	int sze;
  	int* arr;
    // Variables to store information about polynomial
  public:
    Polynomial()
    {
    	//arr=new int [5];
      // Behavior of default constructor
    }

    Polynomial(int deg)
    {
    	sze=deg;
    	arr=new int[sze+1];
      // Behavior of constructor with arguments
    }
  
    ~Polynomial()
    {
    	//cout<<"\nProgram has ended.........\n";
      // Behavior of destructor
    }
  	Polynomial(const Polynomial &cpy)
  	{
  		sze=cpy.sze;
		 arr=new int[sze+1];
		 for(int i=sze;i>=0;i--)
		 {
		 	arr[i]=cpy.arr[i];
		  } 	
	}
    //  Overload copy constructor, +, - and = operators
  
    void storePolynomial()
    {
    
    	for(int i=sze;i>=0;i--)
    	{
    		cout<<"Enter the Coeffienct of your Polynomial's x ^ "<<i<<" : ";
    		cin>>arr[i];
    		//cout<<"\n";
		}
      //  Code to enter and store polynomial
    }
    void display()
    {
    	for(int i=sze;i>=1;i--)
    	{
    		cout<<arr[i]<<"x^("<<i<<") + ";
		}
		cout<<arr[0];
      //  Code to print the polynomial in readable format
    }
    Polynomial operator +(Polynomial ob2)
    {
    	int i,j;
    	Polynomial temp;
    	if(sze>ob2.sze)
    	{
    		temp.sze=sze;
    		temp.arr=new int[temp.sze+1];
    		for(i=sze,j=ob2.sze;i,j>=0;)
			{
				if(i!=j)
				{
					temp.arr[i]=arr[i];
					i--;
				}
				else
				{
					temp.arr[i]=arr[i]+ob2.arr[j];
					i--;
					j--;
				}
			}
		}
		else
		{
			temp.sze=ob2.sze;
			temp.arr=new int[temp.sze+1];
			for(i=ob2.sze,j=sze;i,j>=0;)
			{
				if(i!=j)
				{
					temp.arr[i]=ob2.arr[i];
					i--;
				}
				else
				{
					temp.arr[i]=ob2.arr[i]+arr[j];
					i--;
					j--;
				}
			}
		}
		return temp;
	}
  
  Polynomial operator -(Polynomial ob2)
    {
    	int i,j;
    	Polynomial temp;
    	if(sze>ob2.sze)
    	{
    		temp.sze=sze;
    		temp.arr=new int[temp.sze];
    		for(i=sze,j=ob2.sze;i,j>=0;)
			{
				if(i!=j)
				{
					temp.arr[i]=arr[i];
					i--;
				}
				else
				{
					temp.arr[i]=arr[i]-ob2.arr[j];
					i--;
					j--;
				}
			}
		}
		else
		{
			temp.sze=ob2.sze;
			temp.arr=new int[temp.sze];
			for(i=ob2.sze,j=sze;i,j>=0;)
			{
				if(i!=j)
				{
					temp.arr[i]=ob2.arr[i];
					i--;
				}
				else
				{
					temp.arr[i]=arr[j]-ob2.arr[i];
					i--;
					j--;
				}
			}
		}
		return temp;
	}
	void operator =(Polynomial cpy)
	{
		sze=cpy.sze;
		arr=new int[sze+1];
		for(int i=cpy.sze;i>=0;i--)
		{
			arr[i]=cpy.arr[i];
		}
	} 
};

int main()
{
  int degFirst, degSecond;
  cout<<"Enter the Highest power of your First Polynomial : ";
  cin>>degFirst;
  cout<<"Enter the Highest power of your Second Polynomial : ";
  cin>>degSecond;
  // Ask user to input the values of degFirst and degSecond 
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  
  Polynomial thirdPolynomial;
  
  cout<<"\nFor the First Polynomial : \n\n";
  firstPolynomial.storePolynomial();
  cout<<"\n\nFor the Second Polynomial : \n\n";
  secondPolynomial.storePolynomial();
  cout<<"\n\nFirst Polynomial is : \n";
  firstPolynomial.display();
  cout<<"\n\nSecond Polynomial is : \n";
  secondPolynomial.display();
  cout<<"\n\n\nAfter adding above two Polynomials : \n\n";
  thirdPolynomial=firstPolynomial+secondPolynomial;
  thirdPolynomial.display();
  
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  cout<<"\n\n\nAfter Subtracting your entered polynomials : \n\n";
  fourthPolynomial.display();
  /* 
  
  
  firstPolynomial.display();
  secondPolynomial.display();
  thirdPolynomial.display();
  fourthPolynomial.display(); */
  return 0;
}
