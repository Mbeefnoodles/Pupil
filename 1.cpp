#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

int left_char(char ch)
{
	if (ch=='+')
		return 3;
	if (ch=='-')
		return 3;
	if (ch=='*')
		return 5;
	if (ch=='/')
		return 5;
	if (ch=='(')
		return 1;
	if (ch==')')
		return 6;
	if (ch=='#')
		return 0;
}
int right_char(char ch)
{
	if (ch=='+')
		return 2;
	if (ch=='-')
		return 2;
	if (ch=='*')
		return 4;
	if (ch=='/')
		return 4;
	if (ch=='(')
		return 6;
	if (ch==')')
		return 1;
	if (ch=='#')
		return 0;
}
double simplecaculate(double a,double b,char ch)
{
	if(ch=='+')
		return a+b;
	else if(ch=='-')
		return b-a;
	else if(ch=='*')
		return a*b;
	else if(ch=='/')
		return b/a;
}
int main()
{
	char ch,temp;
	double a,b,mark=1,_decimal=10.0;
	ch=' ';
	stack<char>optr;
	stack<double>opnd;
	optr.push('#');
	while(ch!='#')
	{
		temp=ch;
		cin>>ch;
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
			continue;
		if((ch>='0'&&ch<='9')||ch=='.'){
									if(ch>='0'&&ch<='9'&&mark!=0){
										opnd.push(ch-48);
										if(temp>='0'&&temp<='9')
									{ 
					
											a=opnd.top();
											opnd.pop();
											b=opnd.top();
											opnd.pop();
											opnd.push(b*10+a);
									}
									}
									if(ch=='.')
									{
										mark=0;
									}
									if(mark==0&&ch>='0'&&ch<='9')
									{
										a=opnd.top();
										opnd.pop();
										opnd.push(a+(ch-48)/_decimal);
										_decimal=_decimal*10;

						
									}
			
		

		}else{
			     _decimal=10;
				 mark=1;
				if(right_char(ch)>left_char(optr.top()))
							{
								optr.push(ch);
							}
				 else if(right_char(ch)==left_char(optr.top()))
							{
								optr.pop();
							}
				else if(right_char(ch)<left_char(optr.top()))
							{ 
								while(right_char(ch)<left_char(optr.top())){
									if(optr.top()=='('||optr.top()==')'||optr.top()=='#')
									{
										break;
									}else{
										if(opnd.empty()){
											//cout<<"error3";
											break;
										}
										else{
											a=opnd.top();
											opnd.pop();
										}
										if(opnd.empty()){
											//cout<<"error2";
											break;
										}else{
											b=opnd.top();
											opnd.pop();
											if(a==0&&optr.top()=='/')
												break;
											else{
											opnd.push(simplecaculate(a,b,optr.top()));
											//cout<<opnd.top();
											optr.pop();
											}
										}
									}
									//cout<<optr.top();
								}
									if(right_char(ch)==left_char(optr.top()))
										optr.pop();
									else if(right_char(ch)>left_char(optr.top())){
									optr.push(ch);
									}
						}
				}
			
	}

	if(optr.empty())
	{
		cout<<opnd.top();
	}else
	{
		cout<<"error";
	}

	system("pause");
	return 0;
}
 