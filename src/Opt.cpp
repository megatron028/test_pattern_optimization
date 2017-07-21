//============================================================================
// Name        : Opt.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

enum MethodN { GoldsechN=0, GenN, SumpN };

// Иерархия
class Method_opt
{
  public:
    virtual int info() = 0;
    virtual ~Method_opt() {}
    // Параметризированный статический фабричный метод
    static Method_opt* User_Method( MethodN id );
};

class Goldsech: public Method_opt
{
  public:
    int info() {
    	return 1;
    }
};

class Gen: public Method_opt
{
  public:
    int info() {
      return 2;
    }
};

class Sump: public Method_opt
{
  public:
    int info() {
    	return 3;
    }
};


// Реализация параметризированного фабричного метода
Method_opt* Method_opt::User_Method( MethodN id ){
   Method_opt* p;
    switch (id)
    {
        case GoldsechN:
            p = new Goldsech();
            break;
        case GenN:
            p = new Gen();
            break;
        case SumpN:
            p = new Sump();
            break;
        default:
            assert( false);
    }
    return p;
};


int main() {

	vector<Method_opt*> v;

	v.push_back( Method_opt::User_Method( GoldsechN));
	v.push_back( Method_opt::User_Method( GenN));
	v.push_back( Method_opt::User_Method( SumpN));

	for(int i=0; i<v.size(); i++){
		switch (v[i]->info()){
		    case 3:
		    	cout << "Golden section" << endl;
		    	break;
		    case 2:
		    	cout << "Genetic method" << endl;
		    	break;
		    case 1:
		    	cout << "Simplex" << endl;
		    	break;
		    default:
		    	cout << "Unknown method";
		}
	}
}
